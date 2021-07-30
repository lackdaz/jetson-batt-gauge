#include "gtest/gtest.h"
#include "bitwise.hpp"
#include "jetsonbatt_error.hpp"

#include <boost/cstdint.hpp>

TEST(TwosComplementTest, 8bit) {
  ASSERT_EQ(0, bitwise::compute_signed_twos_complement(0));
  ASSERT_EQ(-1, bitwise::compute_signed_twos_complement(255));
  ASSERT_EQ(127, bitwise::compute_signed_twos_complement(127));
  ASSERT_EQ(-128, bitwise::compute_signed_twos_complement(128));
}

// TODO: what about 16bit?

int main(int argc, char** argv) {
  testing::InitGoogleTest(&argc, argv);
  return RUN_ALL_TESTS();
}