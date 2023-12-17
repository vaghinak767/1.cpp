#include "library.h"

int main()
{
    Library bookinist;
    Book barev(1, "gev", "barev", true);
    Book bare(2, "gev", "bare", true);
    bookinist.add_book(barev);
    bookinist.add_book(bare);
    Reader Armen(1, "Armen");
    bookinist.add_reader(Armen);
    bookinist.issueBook(1, 1);
    bookinist.issueBook(2, 1);
    bookinist.returnBook(2, 1);
    bookinist.list_of_book();
    
}