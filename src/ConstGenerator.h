//
// Created by yurickn on 13/07/2026.
//

#ifndef SIGNALS_EMULATOR_CONST_GENERATOR_H
#define SIGNALS_EMULATOR_CONST_GENERATOR_H

#include "Generator.h"

template <typename T>
class ConstGenerator: public Generator<T, T> {
    const T value;
public:
    explicit ConstGenerator(T value);
    T generate(T arg) override;
};

#endif //SIGNALS_EMULATOR_CONST_GENERATOR_H
