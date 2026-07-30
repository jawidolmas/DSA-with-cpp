#include <iostream>


        /*  **CIRCULAR LINKED LIST**  
                Deleting first node or in given position
        
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
    do{
        node* next = current->next;
        delete current;
        current = next;
    }while(current != head);
}

// Adding data to a circular linked list.               
void linkedlist::append(int value){
    node *p = new node;
    p->data = value;
    

    if(head == nullptr){
        head = p;
        p->next = head;
    }else {
    node *temp = head;
    while(temp->next != head){
        temp = temp->next;
    }
    p->next = head;
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
    do{
        std::cout << temp->data << " ";
        temp = temp->next;
    }while(temp != head);
    std::cout << std::endl;
}

// Count nodes of a circular linked list
int linkedlist::countNodes(){
    if(head == nullptr) return 0;       // empty list
    node *temp = head;
    int count = 0;
    do{
        count++;
        temp = temp->next;
    }while(temp != head);
    return count;
}

// Deleting first or in position
int linkedlist::Delete(int pos){
    int length = countNodes(), x = 0;
    node *p = head, *q = nullptr;
    if(pos < 1 || pos > length){
        return -1;
    }
    if(pos == 1){
        while(p->next != head){
            p = p->next;
        }
        if(head == p){
            delete head;
            head = nullptr;
        }else{
            p->next = head->next;
            x = head->data;
            delete head;
            head = p->next;
        }

    }else{
        for(int i = 0; i<pos-2; i++){
            p = p->next;
        }
        q = p->next;
        p->next = q->next;
        x = q->data;
        delete q;
        q = nullptr;
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
    std::cout << lin.Delete(6) << std::endl;
    lin.display();
    return 0;
}


/*      
        ANALYSIS:   
                -This function is O(n) in terms of time, in best case, it is minimum O(1). why? becuase when we want to delete position 1, right 
                 after the head, it does only one unit work. In any other positions, deleting is O(n). if pos is 0 and bigger than one then it is absloute O(n).
                -Furthermore, this function take constant space, only two pointers, pos, lenght. nothing else. So this is O(1) in terms of space.
*/