#pragma once

#include <boost/cstdint.hpp>
#include <new>
#include <type_traits>
#include <stdlib.h>
#include <string>

#include "jetsonbatt_error.hpp"

namespace bitwise {
  int8_t compute_signed_twos_complement(int8_t udec);
}  // namespace bitwise
