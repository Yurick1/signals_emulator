//
// Created by yurickn on 27/07/2026.
//

#include "gtest/gtest.h"
#include "../src/Generator.cpp"

TEST(GeneratorTests, shouldRepeatValues)
{
    // Given
    constexpr auto expected_count = 100;
    const auto generator = Generator<int>();

    // When
    auto actual_angle_to_value_map = std::map<int, int>();
    for (auto i = 0; i < expected_count; i++)
    {
        actual_angle_to_value_map[i] = generator[i];
    }

    // Then
    ASSERT_EQ(expected_count, actual_angle_to_value_map.size());

    std::for_each(
        actual_angle_to_value_map.begin(), actual_angle_to_value_map.end(),
        [](auto const &pair)
        {
            ASSERT_EQ(pair.first, pair.second);
        }
    );
}

TEST(GeneratorTests, shouldRepeatValuesWithMultipliedFrequency)
{
    // Given
    constexpr auto expected_count = 100;
    auto generator = Generator<int>();
    generator.setFrequency(5);

    // When
    auto actual_angle_to_value_map = std::map<int, int>();
    for (auto i = 0; i < expected_count; i++)
    {
        actual_angle_to_value_map[i] = generator[i];
    }

    // Then
    ASSERT_EQ(expected_count, actual_angle_to_value_map.size());

    std::for_each(
        actual_angle_to_value_map.begin(), actual_angle_to_value_map.end(),
        [](auto const &pair)
        {
            ASSERT_EQ(pair.first * 5, pair.second);
        }
    );
}

TEST(GeneratorTests, shouldRepeatValuesWithAddedPhase)
{
    // Given
    constexpr auto expected_count = 100;
    auto generator = Generator<int>();
    generator.setPhase(5);

    // When
    auto actual_angle_to_value_map = std::map<int, int>();
    for (auto i = 0; i < expected_count; i++)
    {
        actual_angle_to_value_map[i] = generator[i];
    }

    // Then
    ASSERT_EQ(expected_count, actual_angle_to_value_map.size());

    std::for_each(
        actual_angle_to_value_map.begin(), actual_angle_to_value_map.end(),
        [](auto const &pair)
        {
            ASSERT_EQ(pair.first + 5, pair.second);
        }
    );
}
