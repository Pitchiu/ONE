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

#ifndef __LUCI_IR_CIRCLEGELU_H__
#define __LUCI_IR_CIRCLEGELU_H__

#include "luci/IR/CircleNodeDecl.h"
#include "luci/IR/CircleOpcode.h"

#include "luci/IR/CircleNodeMixins.h"

namespace luci
{

/**
 * @brief GELU in Circle
 */
class CircleGelu final : public FixedArityNode<1, CircleNodeImpl<CircleOpcode::GELU>>
{
public:
  loco::Node *features(void) const { return at(0)->node(); }
  void features(loco::Node *node) { at(0)->node(node); }

public:
  bool approximate(void) const { return _approximate; }
  void approximate(bool arg) { _approximate = arg; }

private:
  bool _approximate{false};
};

} // namespace luci

#endif // __LUCI_IR_CIRCLEGELU_H__
