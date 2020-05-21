#ifndef MY_ALGORITHMS_H
#define MY_ALGORITHMS_H

template<typename InputIterator, typename T>
InputIterator find(InputIterator first, InputIterator last, const T& value){
    while(first!=last&&*first!=value)
        ++first;
    return first;
}

#endif