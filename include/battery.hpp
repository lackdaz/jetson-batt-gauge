#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <boost/any.hpp>
#include "i2c/i2c.h"
#include "jetsonbatt_error.hpp"

namespace jetsonbatt {
void print_i2c_data(const unsigned char* data, size_t len);
void hello_world();
}  // namespace jetsonbatt