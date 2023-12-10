#ifndef MAIN_H
#define MAIN_H
#include <iostream>
#include <string>
class LibraryBook
{
        int bookID;
        std::string title;
        std::string autor;
        bool isAvailable;
    public:
        void displayInfo();
        void checkOut();
        void checkIn();
        void setter();
        int get_bookID();
        std::string get_title();
        std::string get_autor();
        bool get_availability();
};
#endif
