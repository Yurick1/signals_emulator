//
// Created by yurickn on 24/07/2026.
//

#ifndef SIGNALS_EMULATOR_SINE_H
#define SIGNALS_EMULATOR_SINE_H

#include "Graph.h"

template<typename T>
class Sine: public Graph<T>
{
public:
    explicit Sine();

    T operator[](double angle) override;
};

#endif //SIGNALS_EMULATOR_SINE_H
