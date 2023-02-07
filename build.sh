which gcc &> /dev/null
if [ $? == 0 ]
then
    COMPILER=gcc
else
    echo gcc not found
    exit
fi

mkdir -p build
g++ -g main.cpp -o build/main.out
build/main.out