//
// Created by yurickn on 27/07/2026.
//

#include "gtest/gtest.h"
#include "../src/Generator.cpp"

#define FREQUENCY_PARAMETER 0
#define PHASE_PARAMETER 1
#define AMPLITUDE_PARAMETER 2
#define OFFSET_PARAMETER 3

namespace
{
    class GeneratorTests: public testing::TestWithParam<
                std::tuple<
                    std::string, std::function<void (int *)>, std::function<int (int, int *)>
                >
            > {};

    Generator<int> *generator = nullptr;
}

TEST_P(GeneratorTests, sholdBeValueChangedByDifferentGeneratorParameters)
{
    // Given
    constexpr auto expected_count = 100;
    generator = new Generator<int>(); //TODO: move to before_each
    const auto set = std::get<1>(GetParam());
    const auto value_changers = new int[]{2, 3, 4, 5};
    set(value_changers);

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
        [&](auto const &pair)
        {
            ASSERT_EQ(change_expected_value(pair.first, value_changers), pair.second);
        }
    );
    free(generator); //TODO: move to tear_down
}

static void setupFunctionArgParameters(auto *gen, const int *values_to_set);

INSTANTIATE_TEST_SUITE_P(
    GeneratorTests,
    GeneratorTests,
    ::testing::Values(
        std::make_tuple(
            "shouldRepeatValues",
            [&]([[maybe_unused]]const int *values_to_set){},
            [](const int arg, [[maybe_unused]]const int *changers)
            {
                return arg;
            }
        ),
        std::make_tuple(
            "shouldRepeatValuesWithMultipliedFrequency",
            [&](const int *values_to_set)
            {
                generator->setFrequency(values_to_set[FREQUENCY_PARAMETER]);
            },
            [](const int arg, const int *changers)
            {
                return arg * changers[FREQUENCY_PARAMETER];
            }
        ),
        std::make_tuple(
            "shouldRepeatValuesWithAddedPhase",
            [&](const int *values_to_set)
            {
                generator->setPhase(values_to_set[PHASE_PARAMETER]);
            },
            [](const int arg, const int *changers)
            {
                return arg + changers[PHASE_PARAMETER];
            }
        ),
        std::make_tuple(
            "shouldRepeatFunctionResultsWithMultipliedAmplitude",
            [&](const int *values_to_set)
            {
                setupFunctionArgParameters(generator, values_to_set);
                generator->setAmplitude(values_to_set[AMPLITUDE_PARAMETER]);
            },
            [](const int arg, const int *changers)
            {
                return changers[AMPLITUDE_PARAMETER] * (changers[FREQUENCY_PARAMETER] * arg + changers[PHASE_PARAMETER]);
            }
        ),
        std::make_tuple(
            "shouldRepeatFunctionResultsWithAddedOffset",
            [&](const int *values_to_set)
            {
                setupFunctionArgParameters(generator, values_to_set);
                generator->setOffset(values_to_set[OFFSET_PARAMETER]);
            },
            [](const int arg, const int *changers)
            {
                return changers[FREQUENCY_PARAMETER] * arg + changers[PHASE_PARAMETER] + changers[OFFSET_PARAMETER];
            }
        )
    )
);

static void setupFunctionArgParameters(auto *gen, const int *values_to_set)
{
    gen->setFrequency(values_to_set[FREQUENCY_PARAMETER]);
    gen->setPhase(values_to_set[PHASE_PARAMETER]);
}
