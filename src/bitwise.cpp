/* Copyright (C) 2021 Seth Loh
 *
 * This software may be modified and distributed under the terms
 * of the MIT license.  See the LICENSE.mit file for details.
 */
#include "bitwise.hpp"
#include "iostream"
#include "assert.h"

namespace {}

namespace bitwise {
  int8_t compute_signed_twos_complement(int8_t udec) {
    uint8_t bits = sizeof(udec) * 8;
    return (int8_t)(udec & (1 << (bits - 1))) ? udec -= 1 << bits : udec;
  };
}  // namespace bitwise

namespace {}  // namespace