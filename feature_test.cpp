/**
 * 基于STL源码剖析的第一章关于各种组态的测试
 */

#include<iostream>
using namespace std;

/**
 * 测试class template中拥有static data member
 */

namespace STATIC_TEMPLATE_MEMBER{
    template<typename T>
    class testClass{
    public:
        static int si;
    };
    //向比如原书中的需要加上template<>
    template<>
    int testClass<int>::si = 2;
    template<>
    int testClass<char>::si = 3;

    void mainfunc(){
        cout << testClass<int>::si << endl;     //测试为g++ -std=c++14以及-std=c++11
        cout << testClass<char>::si << endl;
        testClass<int>().si = 4;
        testClass<char>().si = 5;
        cout << testClass<int>::si << endl;
        cout << testClass<char>::si << endl;
    }
}
/**
 * 测试类模板的偏特化
 */
namespace CLASS_PARTIAL_SPECIALIZATION{
    template<typename T, typename I>
    class testClass{
    public:
        testClass() { cout << "T, I" << endl; }
    };

    template<typename T>
    class testClass<T*,T*>{
    public:
        testClass() { cout << "T*, T*" << endl; }
    };

    template<typename T>
    class testClass<const T*, T*>{
    public:
        testClass() { cout << "const T*" << endl; }
    };

    void mainfunc(){
        testClass<int, char> obj1;
        testClass<int *, int *> obj2;
        testClass<const int *, int *> obj3;
    }
}

/**
 * 测试函数模板的部分指定参数
 */
namespace FUNC_TEMP_PARTIAL_ORDER{
    class alloc{
    };
    template<typename T, typename Alloc=alloc>
    class vector{
    public:
        void swap(vector<T, Alloc> &) { cout << "swap()" << endl; }
    };

    void mainfunc(){
        vector<int> x,y;
        x.swap(y);
    }
}



int main(){
    STATIC_TEMPLATE_MEMBER::mainfunc();
    CLASS_PARTIAL_SPECIALIZATION::mainfunc();
    FUNC_TEMP_PARTIAL_ORDER::mainfunc();
    return 0;
}