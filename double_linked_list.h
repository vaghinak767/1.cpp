#include "node.h"

struct List
{
    public:
        List();
        ~List();
        List(const List& other);
        const List& operator=(const List& other); 
        List(List&& other);
        const List& operator=(List&& other);
        bool empty();
        void push_back(int el);
        void push_front(int el);
        void display_inc();
        void display_dec();
        void display();
        void erase(int pos);
        void erase(int first, int last);
    private:
        Node *head = nullptr;
        Node *tail = nullptr;
        Node *l_great = nullptr;
        Node *l_small = nullptr;
};
