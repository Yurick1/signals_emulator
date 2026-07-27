//
// Created by yurickn on 24/07/2026.
//

#ifndef SIGNALS_EMULATOR_GRAPH_H
#define SIGNALS_EMULATOR_GRAPH_H

template<typename T>
class Graph
{
public:
    virtual T operator[](double angle) = 0;

    virtual ~Graph() = default;
};

#endif //SIGNALS_EMULATOR_GRAPH_H
