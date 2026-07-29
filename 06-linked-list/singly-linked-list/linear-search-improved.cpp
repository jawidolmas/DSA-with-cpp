#include <iostream>


        /*     *Searching for a key in a linked list* 
                    As we implemented linear search, 

                    ** Can we improve the linear search? Yeah, we had two methods, 1. Transposition method, 2. Move to front/Head method. 
                    we know about transposition(sliding found key to head on each search) and move to front(moving found key to head directly). 
                    -We cannot use transposition in linked list, becuase, usually, moving datas in linked list is not good and we avoid it, datas in linked list are 
                    not only ints, chars.., in big projects its about objects, methods and other datas that needs to be private and arranged. this is a real security 
                    issue. 

                    -We use move to front to improve our linear search. 
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
        void displayLoop();
        int  movetofrontSearch(int key);

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

// Searching for key in a linked list using loop
int linkedlist::movetofrontSearch(int key){
        node* p = head;
        node*  q = nullptr;         // Helper pointer to follow the p.
        if(key == head->data) return 1;         // When the searched key is already in head, so no need to move it anywhere(no need for crash). 
        while(p != nullptr){
            if(key == p->data){
                q->next = p->next;    // q will follow p, when key found, q should jump the p and should be linked to next node of p.
                p->next = head;      // doing real move to front here, p should point to head(first node).
                head = p;           // the previous head now should euqal to  p. 
                return 1;
            }
            q = p;                // q should follow the p. one by one.
            p = p->next;          // iterate the p, to do the actual searching action. 
        }
        return 0;
}



int main()
{   
    linkedlist lin;
    lin.append(20);
    lin.append(30);
    lin.append(800);
    lin.displayLoop();
    std::cout << lin.movetofrontSearch(20) << std::endl;     // O/P: 1
    std::cout << lin.movetofrontSearch(10) << std::endl;     // O/P: 0
}



            /*
                ANALYSIS:
                    *Using Loop: 
                        -This function is O(n) in terms of time, becuase we traverse each node one by one until it finds the key, it can be O(1) in best case and 
                        O(n) in average case as well as O(n) in worst case. if key found, we move it to front and we do a 3 unit work in there, so it is O(n).
                        -Moreover, it only call stack frame once and it has one pointer p, q,  and one variable key.
                        so this is O(1) in terms of space. 
            */