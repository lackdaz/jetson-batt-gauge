#include "gtest/gtest.h"
#include "battery.hpp"
#include "jetsonbatt_error.hpp"

TEST(BatteryTest, MinMaxCurrent) {
  jetsonbatt::battery batt;
  batt.get_minmax_current();
  ASSERT_EQ(-1.0, batt.min_current);
  ASSERT_EQ(1.0, batt.max_current);
}

int main(int argc, char** argv) {
  testing::InitGoogleTest(&argc, argv);
  return RUN_ALL_TESTS();
}