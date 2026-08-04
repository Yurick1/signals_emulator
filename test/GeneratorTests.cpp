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
                    std::string,
                    std::function<void (Generator<int>::Builder *, int *)>,
                    std::function<int (int, int *)>
                >
            > {};

    constexpr auto expected_count = 100;
    const auto value_changers = new int[]{2, 3, 4, 5};
    Generator<int>::Builder *builder = nullptr;
    Generator<int> *generator = nullptr;

    template<typename T>
    class RepeaterTimeGraph: public TimeGraph<T>
    {
    public:
        explicit RepeaterTimeGraph() {}

        T operator[](double time) override
        {
            return time;
        }
    };
}

TEST(GeneratorTests, shouldThrowWhenTimeGraphIsNull)
{
    ASSERT_THROW(Generator<int>::Builder().build(), std::invalid_argument);
}

TEST_P(GeneratorTests, sholdBeValueChangedByDifferentGeneratorParameters)
{
    // Given
    const auto setupGeneratorBuilder = std::get<1>(GetParam());
    builder = new Generator<int>::Builder();
    builder->setGraph(new RepeaterTimeGraph<int>());
    setupGeneratorBuilder(builder, value_changers);
    generator = builder->build();

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

    delete builder;
    delete generator; //TODO: move to tear_down
}

INSTANTIATE_TEST_SUITE_P(
    GeneratorTests,
    GeneratorTests,
    ::testing::Values(
        std::make_tuple(
            "shouldRepeatValues",
            [](Generator<int>::Builder *builder, const int *values_to_set)
            {
            },
            [](const int arg, const int *changers)
            {
                return arg;
            }
        ),
        std::make_tuple(
            "shouldRepeatValuesWithMultipliedFrequency",
            [](Generator<int>::Builder *builder, const int *values_to_set)
            {
                builder->setFrequency(values_to_set[FREQUENCY_PARAMETER]);
            },
            [](const int arg, const int *changers)
            {
                return arg * changers[FREQUENCY_PARAMETER];
            }
        ),
        std::make_tuple(
            "shouldRepeatValuesWithAddedPhase",
            [](Generator<int>::Builder *builder, const int *values_to_set)
            {
                builder->setPhase(values_to_set[PHASE_PARAMETER]);
            },
            [](const int arg, const int *changers)
            {
                return arg + changers[PHASE_PARAMETER];
            }
        ),
        std::make_tuple(
            "shouldRepeatFunctionResultsWithMultipliedAmplitude",
            [](Generator<int>::Builder *builder, const int *values_to_set)
            {
                builder->setAmplitude(values_to_set[AMPLITUDE_PARAMETER]);
            },
            [](const int arg, const int *changers)
            {
                return changers[AMPLITUDE_PARAMETER] * arg;
            }
        ),
        std::make_tuple(
            "shouldRepeatFunctionResultsWithAddedOffset",
            [](Generator<int>::Builder *builder, const int *values_to_set)
            {
                builder->setOffset(values_to_set[OFFSET_PARAMETER]);
            },
            [](const int arg, const int *changers)
            {
                return arg + changers[OFFSET_PARAMETER];
            }
        )
    )
);
