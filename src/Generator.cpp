//
// Created by yurickn on 27/07/2026.
//

#include "Generator.h"

#define DEFAULT_ADDITION_VALUE 0
#define DEFAULT_MULTIPLICATION_VALUE 1

template<typename T>
Generator<T>::Generator():
frequency(DEFAULT_MULTIPLICATION_VALUE),
phase(DEFAULT_ADDITION_VALUE),
amplitude(DEFAULT_MULTIPLICATION_VALUE),
offset(DEFAULT_ADDITION_VALUE) {}

template<typename T>
void Generator<T>::setFrequency(const int f)
{
    this->frequency = f;
}

template<typename T>
void Generator<T>::setPhase(const double ph)
{
    this->phase = ph;
}

template<typename T>
void Generator<T>::setAmplitude(double a)
{
    this->amplitude = a;
}

template<typename T>
void Generator<T>::setOffset(double o)
{
    this->offset = o;
}

template<typename T>
T Generator<T>::operator[](const double angle) const
{
    return amplitude * (frequency * angle + phase) + offset;
}
