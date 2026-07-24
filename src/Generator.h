//
// Created by yurickn on 24/07/2026.
//

#ifndef SIGNALS_EMULATOR_GENERATOR_H
#define SIGNALS_EMULATOR_GENERATOR_H


template <typename RESULT, typename ARG>
class Generator
{
public:
    virtual RESULT generate(ARG arg) = 0;
    virtual ~Generator() = default;
};


#endif //SIGNALS_EMULATOR_GENERATOR_H
