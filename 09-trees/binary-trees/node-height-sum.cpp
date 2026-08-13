

    /*
        Tree:
            Binary Tree:
                Counting nodes, height of tree, sum of nodes
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
        int count(node *root) const;
        int height(node *root) const;
        int sum(node *root) const;
        int Sum() const{
            return sum(root);
        };
        int Height() const{
            return height(root);
        };
        int Count() const{
           return  count(root);
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

// Counting nodes
int Tree::count(node *root) const{
    int x = 0, y = 0;
    if(root != nullptr){
        x = count(root->lchild);
        y = count(root->rchild);
        return x + y + 1;
    }
    return 0;
}

// Height of a tree
int Tree::height(node *root) const{
        int x = 0, y = 0;
        if(root == nullptr){
            return 0;
        }else{
            x = height(root->lchild);
            y = height(root->rchild);
            if(x > y){
                return x + 1;
            }
            else{
                return y + 1;
            }
        }
}

// Sum of values in node
int Tree::sum(node *root) const{
    int x = 0, y = 0;
    if(root != nullptr){
        x = sum(root->lchild);
        y = sum(root->rchild);
        return x + y + root->data;
    }
    return 0;
}


int main()
{
    Tree t1;
    t1.createBinTree();
    cout << t1.Count() << endl;
    cout << t1.Sum() << endl;
    cout << t1.Height() << endl;

    return 0;
}


/*
    Output:
            7       nodes
            260     sum
            4       height

*/


/*
    ANALYSIS:
       Preorder:
            All of these three functions are O(n) in terms of time and space. because it is recursive and runs for n times. 
*/