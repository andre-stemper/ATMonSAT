/*
 Copyright 2022 University of Luxembourg

 Licensed under the Apache License, Version 2.0 (the "License");
 you may not use this file except in compliance with the License.
 You may obtain a copy of the License at

      https://www.apache.org/licenses/LICENSE-2.0

 Unless required by applicable law or agreed to in writing, software
 distributed under the License is distributed on an "AS IS" BASIS,
 WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
 See the License for the specific language governing permissions and
 limitations under the License.
 */

/**
 * @author André Stemper (andre.stemper@uni.lu)
 */
 
#ifndef __ATMONSAT_PROTOCOL_H_
#define __ATMONSAT_PROTOCOL_H_

#include "atmonsat.h"
#include "datapoint.h"
#include "matrix.h"

#include "protocol_definitions.h"
#include "protocol_datalink.h"

namespace atmonsat
{

    class GenericProtocolResponse
    {
    protected:
        uint8_t _cmd = 0x00;

    private:
        DataLink *_data_link;

    public:
        GenericProtocolResponse(uint8_t cmd, DataLink *data_link) : _cmd(cmd), _data_link(data_link) {}
        ipr_t send_byte(uint8_t byte)
        {
            uint8_t status = PROTOCOL_STATUS_NAK;
            do
            {
                _data_link->output(byte);
                _data_link->input(&status, true);
            } while (status != PROTOCOL_STATUS_ACK);
            return PROTOCOL_DONE;
        };

        void send_ack() { _data_link->output(PROTOCOL_STATUS_ACK); }
        void send_nak() { _data_link->output(PROTOCOL_STATUS_NAK); }
        void send_rply() { _data_link->output(PROTOCOL_STATUS_RPLY); }
        void send_erp() { send_byte(static_cast<uint8_t>(PROTOCOL_COMMAND_ID_ERP)); }
    };

    template <typename T>
    class VirtualProtocolResponse : public GenericProtocolResponse
    {

    public:
        VirtualProtocolResponse(uint8_t cmd, DataLink *data_link) : GenericProtocolResponse(cmd, data_link) {}
        virtual ipr_t send(T value) = 0;
    };

    template <typename T>
    class ProtocolResponseValue : public VirtualProtocolResponse<T>
    {
    private:
        uint8_t _buffer[sizeof(T)];

    public:
        ProtocolResponseValue(uint8_t cmd, DataLink *data_link) : VirtualProtocolResponse<T>(cmd, data_link){};

        ipr_t send(T value) override
        {
            if (this->send_byte(this->_cmd) != PROTOCOL_DONE)
            {
                return PROTOCOL_ERROR;
            }
            return send_value(value);
        }

        ipr_t send_value(T value)
        {
            convert(value);
            for (unsigned int i = 0; i < sizeof(T); ++i)
            {
                if (this->send_byte(_buffer[i]) != PROTOCOL_DONE)
                {
                    return PROTOCOL_ERROR;
                }
            }
            return PROTOCOL_DONE;
        }
        /**
         * @brief convert a 8bit signed integer into buffer
         *
         * @param value
         */
        void convert(int8_t value)
        {
            _buffer[0] = static_cast<uint8_t>(value);
        }

        /**
         * @brief convert a 8bit unsigned integer into buffer
         *
         * @return uint8_t
         */
        void convert(uint8_t value)
        {
            _buffer[0] = value;
        }

        /**
         * @brief convert buffer to a 32bit unsigned integer
         *
         * @return uint32_t
         */
        void convert(uint32_t value)
        {
            _buffer[0] = (value)&0xFF;
            _buffer[1] = (value >> 8) & 0xFF;
            _buffer[2] = (value >> 16) & 0xFF;
            _buffer[3] = (value >> 24) & 0xFF;
        }

        /**
         * @brief convert buffer to a 32bit integer
         *
         * @return int32_t
         */
        void convert(int32_t value)
        {
            uint32_t _value = static_cast<uint32_t>(value);
            _buffer[0] = (_value)&0xFF;
            _buffer[1] = (_value >> 8) & 0xFF;
            _buffer[2] = (_value >> 16) & 0xFF;
            _buffer[3] = (_value >> 24) & 0xFF;
        }

