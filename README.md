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
## Compiling whole program
```
install wllvm, see: https://github.com/banach-space/llvm-tutor
1) export LLVM_DIR=/usr/lib/llvm-12       (or whatever your path to llvm is)
2) export LLVM_COMPILER=clang
3) make CXX=wllvm++ CXX_FLAGS="<old flags> -Isimplestl" [OR] cmake CMAKE_C_COMPILER=wllvm++ CMAKE_CXX_COMPILER=wllvm++ CMAKE_CXX_FLAGS="<old flags> -Isimplestl" (depending on type of project c/c++) 
[IMPORTANT: please redeclare your old flags in the <old flags> part as the flags stated within the make file will be overwritten] 
{the cmake command is untested we need to test it later}
4) extract-bc <path to executable file created in step 2> -l$LLVM_DIR/bin/llvm-link
5) llvm-dis <path to bc file created in step 3>

This will achieve a human readable file for the whole program
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
We aim to implement the set class as a BST

### Unordered_Set

### Iterators


## TODO
- [X]  deque declaration
    - [] deque implementations (in prog)
- [X]  array declaration
- [X]  forward_list declaration
- [X]  list declaration
- [X]  map declaration
- [X]  queue declaration
- [X]  set declaration
- [X]  stack declaration
- [X]  unordered_map declaration
- [X]  unordered_set declaration
- [X]  vector declaration
