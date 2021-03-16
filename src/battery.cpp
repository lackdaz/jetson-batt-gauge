/* Copyright (C) 2021 Seth Loh
 *
 * This software may be modified and distributed under the terms
 * of the MIT license.  See the LICENSE.mit file for details.
 */

#include "battery.hpp"

void print_i2c_data(const unsigned char* data, size_t len) {
  for (size_t i = 0; i < len; i++) {
    if (i % 16 == 0) {
      fprintf(stdout, "\n");
    }
    fprintf(stdout, "%02x ", data[i]);
  }
  fprintf(stdout, "\n");
}

// void hello_world() {
//   DEBUG << "hello world";
// }