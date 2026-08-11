#include<iostream>


    /*  QUEUE:
            Double-ended Queues
                What they are? Doube Ended Queues which written as DEQueue are a type of implementing queue which strictly not follow the discipline of FIFO. 
                In this method, we can insert at front as well as at rear. At the same time, we can delete at front as well as at rear. 
                So this is not a complete strict FIFO, but it is QUeue.
                How we use it? when adding at rear, we increment rear and add value, same when deleting at rear, we delete and decrement rear. 
                same for front, when adding decrement front and when deleting increment front. 

                
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
        void enqueueRear(int x);
        int  dequeueRear();
        void enqueueFront(int x);
        int  dequeueFront();
        
        bool isEmpty() const;
        bool isFull()  const;
        void display() const;

};

// Constructor:
Queue::Queue(int cap){
    capacity = cap;
    A = new int[capacity];
    front = rear = 0;
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
    if((rear + 1) % capacity == front){
        return true;
    }
    return false;
}

// Enqueue Rear
void Queue::enqueueRear(int x){
    if(isFull()){
        std::cout << "Queue is full\n";
        return;
    }
    rear = (rear + 1) % capacity;
    A[rear] = x;
}
// Dequeue Rear
int Queue::dequeueRear(){
    if(isEmpty()){
        return -1;  // Queue is empty
    }
    int x = A[rear];
    rear = (rear - 1 + capacity) % capacity;
    return x;
}

// Enqueue Front
void Queue::enqueueFront(int x){
    if(isFull()){
        std::cout << "Queue is full\n";
        return;
    }
    A[front] = x;
    front = (front - 1 + capacity) % capacity;
}

// Dequeue Front
int Queue::dequeueFront(){
    if(isEmpty()){
        return -1;  // Queue is empty
    }
    front = (front+1) % capacity;
    int x = A[front];
    return x;
}



// Display
void Queue::display() const{
    if(isEmpty()){
        std::cout << "Queue is empty\n";
        return;
    }
    int i = (front+1) % capacity;
    do{
        std::cout << A[i] << " ";
        i = (i + 1)%capacity;
    } while(i != (rear+1) % capacity);
    std::cout << std::endl;
}

int main()
{
    Queue q1(5);
    q1.enqueueRear(10);
    q1.enqueueRear(20);
    q1.enqueueRear(30);
    q1.enqueueRear(50);
    q1.display();
    q1.dequeueRear();
    q1.display();
    q1.enqueueFront(60);
    q1.display();

    return 0;
}

