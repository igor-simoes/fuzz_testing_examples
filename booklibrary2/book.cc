#include "book.h"

Author::Author(string const& _name) : name(_name) { }

Book::Book(string const& _name, Author const& _author) : name(_name), author(_author) { }

Library::Library(Book* _books) : books(_books) { }

Book* Library::findTitles(string const& name, Book* books, int size)
{
    

    return 0;
}
