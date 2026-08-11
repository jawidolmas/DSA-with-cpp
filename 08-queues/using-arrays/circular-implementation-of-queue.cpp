#include <iostream>


        /*  
            QUEUES:
                Circular Queue Implementation:
                    We can implement Queue using single and double pointers, but there are some drawbacks we need to check them out. 
                    1. When we delete a value in a queue, the front will move forward, and this will lead us to not be able to reuse the indices that are deleted. 
                    2. When there are empty indices before front, then we cannot use them, similar to 1st case. 
                    3. We cannot use the Queue list itself again, coz when we delete all elements and the queue is full, the front will be equal to rear, so 
                    what condition check is front == rear ?, isnt it the condition is of when queue is empty? yean it is, then we cannot insert. means we cannot 
                    reuse the queue. 

                    There is two solutions:
                        1. Resetting: When front gets equal to rear, that means when front==rear, we will reset both of them back to -1 coz the queue is already empty.
                        Though this method solves 3rd case, but it does not guarantee anything for 1st and 2nd case. so we will go to second solution

                        2. CIRCULAR QUEUE: this is THE BEST POSSIBLE IMPLEMENTATION OF A QUEUE USING ARRAY. 
                        in this method, we move the rear and front circularly, and we get help from mod to move them both.
                        (rear + 1) % capacity = this will move rear circularly by one index. same for front. 
                        In this method, we start both front and rear initially at 0. coz we need to be able to move circularly.
                        As we do not use until rear gets to front, we can store in n size array, n-1 elements, if size = 5, we can store maximum 4 elements. 

                        Important statements:
                            1. isFull: if((rear+1)%capacity == front)
                            2. isEmpty: if(front == rear)
                            3. moving front: front+1 % capacity(means the whole size of array)
                            4. moving rear: rear+1 % capacity;
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

// Enqueue: Inserting value in queue
void Queue::enqueue(int x){
    if(isFull()){
        std::cout << "Queue is full\n";
        return;
    }
    rear = (rear + 1) % capacity;
    A[rear] = x;
}

// Dequeue: Deleting a value from Queue
int Queue::dequeue(){
    if(isEmpty()){
        return -1;  // Queue is empty
    }
    front = (front+1) % capacity;
    int x = A[front];
    return x;
}

// Display: In a circular method, we always remmember that we need to print values using a do while loop. 
void Queue::display() const{
    if(isEmpty()){
        std::cout << "Queue is empty\n";
        return;
    }
    int i = front+1;
    do{
        std::cout << A[i] << " ";
        i = (i + 1)%capacity;
    } while(i != (rear+1) % capacity);
    std::cout << std::endl;
}

int main()
{
    Queue q1(5);
    q1.enqueue(10);
    q1.enqueue(20);
    q1.enqueue(30);
    q1.enqueue(50);
    q1.enqueue(60);
    q1.display();

    return 0;
}

/*
    Output:
    Queue is full       Coz we can store only 4 elements in array sized 5.
    10 20 30 50 

*/



    /*
        ANALYSIS:
                All functions in Circular Method are O(1) except display. All functions do a few simple steps of work and done the job. 
                while the display traverses and prints the values of each index i visits until it gets on rear, which makes display O(n).
                All functions has O(1) complexity in terms of space.
    */