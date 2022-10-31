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
 
#ifndef __ATMONSAT_PROTOCOL_DEFINITIONS_H_
#define __ATMONSAT_PROTOCOL_DEFINITIONS_H_

/**
 * @brief Status responses
 *
 */
#define PROTOCOL_STATUS_ACK 0x30  /* acknowledge the reception of a byte */
#define PROTOCOL_STATUS_NAK 0x31  /* do not acknowledge the reception of a byte */
#define PROTOCOL_STATUS_RPLY 0x32 /* a reply object will be send next */
#define PROTOCOL_STATUS_CNS 0x33  /* command not supported */

/**
 * @brief Protocol commands
 *
 */
#define PROTOCOL_COMMAND_ID_GENERIC 0x00                               /* placeholder for a real command */
#define PROTOCOL_COMMAND_ID_ERP 0x01                                   /* end of reply */
#define PROTOCOL_COMMAND_ID_INITIALIZE 0x10                            /* initialize target */
#define PROTOCOL_COMMAND_ID_COMMENT 0x40                               /* start of comment */
#define PROTOCOL_COMMAND_ID_REQUEST_COMMENT 0x41                       /* request for comment */
#define PROTOCOL_COMMAND_ID_DATAPOINT_FLOAT 0x21                       /* datapoint */
#define PROTOCOL_COMMAND_ID_DATAPOINT_INT8 0x22                        /* datapoint */
#define PROTOCOL_COMMAND_ID_MAHALANOBIS_INVERSE_COVARIANCE_MATRIX 0x42 /* mahalanobis inverse of covariance matrix */
#define PROTOCOL_COMMAND_ID_MAHALANOBIS_MEAN 0x43                      /* mahalanobis mean */
#define PROTOCOL_COMMAND_ID_THRESHOLD 0x44                             /* threshold value */
#define PROTOCOL_COMMAND_ID_THRESHOLD_HOLD_OFF 0x45                    /* threshold hold-off value */
#define PROTOCOL_COMMAND_ID_3x3_MATRIX 0x60                            /* test */
#define PROTOCOL_COMMAND_ID_INT8 0x61                                  /* test */
#define PROTOCOL_COMMAND_ID_UINT8 0x62                                 /* test */
#define PROTOCOL_COMMAND_ID_FLOAT 0x63                                 /* test */
#define PROTOCOL_COMMAND_ID_INT32 0x64                                 /* test */
#define PROTOCOL_COMMAND_ID_UINT32 0x65                                /* test */
#define PROTOCOL_COMMAND_ID_EXECUTION_TIME 0x80                        /* measured execution time */
#define PROTOCOL_COMMAND_ID_DETECTION 0x82                             /* detection result */
#define PROTOCOL_COMMAND_ID_MAHALANOBIS_DISTANCE 0x83                  /* prediction distance */
#define PROTOCOL_COMMAND_ID_EXCEPTION 0xFE                             /* remote exception */
#define PROTOCOL_COMMAND_ID_EOC 0xFF                                   /* end of communication */

namespace atmonsat
{
    /**
     * @brief protocol call return type
     *
     */
    typedef enum
    {
        PROTOCOL_ERROR = 0x01,                 /* operation failed */
        PROTOCOL_MORE = 0x02,                  /* more information required to continue */
        PROTOCOL_DONE = 0x03,                  /* operation done and succeeded */
        PROTOCOL_TIMEOUT = 0x04,               /* timeout occurred during operation */
        PROTOCOL_ALREADY_RESPONDED_ACK = 0x83, /* a status has already been send */
        PROTOCOL_UNDEFINED = 0xFF              /* initializer */
    } ipr_t;

}

#endif
