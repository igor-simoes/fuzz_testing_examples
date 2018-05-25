#!/bin/bash

echo "using compiler $CXX"

function compile() {
    NAME="$1"
    (
        cd ${NAME}
        #$CXX -Wall -g -fsanitize=fuzzer,address *.cc *.c -o ${NAME}_target.out
        $CXX -Wall -g -fsanitize=fuzzer *.cc -o ${NAME}_target.out -lstdc++
        mkdir -p corpus
        ./${NAME}_target.out -runs=10000 corpus
    ) # leave directory
}


#compile "bubblesort"
#compile "booklibrary"
compile "booklibrary2"
