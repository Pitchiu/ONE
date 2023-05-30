/*
 * Copyright (c) 2023 Samsung Electronics Co., Ltd. All Rights Reserved
 *
 * Licensed under the Apache License, Version 2.0 (the "License");
 * you may not use this file except in compliance with the License.
 * You may obtain a copy of the License at
 *
 *    http://www.apache.org/licenses/LICENSE-2.0
 *
 * Unless required by applicable law or agreed to in writing, software
 * distributed under the License is distributed on an "AS IS" BASIS,
 * WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
 * See the License for the specific language governing permissions and
 * limitations under the License.
 */

#ifndef LUCI_INTERPRETER_TEST_MODELS_LESS_KERNEL_QUANT_H
#define LUCI_INTERPRETER_TEST_MODELS_LESS_KERNEL_QUANT_H

#include "TestDataLessBase.h"

namespace luci_interpreter
{
namespace test_kernel
{
namespace less_uint8_with_no_broadcasting
{

/*
 * Less Kernel:
 *
 * Input_1(1, 4, 4, 3)   Input_2(1, 4, 4, 3)
 *       \             /
 *     Less(no broadcast)
 *              |
 *          Output(1, 4, 4, 3)
 */

const unsigned char test_kernel_model_circle[] = {
  0x1c, 0x00, 0x00, 0x00, 0x43, 0x49, 0x52, 0x30, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x0e, 0x00,
  0x14, 0x00, 0x00, 0x00, 0x0c, 0x00, 0x08, 0x00, 0x10, 0x00, 0x04, 0x00, 0x0e, 0x00, 0x00, 0x00,
  0x10, 0x00, 0x00, 0x00, 0x30, 0x00, 0x00, 0x00, 0x10, 0x02, 0x00, 0x00, 0x2c, 0x02, 0x00, 0x00,
  0x04, 0x00, 0x00, 0x00, 0x1c, 0x00, 0x00, 0x00, 0x14, 0x00, 0x00, 0x00, 0x0c, 0x00, 0x00, 0x00,
  0x04, 0x00, 0x00, 0x00, 0x88, 0xff, 0xff, 0xff, 0x8c, 0xff, 0xff, 0xff, 0x90, 0xff, 0xff, 0xff,
  0x94, 0xff, 0xff, 0xff, 0x01, 0x00, 0x00, 0x00, 0x14, 0x00, 0x00, 0x00, 0x00, 0x00, 0x0e, 0x00,
  0x18, 0x00, 0x14, 0x00, 0x10, 0x00, 0x0c, 0x00, 0x08, 0x00, 0x04, 0x00, 0x0e, 0x00, 0x00, 0x00,
  0x14, 0x00, 0x00, 0x00, 0x1c, 0x00, 0x00, 0x00, 0x60, 0x00, 0x00, 0x00, 0x64, 0x00, 0x00, 0x00,
  0x6c, 0x00, 0x00, 0x00, 0x04, 0x00, 0x00, 0x00, 0x6d, 0x61, 0x69, 0x6e, 0x00, 0x00, 0x00, 0x00,
  0x01, 0x00, 0x00, 0x00, 0x14, 0x00, 0x00, 0x00, 0x00, 0x00, 0x0e, 0x00, 0x14, 0x00, 0x00, 0x00,
  0x10, 0x00, 0x0c, 0x00, 0x07, 0x00, 0x08, 0x00, 0x0e, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x29,
  0x10, 0x00, 0x00, 0x00, 0x10, 0x00, 0x00, 0x00, 0x14, 0x00, 0x00, 0x00, 0x04, 0x00, 0x04, 0x00,
  0x04, 0x00, 0x00, 0x00, 0x01, 0x00, 0x00, 0x00, 0x02, 0x00, 0x00, 0x00, 0x02, 0x00, 0x00, 0x00,
  0x00, 0x00, 0x00, 0x00, 0x01, 0x00, 0x00, 0x00, 0x01, 0x00, 0x00, 0x00, 0x02, 0x00, 0x00, 0x00,
  0x02, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x01, 0x00, 0x00, 0x00, 0x03, 0x00, 0x00, 0x00,
  0xcc, 0x00, 0x00, 0x00, 0x44, 0x00, 0x00, 0x00, 0x10, 0x00, 0x00, 0x00, 0x0c, 0x00, 0x14, 0x00,
  0x10, 0x00, 0x0f, 0x00, 0x08, 0x00, 0x04, 0x00, 0x0c, 0x00, 0x00, 0x00, 0x10, 0x00, 0x00, 0x00,
  0x03, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x06, 0x0c, 0x00, 0x00, 0x00, 0x03, 0x00, 0x00, 0x00,
  0x6f, 0x66, 0x6d, 0x00, 0x04, 0x00, 0x00, 0x00, 0x01, 0x00, 0x00, 0x00, 0x04, 0x00, 0x00, 0x00,
  0x04, 0x00, 0x00, 0x00, 0x03, 0x00, 0x00, 0x00, 0x8a, 0xff, 0xff, 0xff, 0x14, 0x00, 0x00, 0x00,
  0x4c, 0x00, 0x00, 0x00, 0x02, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x03, 0x4c, 0x00, 0x00, 0x00,
  0x7c, 0xff, 0xff, 0xff, 0x30, 0x00, 0x00, 0x00, 0x24, 0x00, 0x00, 0x00, 0x18, 0x00, 0x00, 0x00,
  0x04, 0x00, 0x00, 0x00, 0x01, 0x00, 0x00, 0x00, 0x80, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
  0x00, 0x00, 0x00, 0x00, 0x01, 0x00, 0x00, 0x00, 0x81, 0x80, 0x00, 0x3c, 0x01, 0x00, 0x00, 0x00,
  0x00, 0x00, 0x80, 0x3f, 0x01, 0x00, 0x00, 0x00, 0x00, 0x00, 0x80, 0xbf, 0x04, 0x00, 0x00, 0x00,
  0x69, 0x66, 0x6d, 0x32, 0x00, 0x00, 0x00, 0x00, 0x04, 0x00, 0x00, 0x00, 0x01, 0x00, 0x00, 0x00,
  0x04, 0x00, 0x00, 0x00, 0x04, 0x00, 0x00, 0x00, 0x03, 0x00, 0x00, 0x00, 0x00, 0x00, 0x0e, 0x00,
  0x18, 0x00, 0x14, 0x00, 0x13, 0x00, 0x0c, 0x00, 0x08, 0x00, 0x04, 0x00, 0x0e, 0x00, 0x00, 0x00,
  0x20, 0x00, 0x00, 0x00, 0x54, 0x00, 0x00, 0x00, 0x01, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x03,
  0x54, 0x00, 0x00, 0x00, 0x0c, 0x00, 0x14, 0x00, 0x04, 0x00, 0x08, 0x00, 0x0c, 0x00, 0x10, 0x00,
  0x0c, 0x00, 0x00, 0x00, 0x2c, 0x00, 0x00, 0x00, 0x20, 0x00, 0x00, 0x00, 0x14, 0x00, 0x00, 0x00,
  0x04, 0x00, 0x00, 0x00, 0x01, 0x00, 0x00, 0x00, 0x80, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
  0x01, 0x00, 0x00, 0x00, 0x81, 0x80, 0x00, 0x3c, 0x01, 0x00, 0x00, 0x00, 0x00, 0x00, 0x80, 0x3f,
  0x01, 0x00, 0x00, 0x00, 0x00, 0x00, 0x80, 0xbf, 0x04, 0x00, 0x00, 0x00, 0x69, 0x66, 0x6d, 0x31,
  0x00, 0x00, 0x00, 0x00, 0x04, 0x00, 0x00, 0x00, 0x01, 0x00, 0x00, 0x00, 0x04, 0x00, 0x00, 0x00,
  0x04, 0x00, 0x00, 0x00, 0x03, 0x00, 0x00, 0x00, 0x01, 0x00, 0x00, 0x00, 0x10, 0x00, 0x00, 0x00,
  0x0c, 0x00, 0x0c, 0x00, 0x0b, 0x00, 0x00, 0x00, 0x00, 0x00, 0x04, 0x00, 0x0c, 0x00, 0x00, 0x00,
  0x3a, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x3a, 0x11, 0x00, 0x00, 0x00, 0x4f, 0x4e, 0x45, 0x2d,
  0x74, 0x66, 0x6c, 0x69, 0x74, 0x65, 0x32, 0x63, 0x69, 0x72, 0x63, 0x6c, 0x65, 0x00, 0x00, 0x00};

const std::vector<uint8_t> input1_data = {
  14,  5,   251, 243, 14,  243, 251, 5,   34, 252, 245, 252, 11, 250, 31, 14,
  5,   250, 21,  5,   24,  233, 5,   235, 23, 25,  15,  6,   22, 251, 23, 252,
  242, 5,   14,  21,  234, 242, 5,   253, 16, 244, 5,   13,  21, 5,   15, 252};

const std::vector<uint8_t> input2_data = {5,   2,   5,   14,  14,  24,  15,  5, 13, 4,   5,   251,
                                          241, 14,  253, 253, 5,   254, 245, 5, 13, 40,  253, 5,
                                          253, 235, 5,   5,   252, 252, 5,   5, 5,  5,   252, 253,
                                          252, 13,  251, 251, 7,   253, 13,  5, 5,  253, 5,   5};

const std::vector<bool> reference_output_data = {
  false, false, false, false, false, false, false, false, false, false, false, false,
  true,  false, true,  true,  false, true,  true,  false, false, false, true,  false,
  true,  true,  false, false, true,  true,  false, false, false, false, true,  true,
  true,  false, true,  false, false, true,  true,  false, false, true,  false, false};

} // namespace less_uint8_with_no_broadcasting

namespace neg_less_uint8_with_no_broadcasting
{

/*
 * Less Kernel with input type mismatch:
 *
 * Input_1(1, 4, 4, 3)   Input_2(1, 4, 4, 3)
 *       \             /
 *     Less(no broadcast)
 *              |
 *          Output(1, 4, 4, 3)
 */

const unsigned char test_kernel_model_circle[] = {};

const std::vector<uint8_t> input1_data = {};

const std::vector<uint8_t> input2_data = {};

const std::vector<bool> reference_output_data = {};

} // namespace neg_less_uint8_with_no_broadcasting

class TestDataQuantLess : public TestDataLessBase<uint8_t, bool>
{
public:
  explicit TestDataQuantLess(bool is_with_broadcast, bool is_neg)
    : TestDataLessBase<uint8_t, bool>(is_with_broadcast)
  {
    if (is_with_broadcast)
    {
      assert(false && "Not impl yet");
    }
    else
    {
      if (is_neg)
      {
        _input1_data = neg_less_uint8_with_no_broadcasting::input1_data;
        _input2_data = neg_less_uint8_with_no_broadcasting::input2_data;
        _reference_output_data = neg_less_uint8_with_no_broadcasting::reference_output_data;
        _test_kernel_model_circle = neg_less_uint8_with_no_broadcasting::test_kernel_model_circle;
      }
      else
      {
        _input1_data = less_uint8_with_no_broadcasting::input1_data;
        _input2_data = less_uint8_with_no_broadcasting::input2_data;
        _reference_output_data = less_uint8_with_no_broadcasting::reference_output_data;
        _test_kernel_model_circle = less_uint8_with_no_broadcasting::test_kernel_model_circle;
      }
    }
  }

  ~TestDataQuantLess() override = default;
};

} // namespace test_kernel
} // namespace luci_interpreter

#endif // LUCI_INTERPRETER_TEST_MODELS_LESS_KERNEL_QUANT_H
