
#ifndef STACK_HPP
#define STACK_HPP

#include <iostream>
#include "Queue.hpp"

// We need to create a stack in order to traverse a tree without using recursion. Otherwise than stack, we cannot use traversal in iterative way.




class StackArray{
    private: 
        node **A;
        int capacity;       
        int size;          
        int top;          
    public:
        StackArray(int cap);
        ~StackArray();
        bool isEmpty() const;
        bool isFull() const;
        void push(node* x);
        node*  pop();
};

// Constructor
StackArray::StackArray(int cap){
    capacity = cap;
    A = new node*[cap];
    size = 0;
    top = -1;           
}

// Destructor
StackArray::~StackArray(){
    delete []A;
}

// isEmpty
bool StackArray::isEmpty() const{
    if(top == -1){
        return true;
    }
    return false;
}
// isFull
bool StackArray::isFull() const{
    if(top == capacity -1){
        return true;
    }
    return false;
}

// Push
void StackArray::push(node* x){
    if(isFull()){
        std::cout << "Stack Overflow\n";
        return;
    }else{
        top++;
        A[top] = x;
        size++;
    }
}

// Pop
node* StackArray::pop(){
    node* x = nullptr;           
    if(isEmpty()){
        return nullptr;      
    }else{
        x = A[top];
        top--;
        size--;
    }
    return x;           
}

#endif