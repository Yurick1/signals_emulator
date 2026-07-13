//
// Created by yurickn on 11/07/2026.
//
// The simplest test case checking testing is working; example of test
//

#include <istream>

#include "gtest/gtest.h"

TEST(SelfTestSuit, self_test) {
    std::cout << "Hello World :) LOL" << std::endl;
    EXPECT_EQ(1, 1);
}