        /**
         * @brief convert buffer to a 32bit float
         *
         * @return float
         */
        void convert(float value)
        {
            /* little endian */
            _buffer[0] = *((uint8_t *)(&value) + 0);
            _buffer[1] = *((uint8_t *)(&value) + 1);
            _buffer[2] = *((uint8_t *)(&value) + 2);
            _buffer[3] = *((uint8_t *)(&value) + 3);
        }
    };

#ifdef PROTOCOL_RESPONSE_COMMENT_SUPPORT_VARIADIC
#include <stdarg.h>
#endif

    class ProtocolResponseComment : public GenericProtocolResponse
    {
    public:
        ProtocolResponseComment(uint8_t cmd, DataLink *data_link) : GenericProtocolResponse(cmd, data_link){};

#ifdef PROTOCOL_RESPONSE_COMMENT_SUPPORT_VARIADIC
        ipr_t send(const char *format, ...)
        {
            char buffer[PROTOCOL_RESPONSE_COMMENT_FORMAT_BUFFER];
            va_list args;
            va_start(args, format);
            vsnprintf(buffer, PROTOCOL_RESPONSE_COMMENT_FORMAT_BUFFER, format, args);
            if (this->send_byte(this->_cmd) != PROTOCOL_DONE)
            {
                return PROTOCOL_ERROR;
            }
            return send_szstring(const_cast<const char*>(buffer));
            va_end(args);
        }
#else
        ipr_t send(const char *str)
        {
            if (this->send_byte(this->_cmd) != PROTOCOL_DONE)
            {
                return PROTOCOL_ERROR;
            }
            return send_szstring(str);
        }
#endif

        ipr_t send_szstring(const char *str)
        {
            while (*str)
            {
                if (this->send_byte(*str++) != PROTOCOL_DONE)
                {
                    this->send_byte(0x00); /* terminate string */
                    return PROTOCOL_ERROR;
                }
            }
            this->send_byte(0x00); /* terminate string */
            return PROTOCOL_DONE;
        }
    };

    /**
     * @brief Forward declaration
     *
     */
    class VirtualProtocolHandler;

    /**
     * @brief Protocol handler callback
     *
     */
    typedef ipr_t (*ProtocolHandlerCallback)(VirtualProtocolHandler *handler);

    /**
     * @brief a virtual protocol handler
     *
     */
    class VirtualProtocolHandler
    {
    private:
        ProtocolHandlerCallback _callback;

    public:
        VirtualProtocolHandler(ProtocolHandlerCallback callback = nullptr) : _callback(callback){};
        virtual ipr_t incoming(const uint8_t character) = 0;
        virtual void reset() = 0;
        virtual bool requires_arguments() = 0;
        virtual void *data() = 0;

        /**
         * @brief
         *
         * @return ipr_t
         */
        ipr_t callback()
        {
            if (_callback == nullptr)
            {
                /* no callback means: all handled apart from the status byte */
                return PROTOCOL_DONE;
            }
            return _callback(this);
        }

        /**
         * @brief begin reception
         *        a cmd has just been received for this handler.
         *
         * @return PROTOCOL_MORE if this expects more bytes to follow
         * @return PROTOCOL_DONE if this is an argumentless command
         * @return PROTOCOL_ALREADY_ACKNOWLEDGED if the callback already handled the status byte
         * @return PROTOCOL_ERROR something bad happend
         *
         */
        ipr_t begin_reception()
        {
            reset();
            if (!requires_arguments())
            {
                /* this is a command without arguments */
                return callback();
            }
            return PROTOCOL_MORE;
        }
    };

    /**
     * @brief protocol handler float
     *
     * @tparam RC
     * @tparam CC
     * @tparam T
     */
    template <typename T>
    class ProtocolHandlerValue : public VirtualProtocolHandler
    {
    private:
        T *_value;
        unsigned int _index;
        uint8_t _buffer[sizeof(T)];

    public:
        ProtocolHandlerValue(T *value, ProtocolHandlerCallback callback = nullptr) : VirtualProtocolHandler(callback), _value(value), _index(0)
        {
            reset();
        }

        /**
         * @brief Does this command require arguments
         *
         * @return true
         * @return false
         */
        bool requires_arguments()
        {
            return true;
        }

        /**
         * @brief pointer to data
         *
         * @return void*
         */
        void *data()
        {
            return static_cast<void *>(_value);
        }

        /**
         * @brief Set the target variable
         *
         * @param value
         */
        void set_target_variable(T *value)
        {
            _value = value;
        }

        /**
         * @brief reset protocol_handler
         *
         */
        void reset()
        {
            *_value = 0;
            _index = 0;
        }

