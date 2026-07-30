#include <iostream>


        /*  **CIRCULAR LINKED LIST**  
                Inserting in position or before head.
        
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
        void insert(int pos, int value);
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

// Insert
void linkedlist::insert(int pos, int value){
    int length = countNodes();
    if(pos < 0 || pos > length){
        std::cout << "Invalid index\n";
        return;
    }
    node *temp, *p = nullptr;
    if(pos == 0){
        temp = new node;
        temp->data = value;
        if(head == nullptr){
            head = temp;
            head->next = head;
        }else{
            p = head;
            while(p->next != head){
                p = p->next;
            }
            p->next = temp;
            temp->next = head;
            head = temp;
        }
    }else{
        p = head;
        for(int i = 0; i<pos-1; i++){
            p = p->next;
        }
        if(p){
            temp = new node;
            temp->data = value;
            temp->next = p->next;
            p->next = temp;
        }
    }
}




int main()
{   
    linkedlist lin;
    linkedlist lin2;
    int A[5] = {10, 20, 30, 40, 50};
    for(int i = 0; i<5; i++){
        lin.append(A[i]);
        lin2.append(A[i]);
    }
    lin.insert(6, 15);
    lin.display();
    return 0;
}


/*      
    ANALYSIS:   
            We have two functions to discuss in here:
                -countNodes: is a function that counts the nodes of a circular linked list, we have one loop and it iterates until it traverses all list and comes
                 back to head, while looping, it does a few operations. so this is O(n) in terms of time. 
                -Moreover, this is O(1) in terms of space, coz we only have one pointer and one integer count. 

                -Insert(pos, value);: This function is O(n) in terms of time, in best case, it is minimum O(1). why? becuase when we want to add at position 1, right 
                 after the head, it does only one unit work. In any other positions, inserting is O(n). if pos is 0 and bigger than one then it is absloute O(n).
                -Furthermore, this function take constant space, only two pointers, pos, value. nothing else. So this is O(1) in terms of space.
*/