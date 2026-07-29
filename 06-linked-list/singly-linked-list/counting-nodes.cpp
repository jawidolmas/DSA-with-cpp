#include <iostream>


        /*     *Counting Nodes*    */

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
        int countNodes();
        int countNodesRec(node *head);
        int count(){
           return countNodesRec(head);              // In order to be able to call countNodesRec() in main, we take a helper function, coz head is private memeber.
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

// Counting nodes of a list using loop
int linkedlist::countNodes(){
    int count = 0;
    node *temp = head;
    while(temp != nullptr){
        count++;
        temp = temp->next;
    }
    return count;
}


// Counting nodes of a list using recursion
int linkedlist::countNodesRec(node *head){
    if(head == nullptr){
        return 0;
    }
    return countNodesRec(head->next) + 1;
}

int main()
{   
    linkedlist lin;
    lin.append(20);
    lin.append(30);
    lin.append(40);
    lin.displayLoop();
    std::cout << lin.count();
}



            /*
                ANALYSIS:
                    *Using Loop: 
                        -This function is O(n) in terms of time, becuase we traverse each node one by one until we reach the last node, which it's next section is null.
                        -Moreover, this function gives us an advantage in terms of space, it only call stack frame once and it has one pointer head, and one variable count.
                        so this is O(1) in terms of space. 

                    *Using Recursion:
                        -This function is O(n) in terms of time, becuase it calls itself for n times, if n is 5, it calls 5 times, so, it depends on n. it runs until
                        the head becomes null, which means end of the list. 
                        -This function is also O(n) in terms of space, coz it calls n activation recalls on each call. The recursion always calls itself, so each function call
                        gets a stack frame and allocates space in stack. as a result, this is O(n) in terms of space. 
            
            */