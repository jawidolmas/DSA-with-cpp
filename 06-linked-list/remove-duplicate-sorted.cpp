#include <iostream>


        /*     * Deleting duplicated values in a sorted linked list*      */

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
        void removeDuplicate();

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


// Removing duplicates from sorted list
void linkedlist::removeDuplicate(){
    node *p = head, *q = head->next;
    int x = 0, repeated = 0; 
    while(q != nullptr){
        if(p->data != q->data){
            p = q;
            q = q->next;
        }
        else{
            p->next = q->next;
            x = q->data;
            delete q;
            q = p->next;
            repeated++;
        }
    }
    std::cout << x << " duplicated " << repeated << " more time(s) and duplicate(s) deleted\n";

}



int main()
{   
    linkedlist lin;
    lin.append(10);
    lin.append(10);
    lin.append(20);
    lin.removeDuplicate();      // O/P: 10 repeated 1 more time(s) and duplicate(s) deleted
    lin.displayLoop();                                          
   
}



            /*
                ANALYSIS:
                    -This function is O(n) in terms of time, because in worst case we traverse the entire list to see if there is any duplicated data. 
                     Best case is O(1), when head node's data is equal to next node data, and it is the only duplication in the list,  since we detect it directly
                     and delete the duplicate at front in one iteration. 
                     Average and worst case are O(n), depending how much duplicates exist or not exist at all. 
                     
                    -However, it only calls stack frame once (no recursion) and uses 2 pointers p, q to compare the data parts and q helps in deleting duplicated data. 
                    -so this is O(1) in terms of space.
            */