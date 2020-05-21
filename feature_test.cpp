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

namespace MEMBER_TEMPLATE{
    class alloc{
    };
    template <typename T, typename Alloc = alloc>
    class vector{
    public:
        typedef T value_type;
        typedef value_type *iterator;
        template<typename I>
        void insert(iterator pos, I first, I last){
            cout << "insert()" << endl;
        }
    };

    void mainfunc(){
        int ia[] = {1, 2, 3, 4};
        vector<int> ivec;
        vector<int>::iterator itor;
        ivec.insert(itor, ia, ia + 3);
    }
}

/**
 * 测试模板参数的默认值，以及是否可以用模板参数作为参数，以及非类型模板参数
 * 友元模板测试
 */
namespace LIMITED_DEFAULT_TEMPLATE{
#include<cstddef>
    class alloc{
    };
    template<typename T, typename Alloc = alloc, size_t BufSiz = 0>
    class deque{
    public:
        deque() { cout << "deque" << endl; }
    };

    template <typename T, typename Seq>
    class stack;

    template <typename T, typename Seq>
    bool operator==(const stack<T,Seq> &, const stack<T,Seq> &);

    template<typename T, typename Sequence=deque<T>>
    class stack{
        //friend bool operator==<>(const stack &, const stack &);
        friend bool operator==<T>(const stack &, const stack &);
        friend bool operator==<T>(const stack<T> &, const stack<T> &);
        //!friend bool operator==(const stack &, const stack &);
    public:
        stack() { cout << "stack" << endl; }
    private:
        Sequence seq;
    };

    void mainfunc(){
        stack<int> s;
    }
}

class T{
public:
    static int get_si(){
        return si;
    }
private:
    static const int si = 8;
};

int main(){
    STATIC_TEMPLATE_MEMBER::mainfunc();
    CLASS_PARTIAL_SPECIALIZATION::mainfunc();
    FUNC_TEMP_PARTIAL_ORDER::mainfunc();
    MEMBER_TEMPLATE::mainfunc();
    LIMITED_DEFAULT_TEMPLATE::mainfunc();
    cout << T::get_si() << endl;
    return 0;
}