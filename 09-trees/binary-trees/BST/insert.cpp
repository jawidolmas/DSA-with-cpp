#include <iostream>
using namespace std;

#include "Queue.hpp"           
                                // WE USUALLY USE LINKED LIST FOR TREES. SOMETHING WE ALREADY KNOW. 

        /*
            Binary Search Trees:
                    Inserting in a binary search tree: The procedure is simple, first we search if the key which is going to insert should not be in BST. 
                    after that, when the pointer of search becomes null, insert it in there, we will have another pointer which follows temp pointer to help us to 
                    know where exactly to add the new node. 

        */



class Tree{
    public:
        node *root;             // public because we use recursive functions and do not want dummy helper functions. 
        Queue q1, q2;   
        Tree();
        void  CreateBinarySearchTree();
        node* Insert(int key);
        int Inorder(node *root);
};


Tree::Tree(){
    root = nullptr;
}

void Tree::CreateBinarySearchTree(){
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





//Inserting in BST
node* Tree::Insert(int key){
    node* temp = root, *r = nullptr, *p;
    //Do the search in here: 
    while(temp != nullptr){
        r = temp;
        if(key == temp->data){
            return temp;
        }else if(key < temp->data){
            temp = temp->lchild;
        }else{
            temp = temp->rchild;
        }
    }
    p = new node;
    p->data = key;
    p->lchild = p->rchild = nullptr;
    if(r->data < p->data){
        r->rchild = p;
    }else{
        r->lchild = p;
    }
    return p;

}

// Inorder
int Tree::Inorder(node *root){
    if(root != nullptr){
        Inorder(root->lchild);
        cout << root->data << " ";
        Inorder(root->rchild);
    }
    return 0;
}



int main() {
    Tree t1;
    t1.CreateBinarySearchTree();
    t1.Insert(5);
    t1.Inorder(t1.root);

    return 0;
}

/*
        OUTPUT:
                We said the the Inorder in BST should be always sorted: 
                HERE WE ARE: 5 10 15 25 30 40 50 60     
                
*/


    /*
        ANALYSIS:
                    The function Insert is O(h), where h is the height of tree, logn. so it is O(logn) in terms of time and O(1) in terms of space.
    */