#include<iostream>


struct node{
    int data;
    node *next;
} *front = nullptr, *rear = nullptr;


bool isEmpty(){
    if(front == nullptr){
        return true;
    }
    return false;
}

void enqueue(int n){
    node *temp = new node;
    temp->data = n;
    temp->next = nullptr;
    if(isEmpty()){
        front = rear = temp;
    }else{
        rear->next = temp;
        rear = temp;
    }
}

int dequeue(){
    int x = -1;
    if(isEmpty()){
        std::cout << "Queue is Empty\n";
        return x;
    }
    x = front->data;
    node *temp = front;
    front = front->next;
    delete temp;
    temp = nullptr;
    return x;
}
