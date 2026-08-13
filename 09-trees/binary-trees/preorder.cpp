

    /*
        Tree:
            Binary Tree:
                Preorder display
    
    */

#include <iostream>
#include "Queue.hpp"
using namespace std;

class Tree{
    private:
        node* root;
    public:
        Tree(){root = nullptr;}
        void createBinTree();
        void Preorder(node *temp);
        void PreOrder(){
            Preorder(root);
        }      
};

void Tree::createBinTree(){
    node *temp, *p;
    int x;
    Queue q1(100);
    cout << "Enter Root Node: ";
    cin >> x;
    root = new node;
    root->data = x;
    root->lchild = root->rchild = nullptr;
    q1.enqueue(root);
    while(!q1.isEmpty()){
        p = q1.dequeue();
        cout << "Enter left child of " << p->data << ": ";
        cin >> x;
        if(x != -1){
            temp = new node;
            temp->data = x;
            temp->lchild = temp->rchild = nullptr;
            p->lchild = temp;
            q1.enqueue(temp);
        }
        cout << "Enter right child of " << p->data << ": ";
        cin >> x;
        if(x != -1){
            temp = new node;
            temp->data = x;
            temp->lchild = temp->rchild = nullptr;
            p->rchild = temp;
            q1.enqueue(temp);
        }
    }
    
}

// Preoder Display
void Tree::Preorder(node *temp){
    if(temp){
        cout << temp->data << " ";
        Preorder(temp->lchild);
        Preorder(temp->rchild);
    }
}

int main()
{
    Tree t1;
    t1.createBinTree();
    t1.PreOrder();

    return 0;
}


/*
    Output:
            10 20 40 50 30 60 70 


*/


/*
    ANALYSIS:
       Preorder:
            This function is O(n) in both time and space complexity. This function will traverse the tree in preorder algorithm and goes up to n. 
            Also, as this is a recursive function, it uses stack for n times which makes space compelexity order of n.
*/