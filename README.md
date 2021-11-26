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
## Compiling whole program
```
1) export LLVM_DIR=/usr/lib/llvm-12       (or whatever your path to llvm is)
2) export LLVM_COMPILER=clang
3) make CXX=wllvm++ CXX_FLAGS="<old flags> -IreplacerIncludes" [OR] cmake CMAKE_C_COMPILER=wllvm++ CMAKE_CXX_COMPILER=wllvm++ CMAKE_CXX_FLAGS="<old flags> -IreplacerIncludes" (depending on type of project c/c++) 
[IMPORTANT: please redeclare your old flags in the <old flags> part as the flags stated within the make file will be overwritten] 
{the cmake command is untested we need to test it later}
4) extract-bc <path to executable file created in step 2> -l$LLVM_DIR/bin/llvm-link
5) llvm-dis <path to bc file created in step 3>

This will achieve a human readable file for the whole program
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
