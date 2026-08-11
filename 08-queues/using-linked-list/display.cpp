#include<iostream>


    /*  QUEUE:
            Queue using Linked List:
                Display
    */


struct node{
    int data;
    node *next;
};

class Queue{
    private:
        node *front;
        node *rear;
    public:
        Queue();
        ~Queue();
        void enqueu(int x); 
        int dequeue();
        void display() const;
        bool isFull() const;
        bool isEmpty() const;
};

// Constructor
Queue::Queue(){
    front = rear = nullptr;
}

// Destructor
Queue::~Queue(){
    node *temp = front;
    while(temp != nullptr){
        node *next = temp->next;
        delete temp;
        temp = next;

    }
}

// isEmpty
bool Queue::isEmpty() const{
    if(front == nullptr){
        return true;
    }
    return false;
}

// isFull
bool Queue::isFull() const{
    node *temp = new node;
    if(temp == nullptr){
        return true;
    }
    delete temp;
    temp = nullptr;
    return false;
}

// Enqueue: inserting value
void Queue::enqueu(int x){
    if(isFull()){
        std::cout << "Queue is full\n";
        return;
    }
    node *temp = new node;
    temp->data = x;
    if(front == nullptr){
        front = rear = temp;
        temp->next = nullptr;
    }else{
        rear->next = temp;
        rear = temp;
    }
}

// Dequeue: Deleting from Queue
int Queue::dequeue() {
    if(isEmpty()){
        return -1;  // Queue is empty
    }
    node *temp = front;
    front = front->next;
    int x = temp->data;
    delete temp;
    temp = nullptr;
    return x;
}

// Display
void Queue::display() const{
    if(isEmpty()){
        std::cout << "Queue is empty\n";
        return;
    }
    node *temp = front;
    while(temp != nullptr){
        std::cout << temp->data << " ";
        temp = temp->next;
    }
    std::cout << std::endl;
}


int main()
{
    Queue q1;
    q1.enqueu(10);
    q1.enqueu(20);
    q1.enqueu(30);
    q1.enqueu(40);
    q1.display(); // 10 20 30 40
    q1.dequeue(); // removes 10.
    q1.display(); // 20 30 40  


}


        /*  
            ANALYSIS:
               Display is O(n) in terms of time, because it traverses all nodes one be one until it reaches null, and prints data parts of each node it visits. 
               Also, it is O(1) in terms of space. 

        
        */