#include <iostream>


        /*  
            QUEUES:
              isFull and isEmpty
        */

class Queue{
    private:
        int *A;
        int capacity;       // Actaul capacity
        int front;        //   Front to handle dequeue
        int rear;        //    Rear to handle enqueue
    public:
        Queue(int cap);
        ~Queue();
        void enqueue(int x);
        int dequeue();
        bool isEmpty() const;
        bool isFull()  const;
};

// Constructor:
Queue::Queue(int cap){
    capacity = cap;
    A = new int[capacity];
    front = rear = -1;
}

//Destructor:
Queue::~Queue(){
    delete []A;
}

// IsEmpty    Time and Space: O(1)
bool Queue::isEmpty() const{
    if(front == rear){
        return true;
    }
    return false;
}

// isFull   Time and Space: O(1)
bool Queue::isFull() const{
    if(rear == capacity-1){
        return true;
    }
    return false;
}

// Enqueue: Inserting value in queue
void Queue::enqueue(int x){
    if(isFull()){
        std::cout << "Queue is full\n";
        return;
    }
    rear++;
    A[rear] = x;
}

// Dequeue: Deleting a value from Queue
int Queue::dequeue(){
    if(isEmpty()){
        return -1;  // Queue is empty
    }
    front++;
    int x = A[front];
    return x;
}


int main()
{
    Queue q1(5);
    q1.enqueue(10);
    std::cout << q1.dequeue();
    
    

    return 0;
}




    /*
        ANALYSIS:
            Both functions are O(1) in terms of time and space
    */