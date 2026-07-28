#include <iostream>




        /*  
            **LINKED LIST**
                -What is linked list? Linked list is a collection of nodes, which each node has a data and a pointer that points to the next node.
                -Why we need linked list? As we know, arrays are fixed size, and we cannot modify, grow or reduce the size of array in runtime. 
                The size of a list does not depends on programmers, it depends on users. USERS depends how much can a list grow or can reduce in size. 
                Linked list gives us ability to grow or reduce the size of our list according to the needs. if we need, we allocate memory and expand, if 
                we done with it, we simply deallocate the memory and release. 
                -What is node? A node is a structure of two informations. a data which can be any type(int, char, flaot, double..), and a pointer, that has an info 
                which is address of another node, that where they are locating, AS LINKED LIST USES HEAPS. nodes are also in heaps. 
                -We can use class as well as structures, for linked list. In big companies, they use combination of both to have a clean and organized code.
                what is difference between CLASS and STRUCTURE? Both are user-defined data type, the only difference is classes are private by defualt and structs are
                public by defualt.     


                Some important statements of linked lists: 
                    1. node * p, q;
                        q = p;      -> In here, if p's add is 200, then q also will point to that node. if p has a data and pointer, q will have the same data and pointer. 
                    2. q = p->next; -> As p has data, and pointer(address of next node), this statement modifies q to the next node, so q will be a node just beside of p.
                    
                    3. p = p->next; -> in here, p is now pointing to the next node just beside of p. so actually, if 2nd statement is done, then in 3rd, p is equal to q. 

                    4. if(p == nullptr) || if(p == 0) || if(!p) -> means if p points no where, 

                    5. if(p != nullptr) || if(p !=0 ) || if(p)  -> means if p points somewhere.

                    6. if(p->next == nullptr)  -> means if p of next points to any other node or not. one node only exist if true

                    7. if(p->next != nullptr)  -> means if p of next has another node beside.  more than one node if true.

        
        
        
        
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
        void displayRecursive(node* p);
        void display(){
            displayRecursive(head);             // As head is a private member, we need to call it within class. Now, we can call recursive display using lin.display();
        }
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
void linkedlist::displayRecursive(node *p){
    if(p != nullptr){
        std::cout << p->data << " ";
        displayRecursive(p->next);
    }
}


int main()
{   
    linkedlist lin;
    lin.append(20);
    lin.append(30);
    lin.append(40);
    lin.display();



}