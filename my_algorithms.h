#ifndef MY_ALGORITHMS_H
#define MY_ALGORITHMS_H

template<typename InputIterator, typename T>
InputIterator find(InputIterator first, InputIterator last, const T& value)
{
    while(first!=last&&*first!=value)
        ++first;
    return first;
}

template<typename InputIterator, typename Function>
Function for_each(InputIterator first, InputIterator last, Function f)
{
    for (; first != last; ++first)
        f(*first);
    return f;
}

#endif