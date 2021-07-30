#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <boost/any.hpp>
#include <iostream>
#include "gtest/gtest.h"

#include "battery.hpp"

#include "jetsonbatt_error.hpp"

TEST(SquareRootTest, PositiveNos) {
  ASSERT_EQ(6, 3 + 3);
  ASSERT_EQ(18.0, 10 + 8);
  ASSERT_EQ(0, 0 + 0);
}

int main(int argc, char** argv) {
  testing::InitGoogleTest(&argc, argv);
  return RUN_ALL_TESTS();
}