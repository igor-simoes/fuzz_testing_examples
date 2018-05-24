#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "book.h"

book* findTitles(const char* author, book* books, int size) {
    int num = 0;
    // find number of books for a given author
    for (int i = 0; i < size; i++)
    {
        if (strcmp(author, books[i].author.name) == 0)
            num++;
    }
    book* titles = (book*) malloc(sizeof(book) * num);
    int j = 0;
    for (int i = 0; i < size; i++)
    {
        if (strcmp(author, books[i].author.name) == 0)
            titles[j++] = books[i];
    }
    return titles;
}
