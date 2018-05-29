#!/bin/bash

echo "using compiler $CXX"

function compile() {
    NAME="$1"
    SOURCES="$2"
    (
        cd ${NAME}

        # compiling
        for x in $SOURCES
        do
            $CXX -Wall -g -fsanitize=fuzzer -c $x
        done

        # linking
        $CXX -Wall -g -fsanitize=fuzzer,address ${SOURCES} -o target.out
        # removing object files; leaving executable
        rm *.o

        # running
        mkdir -p corpus
        ./target.out -runs=10000 corpus
    ) # leave directory
}


compile "bubblesort" "bubblesort.c bubblesort_target.cc"
compile "booklibrary" "book.c booklibrary_target.cc"
compile "booklibrary2" "book.cc booklibrary_target.cc"
compile "bank" "bank.cc bank_target.cc"
