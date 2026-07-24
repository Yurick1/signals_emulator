//
// Created by yurickn on 24/07/2026.
//

#ifndef SIGNALS_EMULATOR_SINE_GENERATOR_H
#define SIGNALS_EMULATOR_SINE_GENERATOR_H
#include "Generator.h"

template <typename RESULT, typename ARG>
class SineGenerator: public Generator<RESULT, ARG> {
public:
    explicit SineGenerator();
    RESULT generate(ARG arg) override;
};

#endif //SIGNALS_EMULATOR_SINE_GENERATOR_H
