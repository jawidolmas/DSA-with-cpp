

    /*
        Tree:
            Binary Tree:
                Postorder display
    
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
        void Postorder(node *temp);
        void PostOrder(){
            Postorder(root);
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

// PostOrdeer Display
void Tree::Postorder(node *temp){
    if(temp){
        Postorder(temp->lchild);
        Postorder(temp->rchild);
        cout << temp->data << " ";
        
    }
}

int main()
{
    Tree t1;
    t1.createBinTree();
    t1.PostOrder();

    return 0;
}


/*
    Output:
            20 30 10 


*/


/*
    ANALYSIS:
       Preorder:
            This function is O(n) in both time and space complexity. This function will traverse the tree in PostOrder algorithm and goes up to n. 
            Also, as this is a recursive function, it uses stack for n times which makes space compelexity order of n.
*/