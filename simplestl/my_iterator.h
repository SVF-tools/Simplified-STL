            struct iterator
            {
                using value_type = T;
                using pointer = T*; 
                using reference = T&;

                iterator(pointer ptr) : curr(ptr) {}

                pointer operator->() { return curr; }
                reference operator*() {return curr; }
                iterator& operator++() { curr++; return *this; }
                /** Postfix increment operator
                 * @return A copy of this iterator before being advanced 
                 */
                iterator operator++(int)
                {
                    iterator return_val = *this;
                    ++(*this);
                    return return_val;
                }
                iterator& operator--() { curr--; return *this; }
                iterator operator--(int)
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
                    return *curr != *b.curr
                }
                
                private:
                    pointer curr;
            };