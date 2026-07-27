#include<iostream>


class LinkedList{
    private: 
        int data;
        LinkedList *next;
    public:
        LinkedList();
        ~LinkedList();
        void display();



};

LinkedList::LinkedList(){
    data = 10;
    next = nullptr;
}

LinkedList::~LinkedList(){
    delete next;
}

void LinkedList::display(){
    std::cout << this->data;        
    LinkedList *p;
    p = this->next;
    while(p != nullptr){
        std::cout << p->data;
        p = p->next;
    }
}

int main()
{
    LinkedList l1;
    l1.display();   // O/P: 10
    return 0;
}