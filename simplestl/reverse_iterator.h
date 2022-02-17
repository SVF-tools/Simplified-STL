// Reverse iterator with random access

#include "iterator.h"

template<typename DataType>
class reverse_iterator_base : public iterator_base<DataType>
{
    public:
        using value_type        = DataType;
        using pointer           = DataType*;
        using reference         = DataType&;
        using difference_type   = std::ptrdiff_t;

        reverse_iterator_base(DataType* ptr = nullptr):iterator_base<DataType>(ptr){}
        reverse_iterator_base(const iterator_base<DataType>& rawIterator){this->m_ptr = rawIterator.getPtr();}
        reverse_iterator_base(const reverse_iterator_base<DataType>& rawReverseIterator) = default;
        ~reverse_iterator_base(){}

        reverse_iterator_base<DataType>&           operator=(const reverse_iterator_base<DataType>& rawReverseIterator) = default;
        reverse_iterator_base<DataType>&           operator=(const iterator_base<DataType>& rawIterator){this->m_ptr = rawIterator.getPtr();return (*this);}
        reverse_iterator_base<DataType>&           operator=(DataType* ptr){this->setPtr(ptr);return (*this);}

        reverse_iterator_base<DataType>&           operator+=(const difference_type& movement){this->m_ptr -= movement;return (*this);}
        reverse_iterator_base<DataType>&           operator-=(const difference_type& movement){this->m_ptr += movement;return (*this);}
        reverse_iterator_base<DataType>&           operator++(){--this->m_ptr;return (*this);}
        reverse_iterator_base<DataType>&           operator--(){++this->m_ptr;return (*this);}
        reverse_iterator_base<DataType>            operator++(int){auto temp(*this);--this->m_ptr;return temp;}
        reverse_iterator_base<DataType>            operator--(int){auto temp(*this);++this->m_ptr;return temp;}
        reverse_iterator_base<DataType>            operator+(const int& movement){auto oldPtr = this->m_ptr;this->m_ptr-=movement;auto temp(*this);this->m_ptr = oldPtr;return temp;}
        reverse_iterator_base<DataType>            operator-(const int& movement){auto oldPtr = this->m_ptr;this->m_ptr+=movement;auto temp(*this);this->m_ptr = oldPtr;return temp;}

        iterator_base<DataType>                   base(){iterator_base<DataType> forwardIterator(this->m_ptr); ++forwardIterator; return forwardIterator;}
};