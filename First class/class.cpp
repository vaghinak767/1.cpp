#include "class.h"

void Student::display()
{
    std::cout << "The student's ID is: " << id << std::endl;
    std::cout << "The student's name is " << name << std::endl;
    std::cout << "The student's mark is: " << mark << std::endl;
    std::cout << "The student's drage is: " << grade << std::endl;
}

void Student::calculatgrade()
{
    if(grade <= 10)
    {
        mark = 'E';
        return;
    }
    if(grade <= 20)
    {
        mark = 'D';
        return;
    }
    if(grade <= 30)
    {
        mark = 'C';
        return;
    }
    if(grade <= 40)
    {
        mark = 'B';
        return;
    }
    if(grade <= 50)
    {
        mark = 'A';
        return;
    }
}
void Student::setter()
{
    std::cout << "Enter the student's ID: ";
    std::cin >> id;
    std::cout << "Enter the student's name: ";
    std::cin >> name;
    std::cout << "Enter the student's garde: ";
    std::cin >> grade;
    Student::calculatgrade();
}

int Student::get_id()
{
    return id;
}

std::string Student::get_name()
{
    return name;
}

char Student::get_mark()
{
    return mark;
}

int Student::get_grade()
{
    return grade;
}

int main()
{
    Student A;
    A.setter();
    A.display();
}
