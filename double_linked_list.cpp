#include "double_linked_list.h"

List::List()
{
    head = nullptr;
    tail = nullptr;
}

List::~List()
{
    while(tail->previous != nullptr)
    {
        Node *tmp = tail;
        tail = tail->previous;
        delete[]tmp;
    }
}

List::List(const List& other)
{
    head = other.head;
    Node* tmp = head;
    while(tmp->next != nullptr)
    {
        Node *ob = new Node;
        ob->previous = tmp->previous;
        ob->next = tmp->next;
        ob->data = tmp->data;
        tmp = tmp->next;
    }
    tail = other.tail;
}

const List& List::operator=(const List& other)
{
    this->head = other.head;
    Node* tmp = other.head;
    while(tmp->next != nullptr)
    {
        Node *ob = new Node;
        ob->previous = tmp->previous;
        ob->next = tmp->next;
        ob->data = tmp->data;
        tmp = tmp->next;
    }
    this->tail = other.tail;
    return *this;
}

List::List(List&& other)
{
    head = other.head;
    Node* tmp = head;
    while(tmp->next != nullptr)
    {
        Node *ob = new Node;
        ob->previous = tmp->previous;
        ob->next = tmp->next;
        ob->data = tmp->data;
        tmp = tmp->next;
    }
    tail = other.tail;
    other.head = nullptr;
    other.tail = nullptr;
}

const List& List::operator=(List&& other)
{
    this->head = other.head;
    Node* tmp = head;
    while(tmp->next != nullptr)
    {
        Node *ob = new Node;
        ob->previous = tmp->previous;
        ob->next = tmp->next;
        ob->data = tmp->data;
        tmp = tmp->next;
    }
    this->tail = other.tail;
    other.head = nullptr;
    other.tail = nullptr;
    return *this;
}

bool List::empty()
{
    if(head == nullptr)
    {
        return true;
    }
    return false;
}

void List::push_back(int el)
{
    if(head == nullptr && tail == nullptr)
    {
        Node *ob = new Node;
        tail = ob;
        head = ob;
        ob->data = el;
        l_great = ob;
        l_small = ob;
        return;
    }
    Node* ob = new Node;
    ob->data = el;
    Node* tmp = l_great;
    Node* ptr = nullptr;
    while(tmp != nullptr && tmp->data > ob->data)
    {
        ptr = tmp;
        tmp =  tmp->small;
    }
    ob->great = ptr;
    ob->small = tmp;
    if(tmp != nullptr)
    {
        tmp->great = ob;
    }
    if(ptr != nullptr)
    {
        ptr -> small = ob;
    }
    ob->previous = tail;
    ob->next = nullptr;
    tail -> next = ob;
    tail = ob; 
    if(ob->great == nullptr) 
    {
        l_great = ob;
    }
    if(ob->small == nullptr)
    {
        l_small = ob;
    }
}

void List::push_front(int el)
{
    if(head == nullptr && tail == nullptr)
    {
        Node *ob = new Node;
        tail = ob;
        head = ob;
        ob->data = el;
        l_great = ob;
        l_small = ob;
        return;
    }
    Node* ob = new Node;
    ob->data = el;
    Node* tmp = l_great;
    Node* ptr = nullptr;
    while(tmp != nullptr && tmp->data > ob->data)
    {
        ptr = tmp;
        tmp =  tmp->small;
    }
    ob->great = ptr;
    ob->small = tmp;
    if(tmp != nullptr)
    {
        tmp->great = ob;
    }
    if(ptr != nullptr)
    {
        ptr->small = ob;
    }
    ob->previous = nullptr;
    ob->next = head;
    head -> previous = ob;
    head = ob; 
    if(ob->great == nullptr) 
    {
        l_great = ob;
    }
    if(ob->small == nullptr)
    {
        l_small = ob;
    }
}

void List::display()
{
    Node* tmp = head;
    while(tmp != nullptr)
    {
        std::cout << tmp->data << " ";
        tmp = tmp->next;
    }
    std::cout << std::endl;
}

void List::display_dec()
{
    Node* tmp = l_small;
    while(tmp != nullptr)
    {
        std::cout << tmp->data << " ";
        tmp = tmp->great;
    }
    std::cout << std::endl;
}

void List::display_inc()
{
    Node* tmp = l_great;
    while(tmp != nullptr)
    {
        std::cout << tmp->data << " ";
        tmp = tmp->small;
    }
    std::cout << std::endl;
}

void List::erase(int pos)
{
    Node *tmp = head;
    --pos;
    while(pos > 0)
    {
        tmp = tmp->next;
        --pos;
    }
    tmp->small->great = tmp->great;
    tmp->previous->next = tmp->next;
    tmp->great->small = tmp->small;
    tmp->next->previous = tmp->previous;
    delete tmp;
}

void List::erase(int first, int last)
{
    if(first >= last)
    {
        return;
    }
    if(l_great->data < first)
    {
        return;
    }
    Node *tmp = l_small;
    if(first > tmp->data)
    {
        while(tmp->data < first && first < tmp->great->data)
        {
            tmp = tmp->great;
        }
    }
    if(l_great->data < last - 1)
    {
        while(tmp)
        {
            tmp->small->great = tmp->great;
            tmp->previous->next = tmp->next;
            tmp->great->small = tmp->small;
            tmp->next->previous = tmp->previous;
            Node *ptr = tmp;
            first = tmp->great->data;
            tmp = tmp->great;
            delete ptr;
        }
        return;
    }
    while(first < last)
    {
        if(tmp->small && tmp->small->great)
            tmp->small->great = tmp->great;
        if(tmp->previous && tmp->previous->next)
            tmp->previous->next = tmp->next;
        if(tmp->great && tmp->great->small)
            tmp->great->small = tmp->small;
        if(tmp->next && tmp->next->previous)
            tmp->next->previous = tmp->previous;
        Node *ptr = tmp;
        tmp = tmp->great;
        if(!tmp)
        {
            delete ptr;
            return;
        }
        first = tmp->data;
        delete ptr;
    }
}
