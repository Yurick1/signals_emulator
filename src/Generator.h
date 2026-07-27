//
// Created by yurickn on 27/07/2026.
//

#ifndef SIGNALS_EMULATOR_GENERATOR_H
#define SIGNALS_EMULATOR_GENERATOR_H

template<typename T>
class Generator
{
    int frequency;
    double phase;

public:
    explicit Generator();

    void setFrequency(int f);

    void setPhase(double ph);

    T operator[](double angle) const;
};

#endif //SIGNALS_EMULATOR_GENERATOR_H
