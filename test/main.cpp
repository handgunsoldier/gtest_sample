//
// Created by slaanesh on 1/2/20.
//

#include <gtest/gtest.h>

int main(int argc, char **argv) {
  #ifdef foo
  std::cout << "foo is defined, with value:\t" << foo <<std::endl;
  #else
  std::cout << "foo is not defined!" << std::endl;
  #endif

  ::testing::InitGoogleTest(&argc, argv);
  return RUN_ALL_TESTS();
}