#include "main.h"

void LibraryBook::displayInfo()
{
    std::cout << "The book's ID is: " << bookID << std::endl;
    std::cout << "The title of book is \"" << title << "\"" << std::endl;
    std::cout << "The autor of book is \"" << autor << "\"" << std::endl;
    std::cout << "This book is ";
    if(isAvailable)
    {
        std::cout << "available" << std::endl;
    }
    else
        std::cout << "not available" << std::endl;
    std::cout << std::endl;
}
void LibraryBook::checkOut()
{
    if(isAvailable)
    {
        isAvailable = false;
        std::cout << "The " << title << " was checked out" << std::endl; 
    }
    else
    {
        std::cout << "This book is not available" << std::endl;
    }
}

void LibraryBook::checkIn()
{
   isAvailable = true;
   std::cout << "The book was checked in" << std::endl;
}

void LibraryBook::setter()
{
    std::cout << "Enter the book's ID: ";
    std::cin >> bookID;
    std::cout << "Enter the title of book: ";
    std::cin >> title;
    std::cout << "Enter the name of autor: ";
    std::cin >> autor;
    isAvailable = true;
}

int LibraryBook::get_bookID()
{
    return bookID;
}

std::string LibraryBook::get_autor()
{
    return autor;
}

std::string LibraryBook::get_title()
{
    return title;
}

bool LibraryBook::get_availability()
{
    return isAvailable;
}
