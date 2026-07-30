//
// Created by yurickn on 24/07/2026.
//

#ifndef SIGNALS_EMULATOR_SINE_H
#define SIGNALS_EMULATOR_SINE_H

#include "TimeGraph.h"

template<typename T>
class Sine: public TimeGraph<T>
{
public:
    explicit Sine();

    T operator[](double time) override;
};

#endif //SIGNALS_EMULATOR_SINE_H
