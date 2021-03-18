/* Copyright (C) 2021 Seth Loh
 *
 * This software may be modified and distributed under the terms
 * of the MIT license.  See the LICENSE.mit file for details.
 */

#include "battery.hpp"

namespace battery {

/**
 * @brief
 *
 * @param data
 * @param len
 */
void print_i2c_data(const unsigned char* data, size_t len) {
  for (size_t i = 0; i < len; i++) {
    if (i % 16 == 0) {
      fprintf(stdout, "\n");
    }
    fprintf(stdout, "%02x ", data[i]);
  }
  fprintf(stdout, "\n");
}

/**
 * @brief
 *
 * @return std::string
 */
std::string hello_world() {
  DEBUG << "this is a debug";
  ERROR << "this is an error";
  INFO << "this is an info";
  WARNING << "this is a warning";

  return "hello world";
}

int add(int a, int b) {
  return a + b;
}

int multiply(int a, int b) {
  return a * b;
}
}  // namespace battery
