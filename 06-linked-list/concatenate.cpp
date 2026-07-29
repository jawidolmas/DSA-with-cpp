#include <iostream>


        /*
                Concatenating two linked list. 
                Means appending one list to the end of another list.
        
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
        void display();
        void concatenate(linkedlist &l1, linkedlist &l2);

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
}

// Concatenate: 
void linkedlist::concatenate(linkedlist &l1, linkedlist &l2){
    node *temp = l1.head;
    while(temp->next != nullptr){
        temp = temp->next;
    }
    temp->next = l2.head;
    l2.head = nullptr;
}


int main()
{   
    linkedlist lin;
    linkedlist lin2;
    int A[5] = {10, 20, 30, 40, 50};
    int A2[5] = {1, 2, 3, 4, 5};;
    for(int i = 0; i < 5; i++){
        lin.append(A[i]);
        lin2.append(A2[i]);
    } 
    lin.display();
    std::cout << std::endl;
    lin.concatenate(lin, lin2);
    lin.display();                       // O/P: 10 20 30 40 50 1 2 3 4 5                            
   
    return 0;
}



            /*
                ANALYSIS:
                        -This function is O(n) in terms of time, because it traverses list 1 fully to find its last node, walking one node at a time until reaching nullptr. 
                         It doesn't touch list 2 at all, just attaches it at the end, so total work depends only on list 1's length.

                        -At the same time, this function is O(1) in terms of space, because it only uses one pointer temp, no recursion involved, so no extra stack frames 
                         are created regardless of how long either list is.
                        -To conclude, this function is O(n) in terms of time and O(1) in terms of space.
            */