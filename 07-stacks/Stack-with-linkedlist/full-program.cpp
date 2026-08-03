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

// Peek     O(n) it time. O(1) in space
int stackLL::peek(int index) const{
    if(isEmpty()){
        return -1;
    }else{
        node *temp = top;
        for(int i = 0; temp != nullptr && i < index-1; i++){
            temp = temp->next;
        }
        if(temp != nullptr){
            return temp->data;
        }else{
            return -1;
        }
    }

}

// stack top
int stackLL::stackTop() const{
    if(isEmpty()){
        return -1;
    }
    else{
        return top->data;
    }
}

// display
void stackLL::display() const{
    if(isEmpty()){
        cout << "Stack is empty\n";
        return;
    }
    node *temp = top;
    while(temp != nullptr){
        cout << temp->data << " ";
        temp = temp->next;
    }
    cout << endl;
}

int main()
{   
    int choice, x, index;
    stackLL stk;      // stack of capacity 5 created in heap. 
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



// All of these functions are O(1) in terms of time as well as space, except display and peek fucntion, which they are O(n) in terms of time, O(1) in terms of space. 
// Destructor also takes a time of O(n).