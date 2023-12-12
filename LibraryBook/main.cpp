#include "LibraryBook.h"

int main()
{
    LibraryBook book1, book2, book3;
    book1.setter();
    book2.setter();
    book3.setter();
    const int a = book1.get_bookID();
    const int b = book2.get_bookID();
    const int c = book3.get_bookID();
    int key;
    int k;
    std::cout << "For checking out press 1: " << std::endl;
    std::cout << "For checking in press 2: " << std::endl;
    for(; std::cin >> k; )
    {
        if(k == 4)
        {
            break;
        }
        if(k == 1)
        {
            if(book1.get_availability() || book2.get_availability() || book3.get_availability())
            {
                std::cout << "The list of our books is" << std::endl;
                if(book1.get_availability())
                {
                    std::cout << "\"" << book1.get_title() << "\" with ID " << a << std::endl;
                }
                if(book2.get_availability())
                {
                    std::cout << "\"" << book2.get_title() << "\" with ID " << b << std::endl;
                }
                if(book3.get_availability())
                {
                    std::cout << "\"" << book3.get_title() << "\" with ID " << c << std::endl;
                }
                std::cout << std::endl;
                for(;std::cin >> key;)
                {
                    if( key == 4)
                    {
                        std::cout << "For checking out press 1: " << std::endl;
                        std::cout << "For checking in press 2: " << std::endl;
                        break;
                    }
                    switch(key)
                    {
                        case 1:
                        {
                            book1.checkOut();
                            break;
                        }
                        case 2:
                        {
                            book2.checkOut();
                            break;
                        }
                        case 3:
                        {
                            book3.checkOut();
                            break;
                        }
                    }
                }
            }
            else
            {
                std::cout << "There is no book" << std::endl << std::endl;
                break;
            }
        }
        if(k == 2)
        {
            std::cout << "Which book you want to check in" << std::endl;
            std::cout << "\"" << book1.get_title() << "\"" << std::endl << "\"" << book2.get_title() << "\"" << std::endl << "\"" << book3.get_title() << "\"" << std::endl;
            std::cout << "For \"" << book1.get_title() << "\" " << "enter " << a << std::endl;
            std::cout << "For \"" << book2.get_title() << "\" " << "enter " << b << std::endl;
            std::cout << "For \"" << book3.get_title() << "\" " << "enter " << c << std::endl;
            for(;std::cin >> key;)
            {
                if( key == 4)
                {
                    std::cout << "For checking out press 1: " << std::endl;
                    std::cout << "For checking in press 2: " << std::endl;
                    break;
                }
                switch(key)
                {
                    case 1:
                    {
                        book1.checkIn();
                        break;
                    }
                    case 2:
                    {
                        book2.checkIn();
                        break;
                    }
                    case 3:
                    {
                        book3.checkIn();
                        break;
                    }
                }
            }
        }
    }
    book1.displayInfo();
    book2.displayInfo();
    book3.displayInfo();
}
