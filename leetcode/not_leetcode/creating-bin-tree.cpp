#include <iostream>
using namespace std;

#include "Queue.hpp"            // For seeing Queue implementation, visit DSA-with-cpp/09-trees/binary-tress/

class Tree{
    public:
        node *root;
        Queue q1, q2;
        Tree();
        void createBinTree();
        int preorder(node *root) const;
};


Tree::Tree(){
    root = nullptr;
}

void Tree::createBinTree(){
    node *temp, *p;
    int x;
    cout << "Enter Root node: ";
    cin >>  x;
    root = new node;
    root->data = x;
    root->lchild = root->rchild = nullptr;
    q1.enqueue(root);
    while(!q1.isEmpty()){
        p = q1.dequeue();
        cout << "Enter Left child of " << p->data << ": ";
        cin >> x;
        if(x != -1){
            temp = new node;
            temp->data = x;
            temp->lchild = temp->rchild = nullptr;
            p->lchild = temp;
            q1.enqueue(temp);
        }
        cout << "Enter Right child of " << p->data<< ": ";
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


int Tree::preorder(node *root) const{
    if(root != nullptr){
        cout << root->data << " ";
        preorder(root->lchild);
        preorder(root->rchild);
    }
    return 0;
}

int main()
{
    Tree t1;
    t1.createBinTree();
    t1.preorder(t1.root);
}