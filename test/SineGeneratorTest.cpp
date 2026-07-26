//
// Created by yurickn on 14/07/2026.
//

#include <cmath>

#include "gtest/gtest.h"
#include "../src/SineGenerator.cpp"

TEST(SineGeneratorTests, test)
{
    // Given
    constexpr auto given_count = 100;
    auto generator = SineGenerator<double, double>();

    // When
    auto actual_map = std::map<double, double>();
    for (int i = 0; i < given_count; i++)
    {
        actual_map[i] = generator.generate(i);
    }

    // Then
    EXPECT_EQ(given_count, actual_map.size());

    std::for_each(
        actual_map.begin(), actual_map.end(),
        [](auto const &it)
        {
            EXPECT_EQ(std::sin(it.first), it.second);
        }
    );
}
