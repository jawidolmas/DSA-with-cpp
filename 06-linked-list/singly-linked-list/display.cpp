#include<iostream>

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

int main()
{   
    linkedlist lin;
    lin.append(20);
    lin.append(30);
    lin.append(40);
    lin.displayLoop();
}



        /*  
            **ANALYSIS:
                -This function is O(n) in terms of time. why? becuase as we can see, we have a traverse, so we need to visit each node, and see what is there inside, 
                and once we reached each node, we need to print the data section of node, and increment the temp, so that means, push the temp to the next node.
                -This way, the function will trace each node one by one until it gets to null node, means last node.
                -see? it depends on number of n. if we have 5 node, it does 5 unit work, if we have 100 node, it does 100 unit work. so it is O(n).

                -This function is O(1) in terms of space. why? becuase this function only takes one activation recall in stack. one node of temp and that's all. 

                -To conclude, this function is O(n) in case of time, and O(1) in case of space. 
        */