#include <stdio.h>
#include <stdlib.h>

#include "book.h"

using namespace std;

template<size_t SIZE, class T> inline size_t array_size(T (&arr)[SIZE]) {
    return SIZE;
}

extern "C" int LLVMFuzzerTestOneInput(const u_int8_t* Data, size_t size) {
    if (size < 22) return 0;

    // reading data
    string author1 = {(char) Data[0], (char) Data[1], (char) Data[2], (char) Data[3], (char) Data[4]};
    string booktitle1 = {(char) Data[5], (char) Data[6], (char) Data[7]};
    string booktitle2 = {(char) Data[8], (char) Data[9], (char) Data[10]};

    string author2 = {(char) Data[11], (char) Data[12], (char) Data[13], (char) Data[14], (char) Data[15]};
    string booktitle3 = {(char) Data[16], (char) Data[17], (char) Data[18]};
    string booktitle4 = {(char) Data[19], (char) Data[20], (char) Data[21]};
    
    // building objects
    Author a1(author1);
    Book b1(booktitle1, a1);
    Book b2(booktitle2, a1);    

    Author a2(author2);
    Book b3(booktitle3, a2);
    Book b4(booktitle4, a2);    

    Book books[] = {b1, b2, b3, b4};
    
    Library lib(books);

    // calling function
    lib.findTitles("paulo", books, array_size(books));
    
    return 0;
}
