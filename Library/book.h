#ifndef BOOK_H
#define BOOK_H
#include <iostream>

class Book
{
    private:
        int m_book_ID;
        std::string m_title;
        std::string m_author;
        bool m_status;
    public:
        Book(int id, std::string author, std::string title, bool status)
        {
            m_title = title;
            m_book_ID = id;
            m_author = author;
            m_status = status;
        }
        void display();
        std::string get_title();
        int get_ID();
        void change();
        bool get_status();
};

#endif

