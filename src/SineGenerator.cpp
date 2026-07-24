//
// Created by yurickn on 24/07/2026.
//

#include <cmath>

#include "SineGenerator.h"

template<typename RESULT, typename ARG>
SineGenerator<RESULT, ARG>::SineGenerator() {}

template<typename RESULT, typename ARG>
RESULT SineGenerator<RESULT, ARG>::generate(const ARG arg)
{
    return std::sin(arg);
}
