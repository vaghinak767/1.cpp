#ifndef LIBRARY_H
#define LIBRARY_H
#include <iostream>
#include <vector>
#include "reader.h"
#include "book.h"

class Library
{
    private:
        std::vector<Book> books;
        std::vector<Reader> readers;
    public:
        void add_book(Book);
        void add_reader(Reader);
        bool find_book_by_title(std::string);
        bool find_reader_by_name(std::string);
        void issueBook(int, int);
        void returnBook(int, int);
        void list_of_book();
        void list_of_readers();
};

#endif