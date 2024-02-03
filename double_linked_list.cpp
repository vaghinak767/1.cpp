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
    if(this == &other)
    {
        return *this;
    }
    this->clear();
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
    this->clear();
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
    }
    Node* ob = new Node;
    ob->previous = tail->next;
    ob->next = nullptr;
    ob->data = el;
    tail = ob;  
}

void List::clear()
{
    while(tail->previous != nullptr)
    {
        Node *tmp = tail;
        tail = tail->previous;
        delete[]tmp;
    }
    tail = nullptr;
    head = nullptr;
}
