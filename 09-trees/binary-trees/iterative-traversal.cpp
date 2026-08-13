

    /*
        Tree:
            Binary Tree:
                Postorder display
    
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
        void IterativePreorder();
        void IterativeInorder();
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

// Inorder Iterative Display
void Tree::IterativePreorder(){
    node *temp = root;
    StackArray stk(100);
    while(temp || !stk.isEmpty()){
        if(temp != nullptr){
            cout << temp->data <<  " ";
            stk.push(temp);
            temp = temp->lchild;
        }else{
            temp = stk.pop();
            temp = temp->rchild;
        }
    }
}

// Inorder Iterative Display
void Tree::IterativeInorder(){
    node *temp = root;
    StackArray stk(100);
    while(temp || !stk.isEmpty()){
        if(temp != nullptr){
            stk.push(temp);
            temp = temp->lchild;
        }else{
            temp = stk.pop();
            cout << temp->data <<  " ";
            temp = temp->rchild;
        }
    }
}


int main()
{
    Tree t1;
    t1.createBinTree();
    t1.IterativePreorder();
    t1.IterativeInorder();
   

    return 0;
}


/*
    Output:
            10 20 30 
            20 10 30 


*/


/*
    ANALYSIS:
       Preorder:
            These functions are O(n) in both time and space complexity. the functions will traverse the tree in Preorder and Inorder algorithm and goes up to n. 
            Also, as these functions uses programmer, it uses stack for height of the tree times which makes space compelexity order of n.
*/