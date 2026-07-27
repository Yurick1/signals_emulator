//
// Created by yurickn on 13/07/2026.
//

#include "gtest/gtest.h"
#include "../src/Const.cpp"

TEST(ConstTests, shouldReturnTheSameValue)
{
    // Given
    constexpr auto given_count = 100;
    constexpr auto expected_val = 123;
    auto graph = Const(expected_val);

    // When
    auto actual_vec = std::vector<int>();
    for (int i = 0; i < given_count; i++)
    {
        actual_vec.push_back(graph[i]);
    }

    // Then
    EXPECT_EQ(given_count, actual_vec.size());

    std::for_each(
        actual_vec.begin(), actual_vec.end(),
        [expected_val](auto const &it)
        {
            EXPECT_EQ(expected_val, it);
        }
    );
}
