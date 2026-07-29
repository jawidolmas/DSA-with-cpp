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
                            -In recursive version: we will have 2 pointers, p and q, we will call the function itself with q = p and p = p->next call, until p gets nullptr
                            In this way, when p gets nullptr, q will be one node behind of p. WHILE RETURNING OF THE RECURSIVE CALLS, we will modify the address, so p->next
                            will be equal to q. and after calling we will assing first = q. that's it. 

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
        void reverseRecursion(node* q, node *p);
        void reverse(){                                 // can't directly call, head is private memeber
            reverseRecursion(nullptr, head);
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




// Reversing a linked list using Recursions
void linkedlist::reverseRecursion(node *q, node *p){
    if(p != nullptr){
        reverseRecursion(p, p->next);       // reverseRecursion(p, p->next)-> in here, as we did p instead of q, that means q = p;
        p->next = q;                       //  Real reverse happens here, while returning change the links of nodes. 
    }
    else{
    head = q;                            //    When finished, make sure q should be head. a complete reverse. 
    }
}


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
    lin.reverse();    
    lin.display();                                          
   
/*
    output:

    Before: 10 20 30 40 50 
    After:  50 40 30 20 10
    
*/

}



            /*
                ANALYSIS:
                    -This function is O(n) in terms of time, because in here, we have a recursion,  and that recursion will call itself until p gets nullptr.
                    and does one operation when returning. 
                     
                    -At the same time, this function is O(n) in terms of space, why? becuase if we see carefully, we take a stack frame on each recursive call, 
                    if list contains 100 nodes, then we would have 100+1 activation recall. one for p = nullptr. so it is O(n) in terms of space too.
                    -To conclude, this function is O(n) in terms of time and O(n) in terms of space. 
            */