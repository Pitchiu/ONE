/*
 * Copyright (c) 2020 Samsung Electronics Co., Ltd. All Rights Reserved
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

#include "luci/Import/Nodes/CircleSelect.h"

#include <luci/IR/Nodes/CircleSelect.h>

#include <loco.h>

namespace luci
{

bool CircleSelectGraphBuilder::validate(const ValidateArgs &args) const
{
  if (!GraphBuilder::validate(args, 3))
    return false;

  const auto &inputs = args.op.inputs;
  const auto tensors = args.reader.tensors();
  const auto tensor = tensors.at(inputs.at(0));
  assert(tensor != nullptr);
  if (tensor->type() != circle::TensorType_BOOL)
    return false;
  // TODO check dtypes for input 1, 2

  return true;
}

CircleNode *CircleSelectGraphBuilder::build_node(const circle::OperatorT &,
                                                 const std::vector<CircleNode *> &inputs,
                                                 loco::Graph *graph) const
{
  auto *node = graph->nodes()->create<CircleSelect>();
  node->condition(inputs.at(0));
  node->t(inputs.at(1));
  node->e(inputs.at(2));

  return node;
}

} // namespace luci
