#include <iostream>


        /*  
            QUEUES:
                Dequeue: Deleting a vlaue from Queue: 
                    As we know, in arrays, while deleting a value, the real deletion will not happen, we only suppose that the deleted value wont show in display 
                    and we act as deleted on it. The value will be in that index and still allocate memory. if we really want to get rid of that value then we can
                    assign 0 to it, so the index seems empty; 
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
        int dequeue();
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



// Dequeue: Deleting a value from Queue
int Queue::dequeue(){
    if(front == rear){
        return -1;  // Queue is empty
    }
    front++;
    int x = A[front];
    return x;
}


int main()
{
    Queue q1(5);
    std::cout << q1.dequeue();      // O/P: -1 coz Queue is empty

    return 0;
}




    /*
        ANALYSIS:
            DEQUEUE function is O(1) in both terms of time and space. As we can see, we just increment front and get the value in x and return it, there 
            wont be a real deletion happen physically. Also, we dont need any loop or extra work to find the wanted value, the front gives it us by one incremention. 
    */