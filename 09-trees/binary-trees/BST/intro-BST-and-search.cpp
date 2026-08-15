#include <iostream>
using namespace std;

#include "Queue.hpp"           
                                // WE USUALLY USE LINKED LIST FOR TREES. SOMETHING WE ALREADY KNOW. 

        /*
            Binary Search Trees:
                Binary search trees are trees that the root will have elements less than itself on left child and greater than itself in right child. 
                Suppose: We have a tree with root 30, then in right child EVERY ELEMENT(data) must be smaller than 30, and EVERY ELEMENT(data) should bigger than 30.
                In fact, it is binary search, as we can see elements are kindda sorted and we search it by comparing the key with element and if not found we go to 
                another half of the list, something like spliting in binary searchs. THIS IS THE REASON WE CALL IT BINARY SEARCH TREES. 

                PROPERTIES OF BINARY SEARCH TREES(BST):
                    1. There will be no duplicate of any element(data)
                    2. Inorder traversal gives sorted list always
                    3. Number of maximum possible BST for n nodes will be catalan number: 2nCn/n+1


                The procedure is simple:
                    We take a key as an input, we check it with root, is it equal, greater, or smaller than root, if equal return root, if smaller than root, go to left
                    child and if bigger than root, go to right child. And continue for this process until the pointer reaches at the end of tree which is null. 

                    We will implement searching in both recursive and iterative ways.

        */



class Tree{
    public:
        node *root;             // public because we use recursive functions and do not want dummy helper functions. 
        Queue q1, q2;   
        Tree();
        void  CreateBinarySearchTree();
        node *RecursiveSearch(node *root, int key);
        node *IterativeSearch(int key);
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

// Recursive Binary Search Tree Searching
node* Tree::RecursiveSearch(node *temp, int key){
    if(temp == nullptr){
        return nullptr;
    }
    if(key == temp->data){
        return temp;
    }else if(key < temp->data){
        return RecursiveSearch(temp->lchild, key);
    }else{
        return RecursiveSearch(temp->rchild, key);
    }
}

// Iterative Binary Search Tree Searching
node* Tree::IterativeSearch(int key){
    node *temp = root;
    while(temp != nullptr){
        if(key == temp->data){
            return temp;
        }else if(key < temp->data){
            temp = temp->lchild;
        }else{
            temp = temp->rchild;
        }
    }
    return nullptr;
}

int main() {
    Tree t1;
    t1.CreateBinarySearchTree();

    node* res1 = t1.RecursiveSearch(t1.root, 25);
    if (res1 != nullptr) {
        cout << "RecursiveSearch found value: " << res1->data
             << " at address: " << static_cast<void*>(res1) << endl;
    } else {
        cout << "RecursiveSearch: not found (nullptr)" << endl;
    }

    node* res2 = t1.IterativeSearch(90);
    if (res2 != nullptr) {
        cout << "IterativeSearch found value: " << res2->data
             << " at address: " << static_cast<void*>(res2) << endl;
    } else {
        cout << "IterativeSearch: not found (nullptr)" << endl;
    }

    return 0;
}

/*
        OUTPUT:
            RecursiveSearch found value: 25 at address: 0x1bbbc496a00
            IterativeSearch found value: 25 at address: 0x1bbbc496a00
*/


    /*
        ANALYSIS:
            In both of the functions, the time complexity depends on height of the tree, suppose h = height then both functions are O(h), in BST, we usually
            take the best case height which is logn, so Recursive function as well as iterative function are O(logn) in terms of time. they can be O(n) in worst case.
            
            If we come to space complexity, the iterative version is simply O(1). but the recursive function again depends on height of the tree and its best and 
            worst case. so the space for recursive is O(h), h is best case logn, so recursive search is O(logn) in terms of space, coz it calls logn times of stack.
    
    */