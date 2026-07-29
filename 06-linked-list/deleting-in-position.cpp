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

int linkedlist::countNodes(){
    node *temp = head;
    int count = 0;
    while(temp != nullptr){
        count++;
        temp = temp->next;
    }
    return count;
}

// deleting a value in a given postion in  linked list
int linkedlist::Delete(int pos){
    int length = countNodes();
    if(pos < 0 || pos > length){
        return -1;                  // invalid index. 
    }
    node *temp, *p = head, *q =nullptr;
    int x = 0;
    if(pos == 1){
        temp = head;
        head = head->next;
        x = temp->data;
        delete temp;
        temp = nullptr;
        return x;
    }else{
        for(int i = 0; i < pos-1; i++){
            q = p;
            p = p->next;
        }
        if(p){
        q->next = p->next;
        x = p->data;
        delete p;
        p = nullptr;
    }
    }
    return x;
}



int main()
{   
    linkedlist lin;
    lin.append(20);
    lin.append(30);
    lin.append(800);
    std::cout << lin.Delete(3) << std::endl;
    lin.displayLoop();
   
}



            /*
                ANALYSIS:
                    -This function is O(n) in terms of time, because in worst case we traverse the entire list to find correct position for deleting.
                     Best case is O(1), when given position is 1, means head node should be deleted, since we delete directly at front without any traversal. 
                     Average and worst case are O(n), depending how far into list the correct position lies.
                     
                    -Moreover, it only calls stack frame once (no recursion) and uses two pointers p and q, plus one pointer temp for new node to hold head.
                    -so this is O(1) in terms of space.
            */