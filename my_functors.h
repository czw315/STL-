#ifndef MY_FUNCTORS_H
#define MY_FUNCTORS_H

#include<iostream>
using namespace std;

template<typename T>
struct minus{
    T operator()(const T &x, const T &y) const { return x - y; }
};

template<typename T>
struct plus{
    T operator()(const T &x, const T &y) const { return x + y; }
};

#endif
