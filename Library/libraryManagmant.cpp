#include "book.h"
#include "reader.h"
#include "library.h"
void Book::display()
{
    std::cout << "The book ID is: " << m_book_ID << std::endl;
    std::cout << "The author of book is: " << m_author << std::endl;
    if(m_status)
    std::cout << "The book is available" << std::endl;
    else
    std::cout << "The book is not available" << std::endl;
}

std::string Book::get_title()
{
    return m_title;
}

int Book::get_ID()
{
    return m_book_ID;
}

void Book::change()
{
    m_status ^= 1;
}

bool Book::get_status()
{
    return m_status;
}

void Reader::display()
{
    std::cout << "The reader name is: " << m_name << std::endl;
    std::cout << "The reader ID is: " << m_reader_id << std::endl;
    std::cout << "The issued books is: " << std::endl;
    for(Book item : m_issued_book)
    {
        std::cout << item.get_title() << std::endl;
    } 
}

std::string Reader::get_name()
{
    return m_name;
}

void Reader::issuebook(Book item)
{
    m_issued_book.push_back(item);
}

int Reader::get_id()
{
    return m_reader_id;
}

void Reader::returnB(int ID)
{
    int index = 0;
    for(Book item : m_issued_book)
    {
        if(ID == item.get_ID())
        {
            //m_issued_book.erase(index);
        }
        ++index;
    }
}

void Library::add_book(Book name)
{
    books.push_back(name);
}

void Library::add_reader(Reader reader)
{
    readers.push_back(reader);
}

bool Library::find_book_by_title(std::string title)
{
    for(Book item : books)
    {
        if(title == item.get_title())
        return true;
    }
    return false;
}

bool Library::find_reader_by_name(std::string name)
{
    for(Reader item : readers)
    {
        if(name == item.get_name())
        return true;
    }
    return false;
}

void Library::issueBook(int bookID, int readerID)
{
    for(Book item : books)
    {
        if(item.get_status())
        {
            bool find = false;
            for(Reader ite : readers)
            {
                if(readerID == ite.get_id())
                {
                    ite.issuebook(item);
                    find = true;
                    break;
                }
            }
            if(find)
            {
                std::cout << "The reader haven't been found" << std::endl;
            }

            if(bookID == item.get_ID())
            {
                item.change();
                break;
            }
        }
        else
        {
            std::cout << "This book is not available" << std::endl;
            return;
        }
    }
}

void Library::returnBook(int bookID, int readerID)
{
    int index = 0;
    for(Book item : books)
    {
        if(bookID == item.get_ID())
        {
            item.change();
            break;
        }
        ++index;
    }
    bool find = false;
    for(Reader ite : readers)
    {
        if(readerID == ite.get_id())
        {   
            ite.returnB(bookID);
            find = true;
            break;
        }
    }
    if(find)
    {
        std::cout << "The reader haven't been found" << std::endl;
        for(Book item : books)
        {
            if(bookID == item.get_ID())
            {
                item.change();
                break;
            }
        }
    }        
}

void Library::list_of_book()
{
    for(Book item : books)
    {
        bool av = item.get_status();
        std::cout << item.get_title();
        if(av)
        {
            std::cout << " - Available" << std::endl;
        }
        else
            std::cout << " - Not available" << std::endl;
    }
}

void Library::list_of_readers()
{
    for(Reader item : readers)
    {
        std::cout << item.get_name() << std::endl;
    }
}
