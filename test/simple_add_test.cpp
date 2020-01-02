//
// Created by slaanesh on 1/2/20.
//

#include <gtest/gtest.h>
#include <cstdint>
#include <iostream>

#include "simple_add.h"

TEST(simple_add, test1) {
  EXPECT_EQ(simple_add(INT32_MAX, INT32_MIN), -1);
  EXPECT_EQ(simple_add(INT32_MAX, 1), INT32_MIN);
}