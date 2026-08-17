#include <iostream>
using namespace std;

              
class node{
public:
    node *lchild;
    int data;
    int height;
    node *rchild;
};
        /*
            Binary Search Trees:
                    AVL trees: AVL(Adelson–Velsky and Landis) surnames of 2 inventors of AVL tree. 
                    AVL trees are hieght balanaced binary search trees. it means, the hieght of a binary tree should be balanced. HOW?
                    There is a formula called Balance Factor, and the result of Balance factor can be -1, 0, 1, anything bigger than these are imbalanced BST. 
                    We take the absloute value so the formula becomes
                    
                    Balance Facotr = |Hieght of Left Child - Height of Right child| <= 1, then it is balanced.

                    so what if it is > 1 ? then we need to balance them by using rotations. Left Left rotation, RR rotation, LR rotation, and RL rotaion, we can name 
                    them anything we want, like clockwise or counterclockwise. it depends on you. 

                    We will code an insertion, in a balanced tree we will add a key which makes the tree imbalanced, then we will call a function to make it balanced.

                    Let's code. 
        */



class Tree{
    public:
        node *root;  

        Tree();
        node* RecInsert(node *root, int key);
        int Inorder(node *root);
        int NodeHeight(node *root);
        int BalanceFactor(node *root);
        node* LLRotation(node *root);
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

// Node height
int Tree::NodeHeight(node *root){
    int hl, hr;
    hl = root && root->lchild?root->lchild->height:0;
    hr = root && root->rchild?root->rchild->height:0;

    return hl>hr?hl+1:hr+1;
}

// Balance Factor
int Tree::BalanceFactor(node *root){
    int hl, hr;
    hl = root && root->lchild?root->lchild->height:0;
    hr = root && root->rchild?root->rchild->height:0;

    return hl-hr;
}

// Left-Left Rotation
node* Tree::LLRotation(node *root){
    node *p = root;
    node *pl = p->lchild;
    node *plr = pl->rchild;

    pl->rchild = p;
    p->lchild = plr;
    p->height = NodeHeight(p);
    pl->height = NodeHeight(pl);

    return pl;
}       

// Insert
node* Tree::RecInsert(node* root, int key){
    node *temp = nullptr;
    if(root == nullptr){
        temp = new node;
        temp->data = key;
        temp->height = 1;
        temp->lchild = temp->rchild = nullptr;
        return temp;
    }
    if(root->data < key){
        root->rchild = RecInsert(root->rchild, key);
    }else if(root->data > key){
        root->lchild = RecInsert(root->lchild, key);
    }

    if(BalanceFactor(root) == 2 && BalanceFactor(root->lchild) == 1){
        return LLRotation(root);
    }
    return root;
}







int main() {
    Tree t1;
    t1.root = t1.RecInsert(t1.root, 20);
    t1.root = t1.RecInsert(t1.root, 10);
    t1.root = t1.RecInsert(t1.root, 5);
    t1.Inorder(t1.root);
    t1.root = t1.LLRotation(t1.root);
    
    return 0;
}

/*
        In fact, the root should be 20, then lchild 10 then lchild 5, but after running LLRotation, the root is 10, 20 is rchild and 5 is lchild. 
        You can debugg it and can see in local variables section.

*/
    /*



        ANALYSIS:   
            Functions used in here:
            NodeHeight(): O(1) in time and space, does 2 operations of if and else condition and returns in a condition. 
            BalanceFacotr(): O(1) in time and space, same operations as NodeHeight() and returns in a condition
            LLRotation(): O(1) in time and space, does a few opeartion as similar to swap algorithm, and returns root;
            RecInsert(): O(logn) in both time and space, coz they do work recursively and on each call they do it again and again, which runs for hieght of tree.
            it also gets O(logn) stack depth so it is O(logn) in space too.
            height of tree is logn minimum and in most of the case, in AVL it is strict logn.
  
    */