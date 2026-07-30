#include <iostream>


        /*  **DOUBLY LINKED LIST**  
            If we remmember, in a singly linked list, we could not be able to access a previous node. that is why we have doubly linked list.
                -What is a doubly linked list?: A doubly linked list is a bidirectional linked list. it means, we have two pointers and can access our previous 
                 nodes too, converse to singly linked list.
                -In doubly linked list, we will have 2 pointer and a data member. struct node{ node *prev; int data; node* next; }; and we can access the nodes 
                 that we already passed them.
                -Think of a browser, when we open a website, there is links to pages and other informations to go deep. once we entered a link or a page inside 
                 page, we have the ability to come back to previous page. So going forward and backward is simply the doubly linked list. 
        
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

int main()
{   
    linkedlist lin;
    int A[5] = {10, 20, 30, 40, 50};
    for(int i = 0; i<5; i++){
        lin.append(A[i]);
    }
    lin.display();
    return 0;
}


/*      
        ANALYSIS:   
                -append(value): This function is O(n) in terms of time, in best case, it is minimum O(1). why? becuase when we want to add first element,
                 it does only one unit work. In any other cases, appending is O(n).
                -Furthermore, this function take constant space, only two pointers, value. nothing else. So this is O(1) in terms of space.

                -display(): This function is O(n) in terms of time, in best case, it is minimum O(1). why? becuase when we display only one element,
                 it does only one unit work. In any other cases, displaying  is O(n).
                -Moreover, this function take constant space, only 1 pointer. nothing else. So this is O(1) in terms of space.

                -countNodes(): This function is O(n) in terms of time, in best case, it is minimum O(1). why? becuase when we count only one element in list,
                 it does only one unit work. In any other cases, counting nodes  is O(n).
                -Moreover, this function take constant space, only 1 pointer, and int count. nothing else. So this is O(1) in terms of space.
*/