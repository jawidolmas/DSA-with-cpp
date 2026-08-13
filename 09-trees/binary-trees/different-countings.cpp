

    /*
        Tree:
            Binary Tree:
                Counting leaf node, node with deg1, node with deg 2;


            ***SUPER IMPORTANT STATEMENTS FOR BINARY TREE COUNTINGS.
                1. Leaf node deg(0): if(!p->lchild && !p->rchild)

                2. node with deg(2): if(p->lchild && p->rchild)

                3. node with deg(1, 2): if(p->lchild || p->rchild)

                4. node with deg(1): if((p->lchil && !p->rchild) || (!p->lchild && p->rchild))   THIS IS EXCLUSIVE OR. means XOR. Do we have any XOR symbol in CPP? yeah;
                    XOR symbole: ^;  if(p->lchild ^ p->rchild) 


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
        int countLeaf(node *root) const;
        int countwith1(node *root) const;
        int countwith1or2(node *root) const;
        int countwith2(node *root) const;
        int Leaf() const{
            return countLeaf(root);
        };
        int only1() const{
            return countwith1(root);
        };
        int only2() const{
           return  countwith2(root);
        };
        int oneORtwo() const{
           return  countwith1or2(root);
        };
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

// Leaf node
int Tree::countLeaf(node *root) const{
    int x = 0, y = 0;
    if(root != nullptr){
        x = countLeaf(root->lchild);
        y = countLeaf(root->rchild);
        if(!root->lchild && !root->rchild){
            return x + y + 1;
        }else{
            return x + y;
        }
    }
    return 0;
}


// Node with deg 2
int Tree::countwith2(node *root) const{
    int x = 0, y = 0;
    if(root != nullptr){
        x = countwith2(root->lchild);
        y = countwith2(root->rchild);
        if(root->lchild && root->rchild){
            return x + y + 1;
        }else{
            return x + y;
        }
    }
    return 0;
}

// Node with deg 1
int Tree::countwith1(node *root) const{
    int x = 0, y = 0;
    if(root != nullptr){
        x = countwith1(root->lchild);
        y = countwith1(root->rchild);
        if ( (root->lchild != nullptr) ^ (root->rchild != nullptr) ) {      // XOR ^ opeartor does not work on raw pointers, it works on integer, so we converted it to bool(nullptr/not nullptr);
            return x + y + 1;
        }else{
            return x + y;
        }
    }
    return 0;
}

// Node with deg 1 or 2
int Tree::countwith1or2(node *root) const{
    int x = 0, y = 0;
    if(root != nullptr){
        x = countwith1or2(root->lchild);
        y = countwith1or2(root->rchild);
        if(root->lchild || root->rchild){
            return x + y + 1;
        }else{
            return x + y;
        }
    }
    return 0;
}


int main()
{
    Tree t1;
    t1.createBinTree();
    cout << "Leaf: "<<t1.Leaf() << endl;
    cout << "Deg(1): "<<t1.only1() << endl;
    cout << "Deg(2): "<< t1.only2() << endl;
    cout << "Deg(1 or 2): "<< t1.oneORtwo() << endl;

    return 0;
}


/*
    Output:
            Enter Root Node: 10
            Enter left child of 10: 20
            Enter right child of 10: 30
            Enter left child of 20: -1
            Enter right child of 20: -1
            Enter left child of 30: -1
            Enter right child of 30: -1
            
            Leaf: 2
            Deg(1): 0
            Deg(2): 1
            Deg(1 or 2): 1

*/


/*
    ANALYSIS:
       Preorder:
            All of these three functions are O(n) in terms of time and space. because it is recursive and runs for n times. 
*/