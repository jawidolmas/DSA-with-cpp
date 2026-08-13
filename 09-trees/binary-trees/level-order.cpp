

    /*
        Tree:
            Binary Tree:
                Level Order Display
    */

#include <iostream>
#include "Queue.hpp"
#include "Stack.hpp"
using namespace std;

class Tree{
    private:
        node* root;
    public:
        Tree(){root = nullptr;}
        void createBinTree();
        void levelOrder();
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

//Level Order Display
void Tree::levelOrder(){
    Queue q1(100);
    cout << root->data << " ";
    q1.enqueue(root);
    while(!q1.isEmpty()){
        root = q1.dequeue();
        if(root->lchild){
            cout << root->lchild->data << " ";
            q1.enqueue(root->lchild);
        }
        if(root->rchild){
            cout << root->rchild->data << " ";
            q1.enqueue(root->rchild);   
        }
    }
}


int main()
{
    Tree t1;
    t1.createBinTree();
    t1.levelOrder();

    return 0;
}


/*
    Output:
            10 20 30 40 50 60 70 80

*/


/*
    ANALYSIS:
       Preorder:
            This program including used Queue is O(n) in both time and space complexity. the function will traverse the tree in Level Order algorithm and goes up to n. 
            Also, as this function uses Queue, it uses Queue for n times which makes space compelexity order of n.
*/