        /**
         * @brief collect consecutive incoming characters into buffer until
         *        there are enough for a conversion
         *
         * @param character incoming character
         * @return ipr_t
         */
        ipr_t incoming(const uint8_t character) override
        {
            if (_index >= sizeof(T))
            {
                return PROTOCOL_ERROR;
            }
            _buffer[_index] = character;
            _index++;
            if (_index == sizeof(T))
            {
                convert(_value);
                return PROTOCOL_DONE;
            }
            return PROTOCOL_MORE;
        }

        /**
         * @brief convert buffer to a 8bit integer
         *
         * @return int8_t
         */
        void convert(int8_t *value)
        {
            *value = static_cast<int8_t>(_buffer[0]);
        }

        /**
         * @brief convert buffer to a 8bit unsigned integer
         *
         * @return uint8_t
         */
        void convert(uint8_t *value)
        {
            *value = _buffer[0];
        }

        /**
         * @brief convert buffer to a 32bit unsigned integer
         *
         * @return uint32_t
         */
        void convert(uint32_t *value)
        {
            *value = _buffer[0] + (_buffer[1] << 8) + (_buffer[2] << 16) + (_buffer[3] << 24);
        }

        /**
         * @brief convert buffer to a 32bit integer
         *
         * @return int32_t
         */
        void convert(int32_t *value)
        {
            *value = static_cast<int32_t>(_buffer[0] + (_buffer[1] << 8) + (_buffer[2] << 16) + (_buffer[3] << 24));
        }

        /**
         * @brief convert buffer to a 32bit float
         *
         * @return float
         */
        void convert(float *value)
        {
            float f;
            /* little endian */
            *((uint8_t *)(&f) + 0) = _buffer[0];
            *((uint8_t *)(&f) + 1) = _buffer[1];
            *((uint8_t *)(&f) + 2) = _buffer[2];
            *((uint8_t *)(&f) + 3) = _buffer[3];
            *value = f;
        }
    };

    /**
     * @brief protocol handler specialized on datapoints
     *
     * @tparam RC
     * @tparam CC
     * @tparam T
     */
    template <typename T = float, unsigned int N = 9>
    class ProtocolHandlerDatapoint : public VirtualProtocolHandler
    {
    private:
        t_datapoint<T, N> *_datapoint;                   /*! pointer to datapoint to store value in */
        unsigned int _ci;                                /*! column index */
        T _value;                                        /*! temporary value */
        ProtocolHandlerValue<T> _value_protocol_handler; /*! value protocol_handler */

    public:
        /**
         * @brief Construct a new protocol handler
         *
         * @param matrix
         */
        ProtocolHandlerDatapoint(t_datapoint<T, N> *datapoint, ProtocolHandlerCallback callback = nullptr) : VirtualProtocolHandler(callback), _datapoint(datapoint), _value_protocol_handler(&_value)
        {
            reset();
        }

        /**
         * @brief Does this command require arguments
         *
         * @return true
         * @return false
         */
        bool requires_arguments()
        {
            return true;
        }

        /**
         * @brief reset protocol_handler
         *
         */
        void reset()
        {
            _ci = 0; /*! reset column index to 0 */
        }

        /**
         * @brief pointer to datapoint
         *
         * @return void*
         */
        void *data()
        {
            return static_cast<void *>(_datapoint);
        }

        /**
         * @brief advance index to the next field
         *
         */
        ipr_t _advance_index(void)
        {
            assert(_ci < _datapoint->size); /* assert column index smaller then column count */
            _ci++;                          /* increase column index */
            if (_ci == _datapoint->size)    /* end of column reached: done */
            {
                _ci = 0; /* start row at column 0 */
                reset(); /* reset indicies to field 0,0 */
                return PROTOCOL_DONE;
            }
            assert(_ci < _datapoint->size);
            return PROTOCOL_MORE;
        }

        /**
         * @brief handle incoming character
         *
         * @param character
         * @return ipr_t
         */
        ipr_t incoming(const uint8_t character) override
        {
            ipr_t result = _value_protocol_handler.incoming(character);
            if (result == PROTOCOL_MORE)
            {
                return PROTOCOL_MORE;
            }
            if (result == PROTOCOL_ERROR)
            {
                reset();
                return PROTOCOL_ERROR;
            }
            /* a value is ready */
            _datapoint->set(_ci, _value);    /* store value in datapoint at position _ci */
            _value_protocol_handler.reset(); /* reset value protocol_handler to accept the next characters */
            return _advance_index();         /* advance to the next field */
        }
    };

