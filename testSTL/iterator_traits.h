#include "testSTL.h"
//iterator_categories
struct simple_input_iterator_tag{};
struct simple_output_iterator_tag{};
struct simple_forward_iterator_tag : public simple_input_iterator_tag{};
struct simple_bidirectional_iterator_tag : public simple_forward_iterator_tag{};
struct simple_random_access_iterator_tag : public simple_bidirectional_iterator_tag{};


//standard iterator
template <class Category,
          class T,
          class Distance=ptrdiff_t,
          class Pointer=T*,
          class Reference=T&>
struct base_iterator
{
    typedef Category        iterator_category;
    typedef T               value_type;
    typedef Distance        difference_type;
    typedef Pointer         pointer;
    typedef Reference       reference;
};


//for generic algorithm
template <class Iterator>    //typename class
struct iterator_traits
{
    typedef typename Iterator::iterator_category    iterator_category;
    typedef typename Iterator::value_type           value_type;
    typedef typename Iterator::pointer              pointer;
    typedef typename Iterator::reference            reference;
    typedef typename Iterator::difference_type      difference_type;
};


//specialize
template <typename T>
struct iterator_traits<T*>
{
    typedef simple_random_access_iterator_tag  iterator_category;
    typedef T                           value_type;
    typedef T*                          pointer;
    typedef T&                          reference;
    typedef ptrdiff_t                   difference_type;
};

template <typename T>
struct iterator_traits<const T*>
{
    typedef simple_random_access_iterator_tag  iterator_category;
    typedef T                           value_type;
    typedef const T*                    pointer;
    typedef const T&                    reference;
    typedef ptrdiff_t                   difference_type;
};


//distance between two iterators
template <class InputIterator>
typename iterator_traits<InputIterator>::difference_type
distance(InputIterator begin,InputIterator end)
{
    typedef typename iterator_traits<InputIterator>::iterator_category category;
    return distance_dispatch(begin,end,category());
}

template <class InputIterator>
typename iterator_traits<InputIterator>::difference_type
distance_dispatch(InputIterator begin,InputIterator end,simple_input_iterator_tag)
{
    typename iterator_traits<InputIterator>::difference_type n=0;
    while(begin!=end){
        ++begin;++n;
    }
    return n;
}

template <class RandomAccessIterator>
typename iterator_traits<RandomAccessIterator>::difference_type
distance_dispatch(RandomAccessIterator begin,RandomAccessIterator end,simple_random_access_iterator_tag)
{
    return end-begin;
}


//advance n
template <class InputIterator>
InputIterator advance(InputIterator iter,
                      typename iterator_traits<InputIterator>::difference_type n)
{
    typedef typename iterator_traits<InputIterator>::iterator_category category;
    return advance_dispatch(iter,n,category());
}

template <class InputIterator>
InputIterator advance_dispatch(InputIterator iter,
                               typename iterator_traits<InputIterator>::difference_type n,
                               simple_input_iterator_tag)
{
    if(n<0)
        while(n++)
            --iter;
    else
        while(n--)
            ++iter;
    return iter;
}

template <class RandomAccessIterator>
RandomAccessIterator advance_dispatch(RandomAccessIterator iter,
                                      typename iterator_traits<RandomAccessIterator>::difference_type n,
                                      simple_random_access_iterator_tag)
{
    return iter+=n;
}


//extract Iterator's value_type
template <class Iterator>
typename iterator_traits<Iterator>::value_type*
value_type(const Iterator&)
{
    return static_cast<typename iterator_traits<Iterator>::value_type*>(0);
}

template <class Iterator>
typename iterator_traits<Iterator>::difference_type*
distance_type(const Iterator&)
{
    return static_cast<typename iterator_traits<Iterator>::difference_type*>(0);
}
