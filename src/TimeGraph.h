//
// Created by yurickn on 24/07/2026.
//

#ifndef SIGNALS_EMULATOR_TIME_GRAPH_H
#define SIGNALS_EMULATOR_TIME_GRAPH_H

template<typename T>
class TimeGraph
{
public:
    virtual T operator[](double time) = 0;

    virtual ~TimeGraph() = default;
};

#endif //SIGNALS_EMULATOR_TIME_GRAPH_H
