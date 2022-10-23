FLAGS="clang++ -S -c -emit-llvm"

FILES=`ls *.cpp`

find . -name "*.ll" -exec rm {} \;
find . -name "*.wpa" -exec rm {} \;
for file in ${FILES}
do
	file=${file%.*}
	echo ${file}
	$CLANGCPP ${FLAGS} -o check.bc ${file}.cpp
	wpa -ander -stat=false check.bc
done