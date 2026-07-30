#include <iostream>


        /*  **DOUBLY LINKED LIST**  
                *Reversing a doubly linked list*        
                    -In reversing a doubly linked list, we use the logic of swap(). we will only swap pointers, one node prev with another node prev and next to another
                    node next. 
                    
                    let's code.
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
        void reverse();


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


// append
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



// Reverse
void linkedlist::reverse(){
    node *p = head, *temp;
    while(p != nullptr){
        // Do the swap here (Remmeber, we will swap pointers not values).
        temp = p->next;
        p->next = p->prev;
        p->prev = temp;
        // Once swap finished, increment the p, as now p change its pointers, we will do p = p->prev instead of p = p->next
        p = p->prev;
        // Check if p gets null, if so, then head = p;
        if(p!= nullptr && p->next == nullptr){
            head = p;
        }
    }

}


int main()
{   
    linkedlist lin;
    int A[5] = {10, 20, 30, 40, 50};
    for(int i = 0; i<5; i++){
        lin.append(A[i]);
    }
    lin.reverse();
    lin.display();
    return 0;
}


/*      
        ANALYSIS:   
                -This function is O(n) in terms of time, because it traverses every single node exactly once, swapping next/prev pointers for each, until p becomes
                 nullptr. No best/worst case difference -- always visits all n nodes.
                -Also, this function takes constant space, only 1 pointer p, nothing else allocated. So this is O(1) in terms of space.

*/