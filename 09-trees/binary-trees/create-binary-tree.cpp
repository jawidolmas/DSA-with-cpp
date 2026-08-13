

    /*
        Tree:
            Binary Tree:
                Creating Binary Tree
    
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


int main()
{
    Tree t1;
    t1.createBinTree();


    return 0;
}


/*
    Output:

        Enter Root Node: 10
        Enter left child of 10: 20
        Enter right child of 10: 30
        Enter left child of 20: 40
        Enter right child of 20: 60
        Enter left child of 30: 80
        Enter right child of 30: 90
        Enter left child of 40: -1
        Enter right child of 40: -1
        Enter left child of 60: -1
        Enter right child of 60: -1
        Enter left child of 80: -1
        Enter right child of 80: -1
        Enter left child of 90: -1
        Enter right child of 90: -1


*/


/*
    ANALYSIS:
        CreateBinTree:
            This function is O(n) in terms of time. At the start of the program, it does some contant steps of work, and calls the enqueue function from Queue.hpp header
            file, which it all depeneds on Queue file enqueue function, by the way, enqueue function is also implemented in O(1). After first initializations, the program
            enters the while loop, at while loop, it does two things, adds the left child and right child of tree respectively, and it does this work until the Queue gets 
            empty. Queue being empty is completely depends on user that how elements will this binary tree can have, so let n be the user created nodes for each child of tree.
            Then, the program does n steps of work. so this is O(n). 

            Also, we have constant amount of space allocated within this function. However, if we look carefully, we allocated a 100 sized array in memory for Queue list.
            The user can add n nodes and n nodes address' will enter the queue. 
            if we consider all of them as a program, then this program takes O(n) of space complexity as well as time. 



*/