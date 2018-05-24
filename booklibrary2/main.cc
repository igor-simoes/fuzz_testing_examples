#include <iostream>

#include "book.h"

using namespace std;

int main(int argc, char* argv[]) {
    Author a("paulo coelho");
    Book b("valquirias", a);
    Book books[] = {b};
    Library lib(books);
    cout << lib.books[0].name << " written by " << lib.books[0].author.name << endl;
    return 0;
}