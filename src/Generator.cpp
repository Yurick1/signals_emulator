//
// Created by yurickn on 27/07/2026.
//

#include <stdexcept>

#include "Generator.h"

#define DEFAULT_ADDITION_VALUE 0
#define DEFAULT_MULTIPLICATION_VALUE 1

template<typename T>
Generator<
    T>::Generator(const int frequency, const double phase, const double amplitude,
                  const double offset): frequency(frequency), phase(phase), amplitude(amplitude), offset(offset) {}

template<typename T>
Generator<T>::Builder::Builder(): frequency(DEFAULT_MULTIPLICATION_VALUE),
                                  phase(DEFAULT_ADDITION_VALUE),
                                  amplitude(DEFAULT_MULTIPLICATION_VALUE),
                                  offset(DEFAULT_ADDITION_VALUE),
                                  graph(nullptr) {}

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
Generator<T>::Builder &Generator<T>::Builder::setGraph(TimeGraph<T> *g)
{
    this->graph = g;
    return *this;
}

template<typename T>
Generator<T> *Generator<T>::Builder::build()
{
    if (!this->graph)
    {
        throw std::invalid_argument("Graph is null");
    }
    return new Generator(frequency, phase, amplitude, offset);
}

template<typename T>
T Generator<T>::operator[](const double angle) const
{
    return amplitude * (frequency * angle + phase) + offset;
}
