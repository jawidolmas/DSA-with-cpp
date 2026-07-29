#include <iostream>


        /*
                *Merging two sorted linked lists*
                Merging two linked list: Mergin means mergin two sorted list into one sorted list. 
                
                -We have two separate sorted linked lists, and want to combine them into
                 one single sorted list, without creating a third, new list from scratch.
                 Instead, we reuse existing nodes from both lists, just relink their
                 'next' pointers so all nodes end up in one sorted chain.

                -Why not just merge like sorted arrays? In arrays we'd copy element by
                 element into a new array, comparing indices. Linked lists don't have
                 indices, but the sorted property still holds. So we walk both lists at
                 once, always picking whichever current node has smaller data, and
                 attach that one to our result.

                -How it works: We use two pointers, one for each list, call them p1 and p2,
                 starting at each list's head. We compare p1->data and p2->data. Whichever
                 is smaller gets attached as next node in merged list, and that pointer
                 advances to its own next node. We repeat this until one list runs out
                 (becomes nullptr). Whatever remains of the other list gets attached
                 wholesale at the end, since it's already sorted.

                -We can do this iteratively (loop, dummy/temp head node to simplify
                 attaching first node) or recursively (function calls itself comparing
                 p1->data and p2->data, whichever smaller gets ->next set to result of
                 recursive call on rest of both lists).

                -After merging, only ONE list remains -- typically we set 'head' to
                 point at whichever list's first node had smaller data, and the second
                 list object shouldn't be used independently anymore, since its nodes
                 got absorbed into the first list.

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
        void Merge(linkedlist &l1, linkedlist &l2);

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

// Merge        :: Only works for sorted arrays. coz this is MERGE
void linkedlist::Merge(linkedlist &l1, linkedlist &l2){
    node *third = nullptr, *last = nullptr;
    node *first = l1.head;
    node *second = l2.head;
    if(first->data < second->data){
        third = last = first;
        first = first->next;
        third->next = nullptr;
    }
    else{
        third = last = second;
        second = second->next;
        third->next = nullptr;
    }
    while(first && second){                 // WHILE these two are not nullptr. 
        if(first->data < second->data){
            last->next = first;
            last = first;
            first= first->next;
            last->next = nullptr;
        }
        else{
            last->next = second;
            last = second;
            second = second->next;
            last->next = nullptr;
        }
    }
    if(first){          // After loop, if second gets nullptr, then attach second to first's remaining.
        last->next = first;
    }
    else{              // After loop, if first gets nullptr, then attach first to seconds remaining;
        last->next = second;
    }
    head = third;
    l1.head = nullptr;
    l2.head = nullptr;

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
    std::cout << std::endl;
    result.Merge(lin, lin2);                                     
    result.display();
    lin.display();
    return 0;
}



            /*
                ANALYSIS:
                    -This function is O(n) in terms of time, because it walks through both list 1 and list 2 together, one node at a time, comparing data and relinking nodes until
                     one list runs out, then attaches remainder of the other. Total work depends on combined length of both lists.

                    -At the same time, this function is O(1) in terms of space, because it only reuses existing nodes from list 1 and list 2, no new nodes are allocated, and no
                     recursion is involved, so no extra stack frames or extra memory are created regardless of how long either list is.
                    -To conclude, this function is O(n) in terms of time and O(1) in terms of space.
            */