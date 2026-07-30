#include <iostream>


        /*  **DOUBLY LINKED LIST**  
            middle node of a linked list.
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
        int middleNode();


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

// Middle node. Two poiner method
int linkedlist::middleNode(){
    node *p, *q;
    p = q = head;
    while(q != nullptr){
        q = q->next;
        if(q) q = q->next;      // if not null
        if(q) p = p->next;     // if not null
    }
    return p->data; 
}




int main()
{   
    linkedlist lin;
    int A[5] = {10, 20, 30, 40, 50};
    for(int i = 0; i<5; i++){
        lin.append(A[i]);
    }
    std::cout << lin.middleNode() << std::endl;
    return 0;
}


/*      
        ANALYSIS:   
                -This function is O(n) in terms of time, because it traverses every single node exactly once, p goes by one step and q by two step, when q gets null 
                 we can understand that p is definitely at the middl. so it is O(n).
                -Also, this function takes constant space, only 2 pointer q, and p, nothing else allocated. So this is O(1) in terms of space.

*/