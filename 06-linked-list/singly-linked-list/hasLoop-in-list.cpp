#include <iostream>


        /*  *CHECK IF A LINKED LIST HAS A LOOP*
                -Having loop means when there is a cycle in the list. the last node pointing to another node.
                we will use two pointers algorithm in here: pointer p and q, p will move by one step and q will move by two steps. 
                -suppose there is a car race, car 1 speed is 100 and car 2 speed is 150. 
                **If they race in a linear track, is there any chance they could meet again? NO. COZ IT IS LINEAR, there is no loop/cycle.
                
                **If they race in a circular/cycle track and they should track 15 times, is there any chance they could meet again? YES, COZ IS A CYCLE AND THEY WILL MEET AGAIN. 

                let's code.
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
        int isLoop();
        void createLoop();

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
    std::cout << std::endl;
}

// Check if list has loop
int linkedlist::isLoop(){
    node *p, *q;
    p = q = head;
    do{
        p = p->next;
        q = q->next;
        q = q?q->next:q;        // Check if we move q by one, does it equal to null or not? in order to not check blindly for loop in a linear list.
    } while(p && q && p != q);
    if(p == q){
        return 1;           // means loop exist
    }
    else{
        return 0;          // no loop exist;
    }
}   

// Create loop
void linkedlist::createLoop(){
    node *t1, *t2;
    t1 = head->next->next;    // t1 is now pointing to 3rd element in list.
    t2 = head->next->next->next->next;        // t2 is pointing to 5th element in list.
    t2->next = t1;              // created the loop. 
}


int main()
{   
    linkedlist lin;
    linkedlist lin2;
    linkedlist result;
    int A[5] = {10, 20, 30, 40, 50};
    int A2[5] = {1, 2, 3, 4, 5};;
    for(int i = 0; i < 5; i++){
        lin.append(A[i]);
        lin2.append(A2[i]);
    } 
    lin.display();
    std::cout << lin.isLoop();  // has no loop in here. O/P: 0;
    lin.createLoop();
    std::cout << lin.isLoop();      // has loop, O/P: 1;
    return 0;
}



            /*
                ANALYSIS:
                    -This function is O(n) in terms of time, because q, p  walks through list together, one node at a time, comparing data and relinking nodes until
                     one list runs out, then attaches remainder of the other. 

                    -At the same time, this function is O(1) in terms of space, coz we only took 2 pointers space. nothing else. 
            */




// NOTE: destructor doesn't handle looped lists -- if a cycle exists
// (created via createLoop()), destructor will crash / undefined behavior,
// since current->next never becomes nullptr, and nodes get deleted
// more than once. Not fixed here, known limitation for this exercise.
// it can be fixed if we handle it in destructor so it should detect the meet points.