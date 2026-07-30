#include <iostream>


        /*  **DOUBLY LINKED LIST**  
                *Inserting in first or in position*        
        
        */

struct node{
    node* prev;
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
        void display();
        int Delete(int pos);
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


// appending in doubly liked list.
void linkedlist::append(int value){
    node *p = new node;
    p->data = value;
    p->next = nullptr;
    p->prev = nullptr;

    if (head == nullptr) {
        head = p;
        return;
    }

    node *last = head;
    while (last->next != nullptr) {
        last = last->next;
    }

    last->next = p;
    p->prev = last;
}

// Display
void linkedlist::display(){
    if(head == nullptr){
        std::cout << "List is empty\n";
        return;
    }
    node *temp = head;
    while(temp != nullptr){
        std::cout << temp->data << " ";
        temp = temp->next;
    }
    std::cout << std::endl;
}

// Count nodes of a doubly linked list
int linkedlist::countNodes(){
    if(head == nullptr) return 0;       // empty list
    node *temp = head;
    int count = 0;
    while(temp != nullptr){
        count++;
        temp =   temp->next;
    }
    return count;
}

// Insert
void linkedlist::insert(int pos, int value){
    if(pos < 0 || pos > countNodes()){
        std::cout << "Invalid index\n";
        return;
    }
    node *temp, *p;
    if(pos == 0){
        temp = new node;
        temp->data = value;
        head->prev = temp;
        temp->next = head;
        temp->prev = nullptr;
        head = temp;
    }else{
        p = head;
        for(int i = 0; i<pos-1; i++){
            p = p->next;
        }
        temp = new node;
        temp->data = value;
        temp->next = p->next;
        temp->prev = p;
        if(p->next){            // if p->next is available, means there is node after p. 
            p->next->prev = temp;
        }
        p->next = temp;   
    }
}







int main()
{   
    linkedlist lin;
    int A[5] = {10, 20, 30, 40, 50};
    for(int i = 0; i<5; i++){
        lin.append(A[i]);
    }
    lin.insert(5, 15);
    lin.display();
    return 0;
}


/*      
        ANALYSIS:   
                -This function is O(n) in terms of time, in best case, it is minimum O(1). why? becuase when we want to add if there is one element, means adding at 
                 position 1. it does only one unit work. In any other cases, inserting is O(n). when pos is 0 or any other pos, it will be O(n).
                -Also, this function take constant space, only two pointers, pos, and value. nothing else. So this is O(1) in terms of space.

*/