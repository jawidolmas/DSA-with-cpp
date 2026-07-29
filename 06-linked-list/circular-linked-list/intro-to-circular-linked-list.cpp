#include <iostream>


        /*  **CIRCULAR LINKED LIST**
            
            -What is circular linked list? Same idea as normal linked list -- nodes with data and a pointer to next node -- but last node doesn't point to nullptr.
            Instead, last node's pointer points back to first node (head). This makes the list a closed loop, no true "end."

            -Why we need circular linked list? Normal linked list, once you reach last node, you're stuck - only way back to start is walking from head again.
            Circular list lets you keep traversing forever, or jump back to front without needing a separate head reference each time. Useful for things
            that naturally "cycle" -- like round-robin scheduling, or repeating playlists, where after last item you want to go back to first automatically.

            -How is it different from normal (linear) linked list? Only real structural difference: last node's next = head, instead of nullptr. Everything else
            (node structure, data + pointer) stays same. But this small change affects HOW we write functions -- loops can't rely on p != nullptr anymore to
            know when to stop, since list never naturally reaches nullptr. Need to check p != head instead, or count nodes, to avoid infinite loop.

            -We can use class as well as structures, same as before. Class hides head as private, struct just holds raw data. Combination pattern still applies.

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
        void displayRecursion(node *temp);
        void display(){
            displayRecursion(head);
        }

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

// Display using loop
void linkedlist::displayLoop(){
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

// Display using recursoin
void linkedlist::displayRecursion(node *temp){
    static int flag = 0;
    if(temp != head || flag == 0){
        flag = 1;
        std::cout << temp->data << " ";
        displayRecursion(temp->next);
    }
    flag = 0;
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
    lin.displayLoop();
    lin.display();
    lin2.display();
    return 0;
}


/*      
    ANALYSIS:

        append (circular)
            -This function is O(n) in terms of time, because in worst case we traverse the entire list to find the last node (where next == head). Best case is O(1),
             when list is empty, since we just set head = p directly.
            -Moreover, it only calls stack frame once (no recursion) and uses one pointer temp, one pointer p.
             so this is O(1) in terms of space.

        displayLoop (circular)
            -This function is O(n) in terms of time, because we traverse each node once, starting at head and stopping when we circle back to head again.
            -Moreover, it only calls stack frame once (no recursion) and uses one pointer temp.
             so this is O(1) in terms of space.
             
        displayRecursion (circular)
            -This function is O(n) in terms of time, because it calls itself once per node,stopping when next node equals starting point (head), so it runs exactly n
             times for n nodes.
            -This function is O(n) in terms of space, because each recursive call adds a tack frame, and frames aren't released until base case hits, so n nodes means
             n stack frames.

*/