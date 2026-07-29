#include <iostream>


        /*     * Inserting *
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
        int countNodes();
        void insert(int pos, int value);

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

//count node
int linkedlist::countNodes(){
    int count = 0;
    node *temp = head;
    while(temp != nullptr){
        count++;
        temp = temp->next;
    }
    return count;
}




// Inserting a value in a given position in linked list
void linkedlist::insert(int pos, int value){
    int length = countNodes();
    if(pos < 0 || pos > length){
        std::cout << "Position index is invalid\n";
        return;
    }
    node *temp = new node;                      // For adding new value
    if(pos == 0){                       // if list is empty
        temp->data = value;
        temp->next = head;              // temp now points to head node.
        head = temp;                  // temp is now head node.
    }
    else if(pos > 0){
        node *p = head;             // For tracing the position from first node to pos
        for(int i = 0; i<pos-1; i++){
            p = p->next;
        }
            if(p){
                temp->data = value;             // add the value for created node.
                temp->next = p->next;           // temp next points to value next to the position we are going to insert.
                p->next = temp;                 // now node p points to temp, temp points to next node of p. 
            }
    }
}



int main()
{   
    linkedlist lin;
    lin.append(20);
    lin.append(30);
    lin.append(800);
    lin.insert(3, 40);
    lin.displayLoop();
   
}



            /*
                ANALYSIS:
                        -This function is O(n) in terms of time, because in worst case we traverse the list up to 'pos' nodes to find insertion point. Best case is O(1), 
                         when pos == 0, since we insert directly at head without any traversal. Average and worst case are O(n), depending how large pos is relative to list size.
                        -Moreover, it only calls stack frame once (no recursion) and uses one pointer p, one pointer temp, and loop variable i.
                        so this is O(1) in terms of space.
            */