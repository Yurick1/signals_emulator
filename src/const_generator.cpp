//
// Created by yurickn on 13/07/2026.
//

#include "const_generator.h"

std::vector<int> generate_const_signal(const int count, const int value)
{
    auto result = std::vector<int>();
    for (int i = 0; i < count; i++)
    {
        result.push_back(value);
    }
    return result;
}