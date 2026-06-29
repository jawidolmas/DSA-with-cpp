#include<iostream>
#include<fstream>

using namespace std;


/*A queue is implemented using a singly linked list.

Write a function:

int frontValue();

that returns the value stored at the front of the queue without removing it.

Then in main():

Enqueue(50)
Enqueue(60)
Enqueue(70)

Print front value.
Print entire queue.

Expected logical result:

Front value: 50

Queue:
50 60 70

Requirements:

Do not modify the queue.
Handle empty queue properly.
*/

struct node{
    int data;
    node* next;
};

node* front = nullptr;
node* rear = nullptr;


void enque(int data){

    node* newNode = new node;
    newNode->data = data;
    newNode->next = nullptr;
    if (front == nullptr){
        front = newNode;
        rear = newNode;
    }else{
    rear->next = newNode;
    rear = newNode;
    }

}

int frontvul(){

    if (front == nullptr){
        cout << "Queue is empty\n";
        return -1;
    }
    return front->data;
}

void print(){
    node* temp = front;
    while(temp != nullptr){
        cout << temp->data << " ";
        temp = temp->next;
    }
}



int main(){

    enque(20);
    enque(30);
    enque(40);
    print();
    cout << "\n The value of front: ";
    int x = frontvul();
    cout << x;
    return 0;
}

