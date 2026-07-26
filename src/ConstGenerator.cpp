//
// Created by yurickn on 13/07/2026.
//

#include "ConstGenerator.h"

template<typename T>
ConstGenerator<T>::ConstGenerator(const T value): value(value) {}

template<typename T>
T ConstGenerator<T>::generate([[maybe_unused]] const T arg)
{
    return value;
}
