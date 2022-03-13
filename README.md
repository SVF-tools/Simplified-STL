# Simplified C++ STL

A simplified version of the C++
Standard Library in aims of achieving a shorter, simpler LLVM IR to allow for a more efficient static software analysis of single files or of a whole program.

## Compiling C++ files into IR
To compile a C++ file into its LLVM IR, use the following command line argument
```
clang++ -S -c -emit-llvm ./basic_cpp_tests/forward_list-1.cpp -o check.ll
```

To compile a C++ file into its LLVM IR using our Simplified C++ STL, use the -I clang flag

```
clang++ -S -c -emit-llvm -Isimplestl ./basic_cpp_tests/forward_list-1.cpp -o check.ll
```
## Compiling whole program UPDATE
```
install wllvm, see: https://github.com/banach-space/llvm-tutor

1) Run main.py
2) Enter the link to your GitHub project
3) Follow the steps by the program for the paths to necessary dependencies (Simplified-STL folder and LLVM folder)
4) The resulting whole program bitcode file will be in the "build" folder named "result"

```

## References
All class templates were obtained from: https://en.cppreference.com/w/cpp/header and https://www.cplusplus.com/reference/stl/

## Implementation

### Vector
Our simple implementation of the vector class uses a dynamic array.

```
namespace std{
    template <typename T>
    class vector {
        private:
            T* arr;
            static const size_t INITIAL_CAPACITY = 10;  // initial capacity of the array  
            size_t space;                               // space used by vector including elements and free space
            size_t _size;                                // the current number of items in the array
```

### Array
A straightforward implementation of an array
```
namespace std{
    template <typename T, unsigned int N>
    class array {
        private:
            size_t size;
            T* array;
```

### Stack
We are using our custom vector class as the underlying data structure for the simple stack
```
#include "vector"

namespace std{
    template <class T>
    class stack {
    private:
        std::vector<T> container;
```

### Queue
We aim to implement the queue using the custom list as our underlying data structure or as a singly-linked list.

### Deque

### Forward List
The forward list class will be implemented as a singly-linked list using a custom forward_list node data structure

### List
The list class will be implemented as a doubly-linked list using a custom list node data structure that contains a reference to the next and previous node
```
#include "DNode.h"
namespace std {
    template<class T>
    class list {
        private:
            typedef struct DNode* DNode*;

            DNode* head;        // A reference to the head of the list
            DNode* tail;        // A reference to the end of the list
            int num_items;      // The size of the list
```
### Map

### Unordered Map

### Set
The set class is implemented as a Red-Black Tree

### Unordered_Set

### Iterators
Iterators are implemented to avoid code redundancy

## TODO
- [X]  vector declaration
    - [ ] vector implementations (in prog)
- [X]  deque declaration
    - [ ] deque implementations (in prog)
- [X]  array declaration
    - [ ] array implementations (in prog)
- [X]  forward_list declaration
    - [ ] forward_list implementations (in prog)
- [X]  list declaration
    - [ ] list implementations (in prog)
- [X]  map declaration
    - [ ] map implementations (in prog)
- [X]  queue declaration
    - [ ] queue implementations (in prog)
- [X]  set declaration
    - [ ] set implementations (in prog)
- [X]  stack declaration
    - [ ] stack implementations (in prog)
- [X]  unordered_map declaration
    - [ ] unordered_map implementations (in prog)
- [X]  unordered_set declaration
    - [ ] unordered_set implementations (in prog)

