#include<iostream>


    /*  QUEUE:
            Queue using Linked List:
                Implementing Queue using linked list is simple than anything else, what really a Queue is? it is FIFO, who enters first leaves first. 
                How much time does deleting head node of a linked list takes? constant time. so dequeue is actually deleting head node. O(1)
                Now, How much time does inserting at the end of a linked list takes? O(n) right, coz we need to traverse until reaching to end of list and then insert
                But can we reduce it to O(1)? as this is Queue, and there is only adding at the end exist, then we can reduce it to O(1). How?
                We take another pointer which is initially null, then, if list is empty, then front=rear=added node, else we will keep adding after rear, this way
                we always will have the track of the last node and we can simply add elements after that last node. VOOLLA, we have implemented the QUEUE using LL. 

                when empty? if front == null, then list is empty. 
                when full? as we know, a linked list does not have a fixed size, almost never it can not be full, but technically, when heap gets full and there is no
                space to allocate, then that means list is full. so its simple, node *temp = new node, if temp = nullptr then means heap is full. 

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




        /*  
            ANALYSIS:
                Both functions in here are O(1) in terms of time and space. the constructor also is O(1) while the desctrucot is O(n) which deletes nodes one by one. 

        
        */