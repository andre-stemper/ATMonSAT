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

#include <iostream>
#include <fstream>
#include <string>
#include <iterator>
#include <fcntl.h>
#include <cstdint>
#include <time.h>

#include "protocol_datalink_pipe.h"

using namespace atmonsat;
using namespace std;

/**
 * @brief Construct a new Std Data Link:: Std Data Link object
 *
 *
 */
ProtocolDatalinkPipe::ProtocolDatalinkPipe()
{
#ifdef PROTOCOL_DATALINK_PIPE_LOG_TO_FILE
    ofstream myfile;
    // empty files
    myfile.open(PROTOCOL_DATALINK_PIPE_STDIN_LOG_FILE, ios::out | ios::binary);
    myfile.close();
    myfile.open(PROTOCOL_DATALINK_PIPE_STDOUT_LOG_FILE, ios::out | ios::binary);
    myfile.close();
#endif

    _stdin = freopen(NULL, "rb", stdin);
    setvbuf(_stdin, NULL, _IONBF, 0);
    setbuf(stdin, NULL);
    set_fl(_stdin->_fileno, O_NONBLOCK);

    _stdout = freopen(NULL, "wb", stdout);
    setbuf(stdout, NULL);
    set_fl(_stdout->_fileno, O_NONBLOCK);

#ifdef PROTOCOL_DATALINK_PIPE_LOG_TO_FILE
    auto result = freopen(PROTOCOL_DATALINK_PIPE_STDERR_LOG_FILE, "w", stderr);
    (void)result; // ignore result
#endif
}

/**
 * @brief communication done ?
 *
 * @return true
 * @return false
 */
bool ProtocolDatalinkPipe::done() { return false; }

/**
 * @brief input: get one byte from pipe
 *
 * @param byte
 * @return ipr_t
 */
ipr_t ProtocolDatalinkPipe::input(uint8_t *byte, bool blocking)
{

    if (blocking)
    {
        /* blocking version */
        while (fread((char *)byte, 1, 1, _stdin) != 1)
        {
            /* free some time to the kernel */
            struct timespec remaining, request = {0, 10};
            nanosleep(&request, &remaining);
        }
    }
    else
    {
        /* non blocking version */
        if (fread((char *)byte, 1, 1, _stdin) == 1)
        {
            return PROTOCOL_DONE;
        }
        return PROTOCOL_TIMEOUT;
    }

#if 0
        do
        {
            std::cin.read((char *)(byte), 1);
// std::cin.read((char *)(byte), 1);
#ifdef ABORT_ON_EMPTY_INPUT_PIPE
            if (!std::cin.good())
            {
                std::cerr << "done." << std::endl;
                exit(1);
            }
#endif
        } while (!std::cin.good());

#endif

#ifdef PROTOCOL_DATALINK_PIPE_LOG_TO_FILE
    /* debug: log to file */
    ofstream myfile;
    myfile.open(PROTOCOL_DATALINK_PIPE_STDIN_LOG_FILE, ios::app | ios::out | ios::binary);
    myfile.write((const char *)byte, 1);
    myfile.close();
#endif
    return PROTOCOL_DONE;
}

/**
 * @brief output - emit one byte to pipe
 *
 * @param byte
 * @return ipr_t
 */
ipr_t ProtocolDatalinkPipe::output(uint8_t byte)
{

#ifdef PROTOCOL_DATALINK_PIPE_LOG_TO_FILE
    /* debug: log to file */
    ofstream myfile;
    myfile.open(PROTOCOL_DATALINK_PIPE_STDOUT_LOG_FILE, ios::app | ios::out | ios::binary);
    myfile.write((const char *)&byte, 1);
    myfile.close();
#endif

#if 0
        fwrite(&byte, 1, 1, _stdout);
        fflush(_stdout);
        std::cout.flush();
#endif

#if 1
    std::cout.write((char *)&byte, 1);
    std::cout.flush();
#endif
    return PROTOCOL_DONE;
}

/**
 * @brief set file status flag
 *
 * @param fd
 * @param flags
 */
void ProtocolDatalinkPipe::set_fl(int fd, int flags) /* flags are file status flags to turn on */
{
    int val;
    if ((val = fcntl(fd, F_GETFL, 0)) < 0)
        std::cerr << "fcntl F_GETFL error" << std::endl;
    val |= flags;
    if (fcntl(fd, F_SETFL, val) < 0)
        std::cerr << "fcntl F_SETFL error" << std::endl;
}

/**
 * @brief clear file status flag
 *
 * @param fd
 * @param flags
 */
void ProtocolDatalinkPipe::clr_fl(int fd, int flags) /* flags are file status flags to turn off */
{
    int val;
    if ((val = fcntl(fd, F_GETFL, 0)) < 0)
        std::cerr << "fcntl F_GETFL error" << std::endl;
    val &= ~flags;
    if (fcntl(fd, F_SETFL, val) < 0)
        std::cerr << "fcntl F_SETFL error" << std::endl;
}
