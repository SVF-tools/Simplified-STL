


            struct const_iterator
            {
                using value_type = const T;
                using pointer = const T*; 
                using reference = const T&;

                const_iterator(pointer ptr) : curr(ptr) {}

                const pointer operator->() const { return curr; }
                const reference operator*() const {return curr; }
                const const_iterator& operator++() const { curr++; return *this; }
                const const_iterator& operator++() const (int)
                {
                    const_iterator return_val = *this;
                    ++(*this);
                    return return_val;
                }
                const const_iterator& operator--() const
                {
                    iterator return_val = *this;
                    --(*this);
                    return return_val;
                }
                const const_iterator& operator--(int)
                {
                    iterator return_val = *this;
                    --(*this);
                    return return_val;   
                }

                bool operator==(const iterator& b) const
                {
                    return *curr == *b.curr;
                }

                bool operator!=(const iterator& b) const
                {
                    return *curr != *b.curr;
                }

                private:
                    pointer curr;
            };