//
// Created by yurickn on 13/07/2026.
//

#include "gtest/gtest.h"
#include "../src/const_generator.cpp"


TEST(ConstantValueGeneration, zero)
{
    // Given
    constexpr auto given_count = 100;
    constexpr auto expected_value_zero = 0;

    // When
    const auto actual_values = generate_const_signal(given_count, expected_value_zero);

    // Then
    EXPECT_EQ(given_count, actual_values.size());
    for (auto actual: actual_values)
    {
        EXPECT_EQ(actual, expected_value_zero);
    }

}
