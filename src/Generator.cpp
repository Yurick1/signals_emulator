//
// Created by yurickn on 27/07/2026.
//

#include "Generator.h"

template<typename T>
Generator<T>::Generator(): frequency(1), phase(0) {}

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
T Generator<T>::operator[](const double angle) const
{
    return frequency * angle + phase;
}
