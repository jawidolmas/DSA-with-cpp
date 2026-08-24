
#include <iostream>


struct node{
    int data;
    node *next;
};

class HashLinkedL{
    private:
        node *head;
    public:
        HashLinkedL(){
            head = nullptr;
        }
        ~HashLinkedL(){
            node *current = head;
            while(current != nullptr){
                node *next = current->next;
                delete current;
                current = next;
            }
        }
        void SortedInsert(node **H, int key){
            node *temp = new node;
            temp->data = key;
            temp->next = nullptr;

            node *p = *H, *q = nullptr;

            if(*H == nullptr || key <= (*H)->data){
                temp->next = *H;
                *H = temp;
                return;
            }

            while(p && p->data < key){
                q = p;
                p = p->next;
            }
            temp->next = p;
            q->next = temp;
        }

        node *search(int key){
            node *temp = head;
            while(temp != nullptr){
                if(key == temp->data){
                    return temp;
                }
                temp = temp->next;
            }
            return  nullptr;
        }
};



