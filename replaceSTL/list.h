#pragma once

namespace std {
    template<class T>
    class list {
        public:
            using value_type        = T;
            using reference         = value_type&;
            using const_reference   = const value_type&;
            using size_type         = size_t;

            struct iterator 
            {
            /* ITERATOR PROPERTIES */
            // using iterator_category = std::forward_iterator_tag;
            // using difference_type   = std::ptrdiff_t;
            using value_type        = T;            // the type the iterator iterates over
            using pointer           = value_type*;  // Defines a pointer to the type iterated over
            using reference         = value_type&;  // Defines a reference to the type iterated over
            iterator(pointer ptr) : m_ptr(ptr) {}

            reference operator*() const { return *m_ptr; }
            pointer operator->() { return m_ptr; }

            private:
                pointer m_ptr;
            };

            struct const_iterator
            {
                using value_type = T;
                using pointer = T; 
                using reference = T&;

                const_iterator(pointer ptr) : m_ptr(ptr) {}

                pointer operator->() { return m_ptr; }
                reference operator*() {return m_ptr; }

                private:
                    pointer m_ptr;
            };

            /* construct/copy/destroy */

            forward_list(const forward_list& x);
            forward_list(forward_list&& x);
            ~forward_list();


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

        private:
            T val[200];
            T frnt;
            unsigned int capacity;
            unsigned int current;
    }; // end list class


// begin implementation

/* modifiers */
template<class T>
void list<T>::push_front(const T& x){ }

template<class T>
void list<T>::push_front(T&& x){ }

template<class T>
void list<T>::pop_front(){ }


} // end namespace std