    /**
     * @brief protocol specialized on comment requests
     *
     */
    class ProtocolHandlerRequestComment : public VirtualProtocolHandler
    {
    public:
        /**
         * @brief Construct a new protocol object
         *
         * @param callback
         */
        ProtocolHandlerRequestComment(ProtocolHandlerCallback callback = nullptr) : VirtualProtocolHandler(callback) {}

        /**
         * @brief Does this command require arguments
         *
         * @return false
         */
        bool requires_arguments()
        {
            return false;
        }

        /**
         * @brief reset
         *
         */
        void reset() {}

        /**
         * @brief pointer to data
         *
         * @return void*
         */
        void *data() { return (nullptr); }

        /**
         * @brief handle incoming character
         *
         * @param character
         * @return ipr_t
         */
        ipr_t incoming(const uint8_t character) override
        {
            return PROTOCOL_ERROR;
        }
    };

    /**
     * @brief protocol specialized on initialization requests
     *
     */
    class ProtocolHandlerInitialize : public VirtualProtocolHandler
    {
    public:
        /**
         * @brief Construct a new protocol object
         *
         * @param callback
         */
        ProtocolHandlerInitialize(ProtocolHandlerCallback callback = nullptr) : VirtualProtocolHandler(callback) {}

        /**
         * @brief Does this command require arguments
         *
         * @return false
         */
        bool requires_arguments()
        {
            return false;
        }

        /**
         * @brief reset
         *
         */
        void reset() {}

        /**
         * @brief pointer to data
         *
         * @return void*
         */
        void *data() { return (nullptr); }

        /**
         * @brief handle incoming character
         *
         * @param character
         * @return ipr_t
         */
        ipr_t incoming(const uint8_t character) override
        {
            return PROTOCOL_ERROR;
        }
    };

    /**
     * @brief protocol handler specialized on matrix / vector (1xn matrix)
     *
     * @tparam RC
     * @tparam CC
     * @tparam T
     */
    template <unsigned RC, unsigned CC, typename T = float>
    class ProtocolHandlerMatrix : public VirtualProtocolHandler
    {
    private:
        Matrix<RC, CC, T> *_matrix;                      /*! pointer to matrix to store value in */
        unsigned int _ci, _ri;                           /*! column and row indecies */
        T _value;                                        /*! temporary value */
        ProtocolHandlerValue<T> _value_protocol_handler; /*! value protocol_handler */

    public:
        /**
         * @brief Construct a new protocol handler
         *
         * @param matrix
         */
        ProtocolHandlerMatrix(Matrix<RC, CC, T> *matrix, ProtocolHandlerCallback callback = nullptr) : VirtualProtocolHandler(callback), _matrix(matrix), _value_protocol_handler(&_value)
        {
            reset();
        }

        /**
         * @brief Does this command require arguments
         *
         * @return true
         * @return false
         */
        bool requires_arguments()
        {
            return true;
        }

        /**
         * @brief reset protocol_handler
         *
         */
        void reset()
        {
            _ri = 0; /*! reset row index to 0 */
            _ci = 0; /*! reset column index to 0 */
        }

        /**
         * @brief pointer to matrix
         *
         * @return void*
         */
        void *data()
        {
            return static_cast<void *>(_matrix);
        }

        /**
         * @brief advance indicies to the next field
         *
         */
        ipr_t _advance_indicies(void)
        {
            assert(_ci < CC); /* assert column index smaller then column count */
            assert(_ri < RC); /* assert row index smaller then row count */
            _ci++;            /* increase column index */
            if (_ci == CC)    /* end of column reached, change to next row  */
            {
                _ci = 0;           /* start row at column 0 */
                if ((++_ri) == RC) /* if this already was the last row the matrix is done */
                {
                    reset(); /* reset indicies to field 0,0 */
                    return PROTOCOL_DONE;
                }
            }
            assert(_ci < CC);
            assert(_ri < RC);
            return PROTOCOL_MORE;
        }

        /**
         * @brief handle incoming character
         *
         * @param character
         * @return ipr_t
         */
        ipr_t incoming(const uint8_t character) override
        {
            ipr_t result = _value_protocol_handler.incoming(character);
            if (result == PROTOCOL_MORE)
            {
                return PROTOCOL_MORE;
            }
            if (result == PROTOCOL_ERROR)
            {
                reset();
                return PROTOCOL_ERROR;
            }
            /* a value is ready */
            _matrix->set(_ri, _ci, _value);  /* write value to matrix */
            _value_protocol_handler.reset(); /* reset value protocol_handler to accept the next characters */
            return _advance_indicies();      /* advance to the next field */
        }
    };

