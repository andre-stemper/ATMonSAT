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
 
#include "atmonsat_output_handler.h"

void atmonsat_handle_output(tflite::ErrorReporter *error_reporter,
                  float x_value,
                  float y_value)
{
    TF_LITE_REPORT_ERROR(error_reporter, "x_value: %f, y_value: %f
",
                         static_cast<double>(x_value),
                         static_cast<double>(y_value));
}
