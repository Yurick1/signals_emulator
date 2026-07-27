//
// Created by yurickn on 24/07/2026.
//

#include <cmath>

#include "Sine.h"

template<typename T>
Sine<T>::Sine() {}

template<typename T>
T Sine<T>::operator[](const double angle)
{
    return std::sin(angle);
}
