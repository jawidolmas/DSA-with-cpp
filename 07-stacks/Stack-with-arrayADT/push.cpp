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

int main()
{
    StackArray stk(5);      // stack of capacity 5 created in heap. 
    stk.push(10);   


    return 0;
}




    /*  
        ANALYSIS:
            -The functions isEmpty, isFull, and length are all of them O(1) in both terms of time and space. Becuase they do only one check.

            -The function push in other hand is also O(1) in both time and space cases. It only checks if top is avalaible, then increments it and adds the value
             at the index where top points now. 
    */