#include <stdio.h>
#include <stdlib.h>

#include "book.h"

extern "C" int LLVMFuzzerTestOneInput(const u_int8_t* Data, size_t size) {
    if (size < 7) return 0;

    char name1[4];
    name1[0] = (char) Data[0];
    name1[1] = (char) Data[1];
    name1[2] = (char) Data[2];
    name1[3] = '\0';
    struct author au = {name1};

    char title1[4];
    title1[0] = (char) Data[3];
    title1[1] = (char) Data[4];
    title1[2] = (char) Data[5];
    title1[3] = '\0';

    int numpages = Data[6];

    book book1 = {numpages, title1, au};

    // book* books = (book*) malloc(((int) sizeof(book) * 1));
    book books[1];
    books[0] = book1;

    // book* booksFromSilvio = 
    findTitles("sil", books, 1);

    return 0;
}
