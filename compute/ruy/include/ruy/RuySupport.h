/*
 * Copyright (c) 2020 Samsung Electronics Co., Ltd. All Rights Reserved
 * Copyright 2017 The TensorFlow Authors. All Rights Reserved.
 *
 * Licensed under the Apache License, Version 2.0 (the "License");
 * you may not use this file except in compliance with the License.
 * You may obtain a copy of the License at
 *
 *      http://www.apache.org/licenses/LICENSE-2.0
 *
 * Unless required by applicable law or agreed to in writing, software
 * distributed under the License is distributed on an "AS IS" BASIS,
 * WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
 * See the License for the specific language governing permissions and
 * limitations under the License.
 */

#ifndef __NNFW_RUY_RUY_SUPPORT_H__
#define __NNFW_RUY_RUY_SUPPORT_H__

#include <util/ConfigSource.h>
#include <ruy/matrix.h>
#include <ruy/ruy.h>
#include <cassert>
#include "Types.h"

namespace nnfw
{
namespace ruy
{
namespace ruy_support
{

inline ::ruy::CachePolicy ToRuyCachePolicy(CachePolicy cache_policy)
{
  switch (cache_policy)
  {
    case CachePolicy::kNeverCache:
      return ::ruy::CachePolicy::kNeverCache;
    case CachePolicy::kCacheIfLargeSpeedup:
      return ::ruy::CachePolicy::kCacheIfLargeSpeedup;
    case CachePolicy::kAlwaysCache:
      return ::ruy::CachePolicy::kAlwaysCache;
    default:
      assert(false);
      return ::ruy::CachePolicy::kNeverCache;
  }
}

template <typename Scalar, typename DataPointer>
void MakeRuyMatrix(const MatrixParams<Scalar> &params, DataPointer data_ptr,
                   ::ruy::Matrix<Scalar> *dst, bool use_caching = false)
{
  ::ruy::Order ruy_order =
    params.order == Order::kColMajor ? ::ruy::Order::kColMajor : ::ruy::Order::kRowMajor;
  ::ruy::MakeSimpleLayout(params.rows, params.cols, ruy_order, dst->mutable_layout());
  // Note that ruy::Matrix::data is a ConstCheckingPtr, not a plain pointer.
  // It does care whether we assign to it a Scalar* or a const Scalar*.
  dst->set_data(data_ptr);
  dst->set_zero_point(params.zero_point);
  if (use_caching)
  {
    dst->set_cache_policy(ToRuyCachePolicy(params.cache_policy));
  }
}

// Floating-point case.
template <typename AccumScalar, typename DstScalar, QuantizationFlavor quantization_flavor>
void MakeRuyMulParams(const GemmParams<AccumScalar, DstScalar, quantization_flavor> &params,
                      ::ruy::MulParams<AccumScalar, DstScalar> *ruy_mul_params)
{
  static_assert(quantization_flavor == QuantizationFlavor::kFloatingPoint, "");
  ruy_mul_params->set_bias(params.bias);
  ruy_mul_params->set_clamp_min(params.clamp_min);
  ruy_mul_params->set_clamp_max(params.clamp_max);
}

// Integer-quantized case with destination type narrower than int32
template <typename DstScalar, QuantizationFlavor quantization_flavor>
void MakeRuyMulParams(const GemmParams<std::int32_t, DstScalar, quantization_flavor> &params,
                      ::ruy::MulParams<std::int32_t, DstScalar> *ruy_mul_params)
{
  static_assert(sizeof(DstScalar) < sizeof(std::int32_t), "");
  if (quantization_flavor == QuantizationFlavor::kIntegerWithUniformMultiplier)
  {
    ruy_mul_params->set_multiplier_fixedpoint(params.multiplier_fixedpoint);
    ruy_mul_params->set_multiplier_exponent(params.multiplier_exponent);
  }
  if (quantization_flavor == QuantizationFlavor::kIntegerWithPerRowMultiplier)
  {
    ruy_mul_params->set_multiplier_fixedpoint_perchannel(params.multiplier_fixedpoint_perchannel);
    ruy_mul_params->set_multiplier_exponent_perchannel(params.multiplier_exponent_perchannel);
  }
  ruy_mul_params->set_bias(params.bias);
  ruy_mul_params->set_clamp_min(params.clamp_min);
  ruy_mul_params->set_clamp_max(params.clamp_max);
}

// Raw-integer case with destination type int32.
template <QuantizationFlavor quantization_flavor>
void MakeRuyMulParams(const GemmParams<std::int32_t, std::int32_t, quantization_flavor> &params,
                      ::ruy::MulParams<std::int32_t, std::int32_t> *ruy_mul_params)
{
  ruy_mul_params->set_bias(params.bias);
}

} // namespace ruy_support
} // namespace ruy
} // namespace nnfw

#endif // __NNFW_RUY_RUY_SUPPORT_H__
