#include <iostream>
#include <string>

class Student
{
    private:
        int id;
        std::string name;
        char mark;
        int grade;
    public:
        void setter();
        void display();
        void calculatgrade();
        int get_id();
        char get_mark();
        std::string get_name();
        int get_grade();
};