#include <iostream>


        /*     * Inserting  in a sorted linkedlist*
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
        void Sortedinsert(int value);

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



// Inserting a value in a given  in sorted linked list
void linkedlist::Sortedinsert( int value){
    node* temp, *p = head, *q = nullptr; 
    temp = new node;
    temp->data = value;
    temp->next = nullptr;

    if(head == nullptr){
        head = temp;
    }else{
        while(p && p->data < value){
            q = p;
            p = p->next;
        }
        if(q == nullptr){
            temp->next = head;
            head = temp;
        }else{
            temp->next = q->next;
            q->next = temp;
        }
    }
}



int main()
{   
    linkedlist lin;
    lin.append(20);
    lin.append(30);
    lin.append(800);
    lin.Sortedinsert(10);
    lin.displayLoop();
   
}



            /*
                ANALYSIS:
                    -This function is O(n) in terms of time, because in worst case we traverse the entire list to find correct sorted position for new value.
                     Best case is O(1), when new value is smaller than head's data, since we insert directly at front without any traversal. 
                     Average and worst case are O(n), depending how far into sorted list the correct position lies.
                     
                    -Moreover, it only calls stack frame once (no recursion) and uses two pointers p and q, plus one pointer temp for new node.
                    -so this is O(1) in terms of space.
            */