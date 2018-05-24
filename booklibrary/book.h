#ifndef BOOK_H_   /* Include guard */
#define BOOK_H_

typedef struct author {
    char const *name;
} author;

typedef struct book {
    int numpages;
    char const *title;
    author author;
} book;

book* findTitles(const char* author, book* books, int size);

#endif // BOOK_H_
