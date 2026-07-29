#include <iostream>


        /*     *Searching for a key in a linked list* 
                    -We have two ways to search a list, at least as of now for my knowledge. 
                    1. Linear Search: A search that visits each node and checks if key is there or not. 
                    2. Binary Search: A search that splits a sorted list in two two and goes for finding in that binary list. For binary list, we need to first know where the 
                    middle is. so how we can know the middle of a linked list? can we put a pointer or even a varaible like int j = size-1? NO. becuase linked list
                    lives in heap and the address is not contingous. for that purpose, we again need to traverse all of the list to find where the middle of list is. 
                    so why would do we use the binary search? coz of it's effeciency, do you think, in linked list, it is also effecient? no, coz we need to traverse
                    on each breaking of list, one by one until key found/not found. so BINARY SEARCH IS NOT SUITABLE FOR LINKED LIST. 
        */

struct node{
    int data;
    node* next;
};

class linkedlist{
    private:
        node* head;
    public:
        linkedlist();
        ~linkedlist();
        void append(int value);
        void displayLoop();
        int  loopSearch(int key);
        int  recursionSearch(node *head, int key);
        int  search(int key){
           return recursionSearch(head, key);              // In order to be able to call recursionSum() in main, we take a helper function, coz head is private memeber.
        }
};


// Constructor

linkedlist::linkedlist(){
    head = nullptr;
}

//Destructor
linkedlist::~linkedlist(){
    node* current = head;
    while(current != nullptr){
        node* next = current->next;
        delete current;
        current = next;
    }
}

// Adding data to end of list                   
void linkedlist::append(int value){
    node *p = new node;
    p->data = value;
    p->next = nullptr;

    if(head == nullptr){
        head = p;
    }else {
    node *temp = head;
    while(temp->next != nullptr){
        temp = temp->next;
    }
    temp->next = p;
    }
}

// Display using loop
void linkedlist::displayLoop(){
    if(head == nullptr){
        std::cout << "List is empty\n";
        return;
    }
    node *temp = head;
    while(temp != nullptr){
        std::cout << temp->data << " ";
        temp = temp->next;
    }
}

// Searching for key in a linked list using loop
int linkedlist::loopSearch(int key){
        node *temp = head;
        while(temp != nullptr){
            if(key == temp->data){
                return 1;
            }
            temp = temp->next;
        }
        return 0;
}


// Searching for key in a list using recursion
int linkedlist::recursionSearch(node *head, int key){
    if(head == nullptr){
        return 0;
    }
    if(key == head->data){
        return 1;
    }
    return recursionSearch(head->next, key);
}

int main()
{   
    linkedlist lin;
    lin.append(20);
    lin.append(30);
    lin.append(800);
    lin.displayLoop();
    std::cout << lin.loopSearch(800);     // O/P: 1
    std::cout << lin.search(10);     // O/P: 0
}



            /*
                ANALYSIS:
                    *Using Loop: 
                        -This function is O(n) in terms of time, becuase we traverse each node one by one until it finds the key, it can be O(1) in best case and 
                        O(n) in average case as well as O(n) in worst case.
                        -Moreover, this function gives us an advantage in terms of space, it only call stack frame once and it has one pointer temp,  and one variable
                        key.
                        so this is O(1) in terms of space. 

                    *Using Recursion:
                        -This function is O(n) in terms of time, becuase it calls itself for n times, if n is 5, it calls 5 times, so, it depends on n. it runs until
                        the key found or not in list at all, which means end of the list and then returns 0/1 and clears the stack frame. 
                        -This function is also O(n) in terms of space, coz it calls n activation recalls on each call. The recursion always calls itself, so each function call
                        gets a stack frame and allocates space in stack. as a result, this is O(n) in terms of space. 
            
            */