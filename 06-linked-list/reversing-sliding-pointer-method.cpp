#include <iostream>


        /*     * Reversing a  linked list*  
                    -We can reverse a linked list in two methods:
                        1. Reversing elements(using hash table): We will get an array of size of nodes in linked list, and copy all elements from linked list
                        to the array. after copying, we init the temp pointer which traversed and copied to array, to the head, and the i for array will be i - 1, 
                        means the last element. Once the copying operation done, we start an opposite copying option. we copy all elements from from array to 
                        linked list, but in reverse, that means we copy from last to first. NOW WE HAVE A REVERSED LINKED LIST.
                        in this method the linked list, the head and the node wont change, only elements.

                        2. Reversing the link: Sliding pointers:
                        what is link? in software engineering, the link part is actually the pointer part of a node, we may have a int data, node* next; so that next is 
                        actually link part. Why? coz it links the node to another node. 
                        How it works? In this method, we change the node itself, means the address will change, for examle: if we have 1->2->3->4. then we will reverse it,
                        using that the link part should point to one behind, not one forward. so it will be 1 <- 2 <- 3 <- 4; The head acutally changes in here, but in 1st
                        method the linked list, the head and the node wont change, only elements.


                        **We also can do the reversing opeartion using recursion. 
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
        void reverseSlidingPointer();

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




// Reversing a linked list using Reversing its link. Sliding pointer(Having more than one pointer and each pointer are following each other) method:
void linkedlist::reverseSlidingPointer(){
    node *q = nullptr, *r = nullptr, *p = head;
    while(p != nullptr){
        r = q;
        q = p;
        p = p->next;
        q->next = r;        // Real reversing happens here.
    } 
    head = q;               // As p is nullptr now, q is the first element, so it needs to be updated with head. 

}
//  in this method we actually change the address of nodes, means we change each node's link to point to some where else. 


int main()
{   
    linkedlist lin;
    lin.append(10);
    lin.append(20);
    lin.append(30);
    lin.append(40);
    lin.append(50);
    lin.display();
    std::cout << std::endl;
    lin.reverseSlidingPointer();    
    lin.display();                                          
   
/*
    output:

    Before: 10 20 30 40 50 
    After:  50 40 30 20 10
    
*/

}



            /*
                ANALYSIS:
                    -This function is O(n) in terms of time, because in here, we have only one loop, and that loop runs until it gets to nullptr(end of list).
                    and does some operations inside loop which are constant unit of time. so it is O(n).
                     
                    -However, this function is O(1) in terms of space, why? becuase if we see carefully, we only took 3 extra pointers, r, q, p. that's it. nothing more. 
                    if linked list contains a node of 100, 10000, 100000000. then again, we will take only 3 pointer in memory. so it is O(1).
                    -To conclude, this function is O(n) in terms of time and O(1) in terms of space. 
            */