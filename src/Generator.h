//
// Created by yurickn on 27/07/2026.
//

#ifndef SIGNALS_EMULATOR_GENERATOR_H
#define SIGNALS_EMULATOR_GENERATOR_H

#include "TimeGraph.h"

template<typename T>
class Generator
{
    const int frequency;
    const double phase;
    const double amplitude;
    const double offset;

    explicit Generator(int frequency, double phase, double amplitude, double offset);

public:
    class Builder
    {
        int frequency;
        double phase;
        double amplitude;
        double offset;
        TimeGraph<T> *graph;

    public:
        explicit Builder();
        Builder &setFrequency(int f);
        Builder &setPhase(double p);
        Builder &setAmplitude(double a);
        Builder &setOffset(double o);
        Builder &setGraph(TimeGraph<T> *g);
        Generator *build();
    };

    T operator[](double angle) const;
};

#endif //SIGNALS_EMULATOR_GENERATOR_H
