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

Legacy option

1) export LLVM_DIR=/usr/lib/llvm-12       (or whatever your path to llvm is)
2) export LLVM_COMPILER=clang
3) make CXX=wllvm++ CXX_FLAGS="<old flags> -Isimplestl" [OR] cmake CMAKE_C_COMPILER=wllvm++ CMAKE_CXX_COMPILER=wllvm++ CMAKE_CXX_FLAGS="<old flags> -Isimplestl" (depending on type of project c/c++) 
[IMPORTANT: please redeclare your old flags in the <old flags> part as the flags stated within the make file will be overwritten] 
{the cmake command is untested we need to test it later}
4) extract-bc <path to executable file created in step 2> -l$LLVM_DIR/bin/llvm-link
5) llvm-dis <path to bc file created in step 3>

This will achieve a human readable file for the whole program

Automated option

1) Run main.py
2) Enter the link to your GitHub project
3) Follow the steps by the program for the paths to necessary dependencies (Simplified-STL folder and LLVM folder)
4) The resulting whole program bitcode file will be in the "build" folder named "result"

```

## Reduce a whole program LLVM IR - The LLVM Pass Approach

We have also developed an LLVM Pass to obtain a simplified LLVM IR. The LLVM Pass does the following:
 - Loops through the module and demangles the name of the functions, identifying those with an "stl" prefix which indicates these functions are from the C++ Standard Library
 - Removes the call chain that this function dumps

To build the pass:
```
mkdir build
cd build
cmake ..
make
export $LLVM_DIR=<llvm path>
$LLVM_DIR/bin/opt -enable-new-pm=0 -load ./ReduceIRPass/libReduceIRPass.so -legacy-reducer-pass -S <path to test file> -o out.ll

The pass is registered through the LLVM legacy pass manager
```
Users can run main.py to obtain the whole program LLVM that they want to feed into the ReduceIRPass

## References
All class templates were obtained from: https://en.cppreference.com/w/cpp/header and https://www.cplusplus.com/reference/stl/

