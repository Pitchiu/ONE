/*
 * Copyright (c) 2022 Samsung Electronics Co., Ltd. All Rights Reserved
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

#include "Builders.h"

#include "kernels/Shape.h"

namespace luci_interpreter
{

std::unique_ptr<Kernel> build_kernel_CircleShape(const luci::CircleNode *circle_node,
                                                 KernelBuilderHelper &helper)
{
  const auto *node = loco::must_cast<const luci::CircleShape *>(circle_node);
  assert(node->arity() == 1);

  const auto input = helper.getInputTensor(node->input());
  auto output = helper.getOutputTensor(node);

  ShapeParams shape_params{};
  shape_params.out_type = node->out_type();

  return std::make_unique<kernels::ShapeKernel>(input, output, shape_params);
}

} // namespace luci_interpreter
