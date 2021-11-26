# Simplified C++ STL

A simplified version of the C++
Standard Library in aims of achieving a shorter, simpler LLVM IR to allow for a more efficient static software analysis.

## Compiling C++ files into IR
To compile a C++ file into its LLVM IR, use the following command line argument
```
clang++ -S -c -emit-llvm ./basic_cpp_tests/forward_list-1.cpp -o check.ll
```

To compile a C++ file into its LLVM IR using a simplified version of the C++ Standard Library, use the -I clang flag

```
clang++ -S -c -emit-llvm -IreplaceSTL ./basic_cpp_tests/forward_list-1.cpp -o check.ll
```
## Compiling whole program
```
1) export LLVM_DIR=/usr/bin/llvm-12       (or whatever your path to llvm is)
2) export LLVM_COMPILER=clang
make CXX=wllvm++ CXX_FLAGS="<old flags> -IreplacerIncludes"  / cmake CMAKE_C_COMPILER=wllvm++ CMAKE_CXX_COMPILER=wllvm++ CMAKE_CXX_FLAGS="<old flags> -IreplacerIncludes"    (depending on type of project c/c++) [IMPORTANT: please redeclare your old flags in the <old flags> part as the flags stated within the make file will be overwritten] {the cmake command is untested we need to test it later}
3) extract-bc <path to executable file created in step 2> -l$LLVM_DIR/bin/llvm-link
4) llvm-dis <path to bc file created in step 3>

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

### Deque

### Forward List

### List

### Map

### Unordered Map

### Set

### Unordered_Set

### Iterators


## TODO
- [ ]  deque
- [ ]  array
- [ ]  forward_list
- [ ]  list
- [ ]  map
- [ ]  queue
- [ ]  set
- [ ]  stack
- [ ]  unordered_map
- [ ]  unordered_set
- [ ]  vector
