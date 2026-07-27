//
// Created by yurickn on 13/07/2026.
//

#include "gtest/gtest.h"
#include "../src/ConstGenerator.cpp"

TEST(ConstantValueGeneratorTests, test)
{
    // Given
    constexpr auto given_count = 100;
    constexpr auto expected_val = 123;
    auto generator = ConstGenerator(expected_val);

    // When
    auto actual_vec = std::vector<int>();
    for (int i = 0; i < given_count; i++)
    {
        actual_vec.push_back(generator.generate(i));
    }

    // Then
    EXPECT_EQ(given_count, actual_vec.size());
    for (auto actual_val: actual_vec)
    {
        EXPECT_EQ(expected_val, actual_val + 1);
    }
}
