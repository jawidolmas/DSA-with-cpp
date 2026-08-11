#include<iostream>


    /*  QUEUE:
            Using Two Stack
                 We can enqueu and dequeue using two stack, that works because we will push all elements to the stack, we will enqueue(push(x)) and when we want 
                 to delete, we will transfer them to second stack and then pop them out of that stack and return the value, this way we can use 2 stacks to actually
                 implement a QUEUE. 
    */

// Stack Class
   
class Stack{
    private:
        int *A;
        int capacity;
        int size;
        int top;
    public:
        Stack(){}
        Stack(int cap){
            capacity = cap;
            A =  new int[capacity];
            size = 0;
            top = -1;
        }
        ~Stack(){
            delete []A;
        }
        bool isEmpty() const{
            if(top == -1){
                return true;
            }
            return false;
        }
        bool isFull() const{
            if(top == capacity-1){
                return true;
            }
            return false;
        }
        void push(int value){
            if(isFull()){
                std::cout << "Stack is Full\n";
                return;
            }
            top++;
            A[top] = value;
            size++;
        }
        int pop(){
            if(isEmpty()){
                return -1; // stack is empty
            }
            int x = A[top];
            top--;
            size--;
            return x;
        }
        void display() const{
            if(isEmpty()){
                std::cout << "Stack is Empty\n";
                return;
            }
            for(int i = 0; i <= top; i++){
                std::cout << A[i] << " ";
            }
            std::cout <<"\n";
        }
};


// Queue Class

class Queue{
    private:      
        Stack q1, q2;
    public:
        Queue(int cap);
        ~Queue();
        void enqueue(int x);
        int  dequeue();
        
        bool isEmpty() const;
        bool isFull()  const;
        void display();

};

// Constructor:
Queue::Queue(int cap) : q1(cap), q2(cap) {}

// Destructor
Queue::~Queue(){}

// Enqueue
void Queue::enqueue(int value){
    q1.push(value);
}

// Dequeue
int Queue::dequeue(){
    if(q2.isEmpty()){
        while(!q1.isEmpty()){
            q2.push(q1.pop());
        }
    }
    if(q2.isEmpty()){
        return -1;
    }
    return q2.pop();
}


// Display
void Queue::display(){
    if(q1.isEmpty() && q2.isEmpty()){
        std::cout << "Queue is empty\n";
        return;
    }
    while(!q1.isEmpty()){
        q2.push(q1.pop());
    }
    while(!q2.isEmpty()){
        int x = q2.pop();
        std::cout << x << " ";
        q1.push(x);
    }
    std::cout << "\n";
}

int main()
{
    Queue q1(5);
    q1.enqueue(10);
    q1.enqueue(20);
    q1.enqueue(30);
    q1.display();
    q1.dequeue();
    q1.dequeue();
    q1.dequeue();
    q1.display();

    return 0;
}

