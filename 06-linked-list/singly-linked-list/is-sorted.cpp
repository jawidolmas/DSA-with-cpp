#include <iostream>


        /*     * Deleting a value in first index or given index in a linked list*      */

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
        bool isSorted();

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


// Checking if a given list is sorted/not sorted.
bool linkedlist::isSorted(){
    node *temp = head;
    int x = INT_MIN;
    while(temp != nullptr){
        if(temp->data < x){
            return false;
        }
        x = temp->data;
        temp = temp->next;
    }
    return true;
}



int main()
{   
    linkedlist lin;
    lin.append(20);
    lin.append(10);
    lin.append(800);
    if(lin.isSorted()){                     // O/P: Not sorted
        std::cout << "Sorted\n";
    }else{
        std::cout << "Not Sorted\n";
    }
    lin.displayLoop();                                          
   
}



            /*
                ANALYSIS:
                    -This function is O(n) in terms of time, because in worst case we traverse the entire list to see if there is any value less than x. 
                     Best case is O(1), when head node's data is smaller than INT_MIN, since we detect it  directly at front without any traversal. 
                     Average and worst case are O(n), depending how far into list the if condition fails or succeeds
                     
                    -However, it only calls stack frame once (no recursion) and uses one pointer temp to hold head and do the actual traverse.
                    -so this is O(1) in terms of space.
            */