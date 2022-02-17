// iterator with random access
#pragma once

template<typename blDataType>
class iterator_base
{
public:
    using value_type        = blDataType;
    using pointer           = blDataType*;
    using reference         = blDataType&;
    using difference_type   = std::ptrdiff_t;

    iterator_base(pointer ptr) : m_ptr(ptr) {}
    iterator_base(const iterator_base<blDataType>& rawIterator) = default;
    ~iterator_base() {}

    iterator_base<blDataType>&                  operator=(const iterator_base<blDataType>& rawIterator) = default;
    iterator_base<blDataType>&                  operator=(blDataType* ptr){m_ptr = ptr;return (*this);}

    operator                                    bool()const
    {
        if(m_ptr)
            return true;
        else
            return false;
    }

    bool                                        operator==(const iterator_base<blDataType>& rawIterator)const{return (m_ptr == rawIterator.getConstPtr());}
    bool                                        operator!=(const iterator_base<blDataType>& rawIterator)const{return (m_ptr != rawIterator.getConstPtr());}

    iterator_base<blDataType>&                  operator+=(const difference_type& movement){m_ptr += movement;return (*this);}
    iterator_base<blDataType>&                  operator-=(const difference_type& movement){m_ptr -= movement;return (*this);}
    iterator_base<blDataType>&                  operator++(){++m_ptr;return (*this);}
    iterator_base<blDataType>&                  operator--(){--m_ptr;return (*this);}
    iterator_base<blDataType>                   operator++(int){auto temp(*this);++m_ptr;return temp;}
    iterator_base<blDataType>                   operator--(int){auto temp(*this);--m_ptr;return temp;}
    iterator_base<blDataType>                   operator+(const difference_type& movement){auto oldPtr = m_ptr;m_ptr+=movement;auto temp(*this);m_ptr = oldPtr;return temp;}
    iterator_base<blDataType>                   operator-(const difference_type& movement){auto oldPtr = m_ptr;m_ptr-=movement;auto temp(*this);m_ptr = oldPtr;return temp;}

    difference_type                             operator-(const iterator_base<blDataType>& rawIterator){return std::distance(rawIterator.getPtr(),this->getPtr());}

    blDataType&                                 operator*(){return *m_ptr;}
    const blDataType&                           operator*()const{return *m_ptr;}
    blDataType*                                 operator->(){return m_ptr;}

    blDataType*                                 getPtr()const{return m_ptr;}
    const blDataType*                           getConstPtr()const{return m_ptr;}


protected:
    blDataType*       m_ptr;

};