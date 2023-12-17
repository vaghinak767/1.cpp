#ifndef READER_H
#define READER_H
#include <iostream>
#include "book.h"
#include <vector>
class Reader
{
    private:
        int m_reader_id;
        std::string m_name;
        std::vector <Book> m_issued_book;
    public:
        Reader(int id, std::string name)
        {
            m_reader_id = id;
            m_name = name;
        }
        void display();
        void issuebook(Book);
        std::string get_name();
        int get_id();
        void returnB(int ID);
};

#endif