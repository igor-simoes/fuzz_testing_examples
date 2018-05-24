#ifndef BOOK_H_   /* Include guard */
#define BOOK_H_

#include <string>

using namespace std;

class Author 
{    
public:
    string name;
    Author(string const& name);
};

class Book {
public:
    string name;
    Author author;
    Book(string const& name, Author const& auth);
};

class Library 
{
public:        
    Book* books;
    Library(Book* books);
    // Book* findTitles(string const& name, Book* books, int size);
};

#endif // BOOK_H_