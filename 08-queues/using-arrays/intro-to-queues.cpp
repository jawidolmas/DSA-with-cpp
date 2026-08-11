#include <iostream>


        /*  
            QUEUES:
                Queues are a logical data structure which has a discipline of FIFO(first in first out). That means, any element which enetered first will served or exits
                first. 
                We can see examples in stores where people create a line and served one by one, or a calling a center which has high-traffic and says: You are waiting on 
                Queue, that means, no one who called after you can served before you. 

                We can implement Queues in two physical methods of data structures, arrays and linked lists.

                1.Arrays: in arrays, we can implement Queues in different ways, but the most important thing is how fast we can do it? Can we use only one pointer to 
                implement a queue using array? OF COURSE WE CAN, we get a pointer of q and when insertion, we move q and insert in there, but what about deletion? 
                When deleting in Queue we need to delete the very first element which entered. that means, when we delete index[0], we need to move all other elements 
                in Queue by one index, which costs us time and is O(n). this method called as Queue using single-pointer. 

                Can we bring this O(n) to O(1)? YEAH, using two pointers, we take two pointers(front & rear) and put both of them at very front, init them to -1. After that, 
                we can add normally as incrementing rear and add value. but here is the change while deleting: the FRONT pointer does not point to the first element, but one index
                before first element. SUPPOSE: you are in a store and there is a line and a counter doing the sales there, if counter serves the very first person, then 
                moving all customers ahead OR moving counter one step near to closest customer, which one is more fast? moving n person or moving 1 person? OF COURSE 
                it is an example, we dont move the all POS and table of counter one step ahead. HAHAHAHA. 

                visual: C = counter,  P = Customers
                        C   <-P1 <-P2 <-P3 <-P4, so in here, when P1 served, we can simply move C near to P2 so they can come face to face and handle the sales. right?
                        EXACTLY, THE FRONT IN QUEUE POINTS TO COUNTER, WHEN WE DELETE ON ELEMENT, WE SIMPLY MOVE THE FRONT(COUNTER) BY ONE INDEX. THAT'S IT...

                SEEEEE, We reduced the O(n) to O(1) by only one more pointer. this method is called Queue using double-pointer. so we will impelement using this method. 

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

