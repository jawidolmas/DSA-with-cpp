#include<iostream>


    /*  QUEUE:
            Queue using Linked List:
                Enqueue: Inserting data to queue

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



int main()
{
    Queue q1;
    q1.enqueu(10);
    q1.enqueu(20);
    q1.enqueu(30);
    q1.enqueu(40);

}


        /*  
            ANALYSIS:
               Enqueue is O(1) in terms of time and space, which we only add at first or at end, which rear pointer gives as an advantage to insert at end
               with only one step of work. 

        
        */