/* Copyright (C) 2021 Seth Loh
 *
 * This software may be modified and distributed under the terms
 * of the MIT license.  See the LICENSE.mit file for details.
 */
#include "bitwise.hpp"
#include "iostream"

namespace {
  int16_t compute_twos_complement(size_t udec, uint8_t bits);
}

namespace bitwise {
  int8_t bin8(uint8_t a) { return compute_twos_complement(a, sizeof(a)); };
  int16_t bin16(uint16_t a) { return compute_twos_complement(a, sizeof(a)); };
}  // namespace bitwise

namespace {
  int16_t compute_twos_complement(size_t udec, uint8_t byte) {
    uint8_t bits = byte * 8;
    return (udec & (1 << (bits - 1))) ? udec -= 1 << bits : udec;
  }
}  // namespace