    /**
     * @brief protocol. This code selects the protocol_handler for the following communication
     *        as long as !PROTOCOL_MORE
     *        Format:
     *              <uin8_t:trigger>, [uint8_t value]+, <uin8_t:trigger>, [uint8_t value]+, ...
     *
     * @tparam N number of protocol_handlers
     */
    class Protocol
    {
    private:
        unsigned int _number_of_handlers;
        VirtualProtocolHandler *_protocol_handler = nullptr; /*! currently active protocol_handler */
        uint8_t *_triggers;                                  /*! list of triggers characters to select the protocol_handler */
        VirtualProtocolHandler **_protocol_handlers;         /*! list of available protocol_handlers */
        DataLink *_data_link;

    public:
        /**
         * @brief Construct a new protocol object
         *
         * @param triggers list of trigger characters to select the next protocol_handler
         * @param protocol_handlers list of available protocol_handlers (same order as the triggers)
         */
        Protocol(uint8_t *triggers,
                 VirtualProtocolHandler **protocol_handlers,
                 unsigned int number_of_handlers,
                 DataLink *data_link) : _number_of_handlers(number_of_handlers),
                                        _triggers(triggers),
                                        _protocol_handlers(protocol_handlers),
                                        _data_link(data_link){};

        /**
         * @brief get one character from input handler and pass to incoming
         *
         * @return ipr_t
         */
        ipr_t handle()
        {
            uint8_t character = 0x00;
            ipr_t status = _data_link->input(&character, false);
            if (status == PROTOCOL_DONE)
            {
                return incoming(character);
            }
            return status;
        }

        /**
         * @brief handle one incoming character
         *
         * @param character
         * @return ipr_t
         */
        ipr_t incoming(const uint8_t character)
        {
            if (_protocol_handler == nullptr) /* no protocol_handler is active */
            {
                /* this is a cmd: search for protocol handler in list */
                for (unsigned int i = 0; i < _number_of_handlers; i++)
                {
                    if (_triggers[i] == character) /* trigger value matches */
                    {
                        _protocol_handler = _protocol_handlers[i]; /* make protocol_handler active */
                                                                   /* begin the reception with this protocol_handler */

                        ipr_t status = _protocol_handler->begin_reception();
                        if (status == PROTOCOL_DONE)
                        {
                            _protocol_handler = nullptr;             /* command without arguments */
                            _data_link->output(PROTOCOL_STATUS_ACK); /* acknowledge reception */
                            return PROTOCOL_DONE;
                        }
                        if (status == PROTOCOL_ALREADY_RESPONDED_ACK)
                        {
                            _protocol_handler = nullptr; /* command without arguments */
                            return PROTOCOL_DONE;
                        }
                        if (status == PROTOCOL_ERROR)
                        {
                            _protocol_handler = nullptr;
                            _data_link->output(PROTOCOL_STATUS_NAK);
                            return PROTOCOL_DONE;
                        }
                        _data_link->output(PROTOCOL_STATUS_ACK); /* acknowledge cmd reception */
                        return PROTOCOL_MORE;
                    }
                }

                /* unkown protocol_handler */
                _data_link->output(PROTOCOL_STATUS_CNS);
                return PROTOCOL_ERROR;
            }
            else
            {
                /* forward character to the currently selected protocol_handler */
                ipr_t result = _protocol_handler->incoming(character);
                if (result == PROTOCOL_DONE)
                {
                    result = _protocol_handler->callback();
                    _protocol_handler = nullptr; /* deactivate protocol_handler */

                    /* reply if the callback handler did not reply */
                    if (result != PROTOCOL_ALREADY_RESPONDED_ACK)
                    {
                        _data_link->output(PROTOCOL_STATUS_ACK);
                        return PROTOCOL_DONE;
                    }
                    return result;
                }
                if (result == PROTOCOL_ERROR) /* a problem occurred */
                {
                    _data_link->output(PROTOCOL_STATUS_NAK);
                    return PROTOCOL_ERROR;
                }
                _data_link->output(PROTOCOL_STATUS_ACK);
                return PROTOCOL_DONE;
            }
        };
    };

}

#endif
