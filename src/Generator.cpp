//
// Created by yurickn on 27/07/2026.
//

#include "Generator.h"

#define DEFAULT_ADDITION_VALUE 0
#define DEFAULT_MULTIPLICATION_VALUE 1

template<typename T>
Generator<T>::Generator(const int frequency, const double phase, const double amplitude, const double offset):
frequency(frequency), phase(phase), amplitude(amplitude), offset(offset) {}

template<typename T>
Generator<T>::Builder::Builder():
    frequency(DEFAULT_MULTIPLICATION_VALUE),
    phase(DEFAULT_ADDITION_VALUE),
    amplitude(DEFAULT_MULTIPLICATION_VALUE),
    offset(DEFAULT_ADDITION_VALUE) {}

template<typename T>
Generator<T>::Builder &Generator<T>::Builder::setFrequency(int f)
{
    this->frequency = f;
    return *this;
}

template<typename T>
Generator<T>::Builder &Generator<T>::Builder::setPhase(double p)
{
    this->phase = p;
    return *this;
}

template<typename T>
Generator<T>::Builder &Generator<T>::Builder::setAmplitude(double a)
{
    this->amplitude = a;
    return *this;
}

template<typename T>
Generator<T>::Builder &Generator<T>::Builder::setOffset(double o)
{
    this->offset = o;
    return *this;
}

template<typename T>
Generator<T> *Generator<T>::Builder::build()
{
    return new Generator<T>(frequency, phase, amplitude, offset);
}

template<typename T>
T Generator<T>::operator[](const double angle) const
{
    return amplitude * (frequency * angle + phase) + offset;
}
