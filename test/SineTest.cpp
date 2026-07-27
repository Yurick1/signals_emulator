//
// Created by yurickn on 14/07/2026.
//

#include <cmath>

#include "gtest/gtest.h"
#include "../src/Sine.cpp"

TEST(SineTests, shouldReturnSinusValues)
{
    // Given
    constexpr auto given_count = 100;
    auto graph = Sine<double>();

    // When
    auto actual_angle_to_value_map = std::map<double, double>();
    for (int i = 0; i < given_count; i++)
    {
        actual_angle_to_value_map[i] = graph[i];
    }

    // Then
    EXPECT_EQ(given_count, actual_angle_to_value_map.size());

    std::for_each(
        actual_angle_to_value_map.begin(), actual_angle_to_value_map.end(),
        [](auto const &pair_it)
        {
            EXPECT_EQ(std::sin(pair_it.first), pair_it.second);
        }
    );
}
