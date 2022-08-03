#include "testSTL.h"
//using namespace std;

class my_true_type{};
class my_false_type{};

template <typename T>
struct type_traits
{
    typedef my_false_type isInteger;
};

template <>
struct type_traits<char>
{
    typedef my_true_type isInteger;
};


template <>
struct type_traits<unsigned char>
{
    typedef my_true_type isInteger;
};


template <>
struct type_traits<signed char>
{
    typedef my_true_type isInteger;
};


template <>
struct type_traits<short>
{
    typedef my_true_type isInteger;
};


template <>
struct type_traits<unsigned short>
{
    typedef my_true_type isInteger;
};


template <>
struct type_traits<int>
{
    typedef my_true_type isInteger;
};


template <>
struct type_traits<unsigned int>
{
    typedef my_true_type isInteger;
};


template <>
struct type_traits<long>
{
    typedef my_true_type isInteger;
};


template <>
struct type_traits<unsigned long>
{
    typedef my_true_type isInteger;
};


template <>
struct type_traits<long long>
{
    typedef my_true_type isInteger;
};

template <>
struct type_traits<unsigned long long>
{
    typedef my_true_type isInteger;
};
