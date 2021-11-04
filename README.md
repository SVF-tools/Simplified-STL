# Simplified C++ STL

We're implementing a simplified version of the C++
Standard Library in aims of simplifying an LLVM IR to allow for less messy software analysis

## Compiling C++ files into IR
To compile a C++ file into its LLVM IR, use the following command line argument
```
clang++ -S -c -emit-llvm ./basic_cpp_tests/forward_list-1.cpp -o check.ll
```

To compile a C++ file into its LLVM IR using a simplified version of the C++ Standard Library, use the -I clang flag

```
clang++ -S -c -emit-llvm -IreplaceSTL ./basic_cpp_tests/forward_list-1.cpp -o check.ll
```

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