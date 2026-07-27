//
// Created by yurickn on 27/07/2026.
//

#include "gtest/gtest.h"
#include "../src/Generator.cpp"

namespace
{
    class GeneratorTests: public testing::TestWithParam<
                std::tuple<
                    std::string,
                    std::function<void (int)>,
                    std::function<int (int, int)>
                >
            > {};

    Generator<int> *generator = nullptr;
}

TEST_P(GeneratorTests, sholdBeValueChangedByDifferentGeneratorParameters)
{
    // Given
    constexpr auto expected_count = 100;
    constexpr auto changer = 5;
    generator = new Generator<int>(); //TODO: move to before_each
    const auto set = std::get<1>(GetParam());
    set(changer);

    // When
    auto actual_angle_to_value_map = std::map<int, int>();
    for (auto i = 0; i < expected_count; i++)
    {
        actual_angle_to_value_map[i] = (*generator)[i];
    }

    // Then
    ASSERT_EQ(expected_count, actual_angle_to_value_map.size());

    const auto change_expected_value = std::get<2>(GetParam());
    std::for_each(
        actual_angle_to_value_map.begin(), actual_angle_to_value_map.end(),
        [&change_expected_value](auto const &pair)
        {
            ASSERT_EQ(change_expected_value(pair.first, changer), pair.second);
        }
    );
    free(generator); //TODO: move to tear_down
}

INSTANTIATE_TEST_SUITE_P(
    GeneratorTests,
    GeneratorTests,
    ::testing::Values(
        std::make_tuple(
            "shouldRepeatValues",
            [&]([[maybe_unused]]const int value_to_set){},
            [](const int arg, [[maybe_unused]]const int changer)
            {
            return arg;
            }
        ),
        std::make_tuple(
            "shouldRepeatValuesWithMultipliedFrequency",
            [&](const int value_to_set)
            {
            generator->setFrequency(value_to_set);
            },
            [](const int arg, const int changer)
            {
            return arg * changer;
            }
        ),
        std::make_tuple(
            "shouldRepeatValuesWithAddedPhase",
            [&](const int value_to_set)
            {
            generator->setPhase(value_to_set);
            },
            [](const int arg, const int changer)
            {
            return arg + changer;
            }
        )
    )
);
