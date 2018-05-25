#include <stdio.h>
#include <stdlib.h>

#include "book.h"

using namespace std;

template<size_t SIZE, class T> inline size_t array_size(T (&arr)[SIZE]) {
    return SIZE;
}

extern "C" int LLVMFuzzerTestOneInput(const u_int8_t* Data, size_t size) {
    if (size < 7) return 0;

    // reading data
    char author1[4];
    author1[0] = (char) Data[0];
    author1[1] = (char) Data[1];
    author1[2] = (char) Data[2];
    author1[3] = '\0';

    char booktitle1[4];
    booktitle1[0] = (char) Data[3];
    booktitle1[1] = (char) Data[4];
    booktitle1[2] = (char) Data[5];
    booktitle1[3] = '\0';

    char booktitle2[4];    
    booktitle2[0] = (char) Data[6];
    booktitle2[1] = (char) Data[7];
    booktitle2[2] = (char) Data[8];
    booktitle2[3] = '\0';
    
    // building objects
    Author a(author1);
    Book b1(booktitle1, a);
    Book b2(booktitle2, a);    
    Book books[] = {b1};
    Library lib(books);

    // calling function
    lib.findTitles("paulo coelho", books, array_size(books));
    
    return 0;
}
