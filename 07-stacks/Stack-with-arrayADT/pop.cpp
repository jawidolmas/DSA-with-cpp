#include <iostream>


    /*  ***STACK***:

            Push: Adding a value in a stack
    */

class StackArray{
    private: 
        int *A;
        int capacity;       // The size of array
        int size;          //  Actual elements
        int top;          //   Points to top element. 
    public:
        StackArray(int cap);
        ~StackArray();
        bool isFull() const;
        bool isEmpty() const;
        int  length() const;
        void push(int x);
        int  pop();
};

// Constructor
StackArray::StackArray(int cap){
    capacity = cap;
    A = new int[cap];
    size = 0;
    top = -1;           // Array is empty. 
}

// Destructor
StackArray::~StackArray(){
    delete []A;
}

// isEmpty
bool StackArray::isEmpty() const{
    if(top == -1){
        return true;
    }
    return false;
}

// isFull
bool StackArray::isFull() const{
    if(top == capacity-1){
        return true;
    }
    return false;
}

// length
int StackArray::length() const{
    return size;
}

// Push
void StackArray::push(int x){
    if(isFull()){
        std::cout << "Stack Overflow\n";
        return;
    }else{
        top++;
        A[top] = x;
        size++;
    }
}

// Pop: deleting a value from top of a stack
int StackArray::pop(){
    int x = -1;             // We init it -1 coz if stack is empty, x should be -1 to return.
    if(isEmpty()){
        return -1;      // same as return x.
    }else{
        x = A[top];
        top--;
        size--;
    }
    return x;           
}



int main()
{
    StackArray stk(5);      // stack of capacity 5 created in heap. 
    stk.push(10);  



    return 0;
}




    /*  
        ANALYSIS:
            -The function pop is also O(1) in both time and space cases. It only checks if top has value, then takes value in x, decrements it and returns the value
            
    */