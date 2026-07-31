#include <iostream>
#include "linkedlist.hpp"

linkedlist::linkedlist(){
    head = nullptr;
}

linkedlist::~linkedlist(){
    node *current = head;
    while(current != nullptr){
        node *next = current->next;
        delete current;
        current = next;
    }
}

// length of nodes
int linkedlist::length() const{
    node *temp = head;
    int count = 0;
    while(temp != nullptr){
        count++;
        temp = temp->next;
    }
    return count;
}

// isEmpty
bool linkedlist::isEmpty() const{
    if(head == nullptr){
        return true;
    }
    return false;
}


// Display
void linkedlist::display() const{
    if(isEmpty()){
        std::cout << "List is empty\n";
        return;
    }
    node *temp = head;
    while(temp != nullptr){
        std::cout << temp->data << " ";
        temp = temp->next;
    }
    std::cout << std::endl;
}

// Clear List
void linkedlist::clearList() {
    node *temp = head;
    while(temp != nullptr){
        node* next = temp-> next;
        delete temp;
        temp = next;
    }
    head = nullptr;
}

// Prepend: insert at beginning
void linkedlist::prepend(int value){
    node *temp = new node;
    temp->data = value;
    if(isEmpty()){
        head = temp;
        temp->next = nullptr;
    }else{
        temp->next = head;
        head = temp;
    }
}

// append: insert at end
void linkedlist::append(int value){
    node *temp = new node;
    temp->data = value;
    temp->next = nullptr;
    if(isEmpty()){
        head = temp;
    }else{
        node *p = head;
        while(p->next != nullptr){
            p = p->next;
        }
        p->next = temp;
    }
}

// insert. 1-based
void linkedlist::insert(int index, int value){
    if(index < 0 || index > length()){
        std::cout << "Invalid index\n";
        return;
    }
    node *temp, *p = head;
    temp = new node;
    temp->data = value;
    temp->next = nullptr;
    if(index == 0){
        if(isEmpty()){
            head = temp;
        }else{
            temp->next = head;
            head = temp;
        }
    }else{
        for(int i = 0; i<index-1; i++){
            p = p->next;
        }
        if(p){
            temp->next = p->next;
            p->next = temp;
        }
    }
}

// Remove First
int linkedlist::removeFirst(){
    if(isEmpty()){
        return -1;
    }
    int x = 0;
    node *temp = head;
    head = head->next;
    x = temp->data;
    delete temp;
    temp = nullptr;
    return x;
}

// Remove Last
int linkedlist::removeLast(){
    if(isEmpty()){
        return -1;
    }
    int x = 0;
    if(head->next == nullptr){
        x = head->data;
        delete head;
        head = nullptr;
        return x;
    }
    node *temp = head, *p=nullptr;
    while(temp->next != nullptr){
        p = temp;
        temp = temp->next;
    }
    p->next = nullptr;
    x = temp->data;
    delete temp;
    temp = nullptr;
    return x;
}


// Delete at given index
int linkedlist::removeIndex(int index){
    if(index < 1 || index > length()){
        return -1;
    }
    int x = 0;
    node* temp = nullptr, *p = nullptr;
    if(index == 1){
        if(head->next == nullptr){
            x = head->data;
            delete head;
            head = nullptr;
            return x;
        }else{
            temp = head;
            head = head->next;
            x = temp->data;
            delete temp;
            temp = nullptr;
        }   
    }else{
        temp = nullptr, p = head;
        for(int i = 0; i < index-1; i++){
            temp = p;
            p = p->next;
        }
        if(p){
            temp->next = p->next;
            x = p->data;
            delete p;
            p = nullptr;
        }
    }
    return x;
}

// Linear Search
int linkedlist::linearSearch(int key) const{
    node *temp = head;
    if(isEmpty()){
        return 0;
    }
    while(temp != nullptr){
        if (temp->data == key){
            return 1;
        }
        temp = temp->next;
    }
    return 0;
}

// Get element at index
int linkedlist::getElement(int index) const{
    if(index < 0 || index >= length()){
        return -1;
    }
    node *temp = head;
    for(int i = 0; i<index; i++){
        temp = temp->next;
    }
    return temp->data;
}

// Set element ar index
void linkedlist::setElement(int index, int value){
    int x = 0;
    if(index < 0 || index >= length()){
        std::cout << "Invalid index\n";
        return;
    }
    node *temp = head;
    for(int i = 0; i<index; i++){
        temp = temp->next;
    }
    x = temp->data;
    temp->data = value;
    std::cout << x << " replaced with " << value << "\n";
}


// Reverse Iteratively: sliding pointers
void linkedlist::reverse(){
    node *p = head, *q = nullptr, *r = nullptr;
    while(p!=nullptr){
        r = q;
        q = p;
        p = p->next;
        q->next = r;
    }
    head = q;
}