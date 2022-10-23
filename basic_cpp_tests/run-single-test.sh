FLAGS="clang++ -S -c -emit-llvm"
#FLAGS="${FLAGS} -I../hollowSTL"
#FLAGS="-g ${FLAGS}"

file=$1


$CLANGCPP ${FLAGS} ${file} -o check.bc
wpa -ander -dump-callgraph check.bc

