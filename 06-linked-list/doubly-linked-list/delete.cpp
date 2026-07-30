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
        int DeleteElement(int pos);


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

// Count
int linkedlist::countNodes(){
    if(head == nullptr) return 0;      
    node *temp = head;
    int count = 0;
    while(temp != nullptr){
        count++;
        temp =   temp->next;
    }
    return count;
}

// Delete
int linkedlist::DeleteElement(int pos){
    if(pos < 1 || pos > countNodes()){
        return -1;
    }
    int x = 0;
    node* temp = nullptr;
    if(pos == 1){
        temp = head;
        head = head->next;
        x = temp->data;
        delete temp;
        if(head != nullptr){
            head->prev = nullptr;
        }
    }else{
        temp = head;
        for(int i = 0; i<pos-1; i++){
            temp = temp->next;
        }
        temp->prev->next = temp->next;
        if(temp->next){
            temp->next->prev = temp->prev;
        }
        x = temp->data;
        delete temp;
    }
    return x;
}


int main()
{   
    linkedlist lin;
    int A[5] = {10, 20, 30, 40, 50};
    for(int i = 0; i<5; i++){
        lin.append(A[i]);
    }
    std::cout << lin.DeleteElement(3) << std::endl;
    lin.display();
    return 0;
}


/*      
        ANALYSIS:   
                -This function is O(n) in terms of time, in best case, it is minimum O(1). why? becuase when we want to delete 1st element, means deleting at 
                 position 1. it does only one unit work. In any other cases, deleting is O(n). when pos is 0 or any other pos, it will be O(n).
                -Also, this function take constant space, only 1 pointers, pos, i. nothing else. So this is O(1) in terms of space.

*/