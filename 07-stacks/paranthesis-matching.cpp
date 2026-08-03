#include <iostream>
using namespace std;

    /*  ***STACK***:
                    APPLICATIONS OF STACK:
                    Paranthesis matching: checking if for each opening paranthesis, there is a closing paranthesis. 
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
        void display() const;
        void paranthesisMatch(char *A);
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

// Paranthesis matching
void stackLL::paranthesisMatch(char *A){
    for(int i = 0; A[i]!='\0'; i++){
        if(A[i] == '('){
            push(A[i]);
        }else if(A[i] == ')'){
            if(isEmpty()) {
             cout << "Paranthesis not matched\n";
             return;
            }
            pop();
        }   
    }
    if(isEmpty()){
        cout << "Paranthesis Matched\n";
    }
    else{
        cout << "Paranthesis not Matched\n";
    }
}

int main()
{   
    stackLL stk;
    char A[] = "(a+b) * (   (b+c)";
    stk.paranthesisMatch(A);        

    return 0;
}



// This function is O(n) in terms of time, coz it scans all the characters in that char array, then does a few operations.
// Moreover, this function is O(1) in terms of space. 