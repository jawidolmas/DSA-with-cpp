#include <iostream>
using namespace std;

    /*  ***STACK***:
                -Stack using linked list. 
                - A few things we need to know:
                    -In here, we use to insert at 0th index so we can catch O(1), in all operations. we push, pop,... at first and top will be first node.
                    -In linked list, when the list will be full? we can get as much as we want but when the heap is full, there is no more memory, then it means
                     list is full. so coz of that, we take a new node, if that node remains null, then heap is full. 
                    -When then is it empty? simple, when top is nullptr, then it is empty.
    */

struct node{
    int data;
    node *next;
};

class stackLL{
    private: 
        node *top;
    public:
        stackLL();
        ~stackLL();
        bool isFull() const;
        bool isEmpty() const;
        void push(int x);
        int  pop();
        int  peek(int index) const;
        int  stackTop() const;
        void display() const;
};

// Constructor
stackLL::stackLL(){
    top = nullptr;
}

// Destructor
stackLL::~stackLL(){
    node *current = top;
    while(current != nullptr){
        node *next = current->next;
        delete current;
        current = next;
    }
}

// IsEmpty
bool stackLL::isEmpty() const{
    if(top == nullptr){
        return true;
    }
    return false;
}

// isFull
bool stackLL::isFull() const{
    node *temp = new node;
    if(temp == nullptr){
        return true;
    }
    else{
        return false;
    }
    delete temp;
    temp = nullptr;
}


// Push
void stackLL::push(int value){
    if(isFull()){
        cout << "Stack Overflow\n";
        return;
    }
    node *temp = new node;
    temp->data = value;
    temp->next = top;
    top = temp;
}

// Pop
int stackLL::pop(){
    int x;
    if(isEmpty()){
        return -1;
    }
    node *temp = top;
    top = top->next;
    x = temp->data;
    delete temp;
    temp = nullptr;
    return x;
}



int main()
{   
    stackLL stk;
    stk.push(10);
    cout << stk.pop();

    return 0;
}



