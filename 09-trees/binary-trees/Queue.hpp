#include <iostream>

class node{
public:
    node *lchild;
    int data;
    node *rchild;
};


class Queue{
    private:
        node **A;
        int capacity;      
        int front;        
        int rear;        
    public:
        Queue(int cap);
        ~Queue();
        void enqueue(node *p);
        node* dequeue();
        bool isEmpty() const;
};

// Constructor:
Queue::Queue(int cap){
    capacity = cap;
    A = new node*[capacity];
    front = rear = -1;
}

//Destructor:
Queue::~Queue(){
    delete []A;
}

// Enqueue: Inserting value in queue
void Queue::enqueue(node *p){
    if(rear == capacity-1){
        std::cout << "Queue is full\n";
        return;
    }
    rear++;
    A[rear] = p;
}

// Dequeue: Deleting a value from Queue
node* Queue::dequeue(){
    node *x = nullptr;
    if(front == rear){
        return nullptr;  // Queue is empty
    }
    x = A[front+1];
    front++;
    return x;
}

// IsEmpty    Time and Space: O(1)
bool Queue::isEmpty() const{
    if(front == rear){
        return true;
    }
    return false;
}