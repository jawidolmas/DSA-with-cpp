#include <iostream>
using namespace std;

    /*  ***STACK***:

            Full program of stack using Array ADT
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
        int  peek(int index) const;
        int  stackTop() const;
        void display() const;
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

// Peek: searching for a value in given index
int StackArray::peek(int index) const{
    int x = -1;
    if(isEmpty()){
        return -1;
    }
    else{
        if((top - index)+1 < 0){
            return x;
        }else{
            x = A[top-index + 1];
        }
    }
    return x;
}

// Stack Top: top value of a stack
int StackArray::stackTop() const{
    if(isEmpty()){
        return -1;
    }else{
        return A[top];
    }
}

// display
void StackArray::display() const{
    if(isEmpty()){
        cout << "Stack is empty\n";
    }
    for(int i = 0; i < size; i++){
        cout << A[i] << " ";
    }
    cout << endl;
}
int main()
{   
    int choice, x, index;
    StackArray stk(5);      // stack of capacity 5 created in heap. 
    do{
    cout << "1. Push\n";
    cout << "2. Pop\n";
    cout << "3. Peek\n";
    cout << "4. Stack Top\n";
    cout << "5. Display\n";
    cout << "6. Exit\n";

    
    cout << "Enter your choice: ";
    cin >> choice;
    switch(choice){
        case 1:
            cout << "Enter data to push:";
            cin >> x;
            stk.push(x);
            break;
        case 2: {
            int val = stk.pop();
            if(val == -1){
                cout << "Stack is empty\n";
            } else {
                cout << val << " deleted\n";
            }
            break;
        }
        case 3:
            cout  << "Enter index of peek:";
            cin >> index;
            if(stk.peek(index) == -1) cout << "Not Found\n";
            else cout << stk.peek(index) << " Found\n";
            break;
        case 4:
            if(stk.stackTop() == -1) cout << "Empty stack\n";
            else cout << stk.stackTop() << " is top of stack\n";
            break;
        case 5:
            stk.display();
            break;
        case 6:
            cout << "Exiting program\n";
            return 0;
            break;
        default:
            cout << "Invalid choice\n";
    }
    }while(choice != 6);
    return 0;
}



// All functions in this program is O(1) in both time and space terms, except display which is O(n). 