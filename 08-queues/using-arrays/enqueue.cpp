#include <iostream>


        /*  
            QUEUES:
                Enqueue: Adding a value in Queue.
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

// Enqueue: Inserting value in queue
void Queue::enqueue(int x){
    if(rear == capacity-1){
        std::cout << "Queue is full\n";
        return;
    }
    rear++;
    A[rear] = x;
}


int main()
{
    Queue q1(5);
    q1.enqueue(10);

    return 0;
}




    /*
        ANALYSIS:
            DEQUEUE function is O(1) in both terms of time and space. As we can see, we just increment rear and add the value. There is no loop, and no other 
            extra works. 
    */