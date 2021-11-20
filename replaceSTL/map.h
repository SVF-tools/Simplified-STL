#include <utility>

#ifndef MAP_H
#define MAP_H

namespace std{
    template<class Key, class T>
    class map {
        public:
            using key_type      = Key;
            using mapped_type   = T;

            struct const_iterator
            {
                using value_type = std::pair<K, V>;
                using pointer = std::pair<K, V>; 
                using reference = std::pair<K, V>&;

                const_iterator(pointer ptr) : m_ptr(ptr) {}

                pointer* operator ->() { return &m_ptr; }

                private:
                pointer m_ptr;
            }

            // capacity
            bool empty() const { return current == 0; }
            size_type size() {}
            size_type max_size() {}

            // element access
            mapped_type& operator[] (const key_type& x) {}
            mapped_type& operator[] (key_type& x) {}
            mapped_type&            at(const key_type& x) {}
            const mapped_type&      at(const key_type& x) {}
        private:
            int capacity;
            int current;
    }; // end map class

} // end namespace std

#endif