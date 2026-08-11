#include <iostream>


        /*  
            QUEUES:
                Displaying elements of a Queue
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
        void display() const;

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

// Display
void Queue::display() const{
    if(isEmpty()){
        std::cout << "Queue is empty\n";
        return;
    }
    for(int i = 0; i<=rear; i++){
        std::cout << A[i] << " ";
    }
    std::cout << std::endl;
}

int main()
{
    Queue q1(5);
    q1.enqueue(10);
    q1.enqueue(20);
    q1.enqueue(30);
    q1.display();

    return 0;
}
    // O/P: 10 20 30 




    /*
        ANALYSIS:
            This function is O(n) in terms of time, as we can see, this function traverses the whole Queue, starts from 0th index and goes up to rear's index, and 
            while traversing, it prints the value of each index it visits. so this is definitely O(n).
            Furthermore, this function is O(1) in terms of time, we only have i assigned here. 
    */