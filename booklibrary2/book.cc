#include <list>
#include <vector>
#include <string.h>
#include <iostream>

#include "book.h"

Author::Author(string const& _name) : name(_name) { }

Book::Book(string const& _name, Author const& _author) : name(_name), author(_author) { }

Library::Library(Book* _books) : books(_books) { }

Book* Library::findTitles(string const& name, Book* books, int size)
{
    std::list<Book> authorBooks = {};
    for (int i = 0; i < size; i++)
    {
        if (strcmp(name.c_str(), books[i].author.name.c_str()) == 0)
            authorBooks.push_back(books[i]);
    }
    if (authorBooks.size() == 0)
        return NULL;
    if (authorBooks.size() == 2)
        fprintf(stderr, "this is an artificial bug!");
        abort();        
    std::vector<Book> v{ std::begin(authorBooks), std::end(authorBooks) };
    return &v.at(0);
}
