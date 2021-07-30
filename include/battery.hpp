#include <string.h>
#include <unistd.h>
#include <boost/any.hpp>

#include "i2c/i2c.h"
#include "jetsonbatt_error.hpp"
#include "bitwise.hpp"

namespace {}  // namespace

namespace jetsonbatt {
  class battery {
   public:
    float min_current = 0.0;
    float max_current = 0.0;
    battery();
    ~battery();
    char query(uint8_t hex);
    void get_minmax_current();
  };
}  // namespace jetsonbatt
