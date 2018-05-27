#include <iostream>

#include "book.h"

using namespace std;

template<size_t SIZE, class T> inline size_t array_size(T (&arr)[SIZE]) {
    return SIZE;
}

int main(int argc, char* argv[]) {

    // reading data
    string author1("marcelo");
    string booktitle1("paper1");
    string booktitle2("paper2");    

    string author2("fernanda");
    string booktitle3("paper3");
    string booktitle4("paper4");    

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
    Book* titles = lib.findTitles("marcelo", books, array_size(books));
    if (titles)
        cout << "there are books associated with this author" << endl;
}
