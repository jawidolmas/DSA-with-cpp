#include <iostream>


        /*     * Reversing a  linked list*  
                    -We can reverse a linked list in two methods:
                        1. Reversing elements(using hash table): We will get an array of size of nodes in linked list, and copy all elements from linked list
                        to the array. after copying, we init the temp pointer which traversed and copied to array, to the head, and the i for array will be i - 1, 
                        means the last element. Once the copying operation done, we start an opposite copying option. we copy all elements from from array to 
                        linked list, but in reverse, that means we copy from last to first. NOW WE HAVE A REVERSED LINKED LIST.
                        in this method the linked list, the head and the node wont change, only elements.

                        2. Reversing the link: 
                        what is link? in software engineering, the link part is actually the pointer part of a node, we may have a int data, node* next; so that next is 
                        actually link part. Why? coz it links the node to another node. 
                        How it works? In this method, we change the node itself, means the address will change, for examle: if we have 1->2->3->4. then we will reverse it,
                        using that the link part should point to one behind, not one forward. so it will be 1 <- 2 <- 3 <- 4; The head acutally changes in here, but in 1st
                        method the linked list, the head and the node wont change, only elements.

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
        int countNodes();
        void reverseMethod1();

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

int linkedlist::countNodes(){
    node *temp = head;
    int count = 0;
    while(temp != nullptr){
        count++;
        temp = temp->next;
    }
    return count;
}


// Reversing a linked list using Reversing elements method:
void linkedlist::reverseMethod1(){
    int size = countNodes();
    node* temp = head;
    int arr[size] = {0}, i = 0;
    while(temp != nullptr){
        arr[i] = temp->data;
        i++;
        temp =temp->next;
    }
    temp = head;
    i--;
    while(temp != nullptr){
        temp->data = arr[i--];
        temp = temp->next;
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
    lin.reverseMethod1();    
    lin.display();                                          
   
/*
    output:

    Before: 10 20 30 40 50 
    After:  50 40 30 20 10
    
*/

}



            /*
                ANALYSIS:
                    -This function is O(n) in terms of time, because we have two while loops, one loop will copy the elements from first to last element inside the array
                    and the next loop will copy back the array to linked list in reverse order from last to first. n for first loop and n for second loop.
                    In total we did 2n work in here, so it is O(n) in terms of time.
                     
                    -At the same time, as we created a brand new array just to copy the values from linked list, that means we have allocated n spaces in memeory.
                    Because, if we have n elements in linked list, how many nodes will we have? n nodes, isn't it? so we allocate memory in stack for array in size of 
                    nodes, so we allocate n unit space. 
                    -To conclude, this function is O(n) in both space and time. 
            */