//
// Created by yurickn on 13/07/2026.
//

#ifndef SIGNALS_EMULATOR_CONST_H
#define SIGNALS_EMULATOR_CONST_H

#include "Graph.h"

template<typename T>
class Const: public Graph<T>
{
    const T value;

public:
    explicit Const(T value);

    T operator[](double angle) override;
};

#endif //SIGNALS_EMULATOR_CONST_H
