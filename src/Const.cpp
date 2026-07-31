//
// Created by yurickn on 13/07/2026.
//

#include "Const.h"

template<typename T>
Const<T>::Const(const T value): value(value) {}

template<typename T>
T Const<T>::operator[]([[maybe_unused]] const double angle)
{
    return value;
}
