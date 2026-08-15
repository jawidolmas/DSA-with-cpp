#include <iostream>
using namespace std;

#include "Stack.hpp"           
                               

        /*
            Binary Search Trees:
                Generating BST with only preorder. 
                    *We have learned that if a preorder, postorder, or inorder given, we cannot generate a unique binary tree, there will be catalan numbers of 
                    trees, but CAN WE REALLY GENERATE A BINARY SEARCH TREE from given only postorder or preorder? we also said that preorder+inorder or postorder+inorder 
                    can generate a unique binary tree. So, can we generate binary search tree with only post or pre order? YEAH, thanks to the property of BST that 
                    are always inorder. so if an array like 30 20 10 15 50 80 60 given, we know what is the inorder of this BST, it is 10 15 20 30 50 60 80, isnt it. 
                    So according to this feature of BST, we can generate BST using only pre or post order. 

                    If preorder given, we start i with first which shows its root. if postorder given, we start i with last index which shows the root of tree. 

                    For both of them, we will use stack to save the address of some nodes. we will see it in code.
        */



class Tree{
    public:
        node *root;  
        StackArray stk{100};

        Tree();
        node* Insert(int key);
        void createPre(int Arr[], int size);
        int Inorder(node *root);
        void createPost(int Arr[], int size);
};


Tree::Tree(){
    root = nullptr;
}


// Inorder
int Tree::Inorder(node* root){
    if(root != nullptr){
        Inorder(root->lchild);
        cout << root->data << " ";
        Inorder(root->rchild);
    }
    return 0;
}

// Generating a BST using preorder
void Tree::createPre(int Arr[], int size){
    node *temp, *p;
    int i = 0;
    root = new node;
    root->data = Arr[i++];
    root->lchild = root->rchild = nullptr;
    p = root;
    while(i < size){
        if(Arr[i] < p->data){
            temp = new node;
            temp->data = Arr[i++];
            temp->lchild = temp->rchild = nullptr;
            p->lchild = temp;
            stk.push(p);
            p = temp;
        }
        else{
            if((Arr[i] > p->data) && (Arr[i] < (stk.isEmpty() ? INT_MAX : stk.stackTop()->data))){
                temp = new node;
                temp->data = Arr[i++];
                temp->lchild = temp->rchild = nullptr;
                p->rchild = temp;
                p=temp;
            }else{
                p = stk.pop();
            }
        }
    }
}

// Generating a BST using preorder
void Tree::createPost(int Arr[], int size){
    node *temp, *p;
    int i = size-1;
    if(size <= 0){
        root = nullptr;
        return;
    }
    root = new node;
    root->data = Arr[i--];
    root->lchild = root->rchild = nullptr;
    p = root;
    while(i >= 0){
        if(Arr[i] > p->data){
            temp = new node;
            temp->data = Arr[i--];
            temp->lchild = temp->rchild = nullptr;
            p->rchild = temp;
            stk.push(p);
            p = temp;
        }
        else{
            if((Arr[i] < p->data) && (Arr[i] > (stk.isEmpty() ? INT_MIN : stk.stackTop()->data))){
                temp = new node;
                temp->data = Arr[i--];
                temp->lchild = temp->rchild = nullptr;
                p->lchild = temp;
                p=temp;
            }else{
                p = stk.pop();
            }
        }
    }
}






int main() {
    Tree t1, t2;
    int A[8] = {30, 20, 10, 15, 25, 40, 50, 45};
    int Ar[8] = {15, 10, 25, 20, 45, 50, 40, 30};
    t1.createPre(A, 8);
    t2.createPost(Ar, 8);
    t1.Inorder(t1.root);
    cout << endl;
    t2.Inorder(t2.root);
    return 0;
}

/*
        ANALYSIS:
            In both createPre() and createPost(), the time complexity does NOT depend on the height of the
            tree like search does. These functions read every element of the input array exactly once (i moves
            forward/backward by one index per node created), and the loop only ends once all n elements are
            consumed. So no matter whether the tree being built turns out balanced or skewed, the number of
            iterations is always tied to n. Hence both functions are O(n) in terms of time, same in best case
            and worst case, there's no logn/n split here since there's no early exit, every element has to be
            placed somewhere in the tree.

            If we come to space complexity, here it does depend on height, just like the recursive search does.
            The stack (stk) holds the chain of ancestor nodes that might still need a child attached later, and
            this chain length grows and shrinks with the height of the tree as it's being built, same as a
            recursive call stack would. So space is O(h), h is best case logn, so both functions are O(logn) in
            terms of space in the best case, coz the stack holds logn nodes at most. In worst case (skewed tree,
            e.g. already sorted input), h becomes n, so space becomes O(n).
    */