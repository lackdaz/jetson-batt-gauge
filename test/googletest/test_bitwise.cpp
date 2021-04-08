#include "gtest/gtest.h"
#include "bitwise.hpp"
#include "jetsonbatt_error.hpp"

#include <boost/cstdint.hpp>

TEST(TwosComplementTest, 8bit) {
  ASSERT_EQ(0, bitwise::bin8(0));
  ASSERT_EQ(-1, bitwise::bin8(255));
  ASSERT_EQ(127, bitwise::bin8(127));
  ASSERT_EQ(-128, bitwise::bin8(128));
  ASSERT_EQ(1, sizeof(bitwise::bin8(255)));
}

TEST(TwosComplementTest, test) {
  ASSERT_EQ(256, bitwise::bin16(256));
  ASSERT_EQ(2, sizeof(bitwise::bin16(256)));
}

int main(int argc, char** argv) {
  testing::InitGoogleTest(&argc, argv);
  return RUN_ALL_TESTS();
}