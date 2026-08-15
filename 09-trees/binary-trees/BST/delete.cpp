#include <iostream>
using namespace std;

#include "Queue.hpp"           
                               

        /*
            Binary Search Trees:
                Deleting a key in BST



        */



class Tree{
    public:
        node *root;             // public because we use recursive functions and do not want dummy helper functions. 
        Queue q1, q2;   
        Tree();
        node* Insert(int key);
        int Inorder(node *root);
        int hieght(node* root);
        node* InPrecessor(node* root);
        node* InSuccessor(node* root);
        node *Delete(node *root, int key);
};


Tree::Tree(){
    root = nullptr;
}


//Inserting in BST
node* Tree::Insert(int key){
    node* temp = root, *r = nullptr, *p;
    // Handle empty-case
    if(temp == nullptr){
        temp = new node;
        temp->data = key;
        temp->lchild = temp->rchild = nullptr;
        root = temp;
        return temp;
    }else{
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

// Height
int Tree::hieght(node* root){
    int x, y;
    if(root == nullptr){
        return 0;
    }
    x = hieght(root->lchild);
    y = hieght(root->rchild);
    return x>y?x+1:y+1;
}

// Inorder Precessor: These shows which sub-tree has bigger hieght
node* Tree::InPrecessor(node *root){
    while(root && root->lchild != nullptr){
        root = root->lchild;
    }
    return root;
}

// Inorder Successor
node* Tree::InSuccessor(node *root){
    while(root && root->rchild != nullptr){
        root = root->rchild;
    }
    return root;
}

node* Tree::Delete(node* root, int key){
    node* p = root, *q;

    if(p == nullptr){
        return nullptr;
    }

    if(key < p->data){
        p->lchild = Delete(p->lchild, key);
    }else if(key > p->data){
        p->rchild = Delete(p->rchild, key);
    }else{
        // Case 1: leaf node
        if(p->lchild == nullptr && p->rchild == nullptr){
            delete p;
            return nullptr;
        }
        // Case 2: only right child
        if(p->lchild == nullptr){
            node* temp = p->rchild;
            delete p;
            return temp;
        }
        // Case 3: only left child
        if(p->rchild == nullptr){
            node* temp = p->lchild;
            delete p;
            return temp;
        }

        // Case 4: two children
        if(hieght(p->lchild) < hieght(p->rchild)){
            q = InPrecessor(p->lchild);
            p->data = q->data;
            p->lchild = Delete(p->lchild, q->data);
        }else{
            q = InSuccessor(p->rchild);
            p->data = q->data;
            p->rchild = Delete(p->rchild, q->data);
        }
    }
    return p;
}





int main() {
    Tree t1;
    t1.Insert(5);
    t1.Insert(10);
    t1.Insert(50);
    t1.Insert(30);
    t1.Insert(40);
    t1.Insert(60);
    t1.root = t1.Delete(t1.root, 5);         // Deletes the 5. we need to pass it to root coz 5 is root. 
    t1.Delete(t1.root, 40);                 // Deletes the 40.
    t1.Inorder(t1.root);

    return 0;
}

/*
        Dear Me,
        I really do not know how I wrote this function, and how it worked, when I see it worked I stopped and pushed it in github. 
        This function took me hours to write and took days to understand, but I am still sure that I will forget it within one week. 
        This note is exculsively for myself and Delete function was extremely hard for me to trace it one by one, even by multiple debuggings, I am still not 100% 
        on it. So, if someone asks you do you know how to delete a node in a BST, just simply asnwer: NO. 
                
*/


    /*
        ANALYSIS:
                HOW DO I EVEN CAN ANALYZE THIS when I didnt understand fully. I CANNNNNOOT;
    */