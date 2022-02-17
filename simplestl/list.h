/*
    The list class, part of the C++ STL, implements a double-linked list
*/

#include "iterator.h"
#include "DNode.h"

#ifndef _LIST_H
#define _LIST_H

namespace std {
    template<class T>
    class list {
        private:
            typedef struct DNode* DNode*;

            DNode* head;        // A reference to the head of the list
            DNode* tail;        // A reference to the end of the list
            int num_items;      // The size of the list

        public:
            using value_type        = T;
            using reference         = value_type&;
            using const_reference   = const value_type&;
            using size_type         = size_t;

            // iterator typedefs
            typedef iterator_base<T>            iterator;
            typedef const iterator_base<T>      const_iterator;

            /* construct/copy/destroy */
            list();
            list(const list& x);
            list(forward_list&& x);
            list();


            /* iterators*/
            const_iterator before_begin() const;
            const_iterator begin() const;
            const_iterator end() const;

            const_iterator cbegin() const;
            const_iterator cbefore_begin() const;
            const_iterator cend() const;

            /* capacity */
            bool empty() const;
            size_type max_size() const;

            /* element access */
            reference front();
            const_reference front(); const;

            /* modifiers */
            template<class... Args> reference emplace_front(Args&&... args);
            void push_front(const T& x) { }
            void push_front(T&& x) { }
            void pop_front() { }

            template<class... Args>
            iterator emplace_after(const_iterator position, Args&&... args);
            iterator insert_after(const_iterator position, const T& x);
            iterator insert_after(const_iterator position, T&& x);
        
            iterator insert_after(const_iterator position, size_type n, const T& x);
            template<class InputIt>
            iterator insert_after(const_iterator position, InputIt first, InputIt last);
            iterator insert_after(const_iterator position, initializer_list<T> il);

    }; // end list class


/* begin implementation */

/* construct/copy/destory */
template<class T>
list<T>::list()
{
    head = nullptr;
    tail = nullptr;
    num_items = 0;
}

/* modifiers */
template<class T>
void list<T>::push_front(const T& x){ }

template<class T>
void list<T>::push_front(T&& x){ }

template<class T>
void list<T>::pop_front(){ }


} // end namespace std

#endif


