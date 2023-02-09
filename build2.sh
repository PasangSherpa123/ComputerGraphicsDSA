which gcc &> /dev/null
if [ $? == 0 ]
then
    COMPILER=gcc
else
    echo gcc not found
    exit
fi
g++ -g main2.cpp -o build/main2.out
build/main2.out