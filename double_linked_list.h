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
        void push_front(int el)
    private:
        Node *head = nullptr;
        Node *tail = nullptr;
};