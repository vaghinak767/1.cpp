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
        return;
        std::cout << el << "---" << std::endl;
    }
    Node* ob = new Node;
    ob->data = el;
    Node* tmp = tail;
    Node* ptr = nullptr;
    while(tmp != nullptr && tmp->data > ob->data)
    {
        ptr = tmp;
        tmp =  tmp->small;
        std::cout << el << "---" << std::endl;
    }
    ob->great = ptr;
    ob->small = tmp;
    if(tmp != nullptr)
        tmp->great = ob;
    ob->previous = tail;
    ob->next = nullptr;
    tail = ob;  
}

void List::dis()
{
    Node* tmp = head;
    while(tmp->great != nullptr)
    {
        std::cout << tmp->data << " ";
        tmp = tmp->great;
    }
    std::cout << std::endl;
}
