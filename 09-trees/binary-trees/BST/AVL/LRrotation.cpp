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
                    Left-Right Rotation
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
        node *LRRotation(node *root);
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

// Left-Right Rotation
node* Tree::LRRotation(node *root){
    node *p = root;
    node *pl = p->lchild;
    node *plr = pl->rchild;
    pl->rchild = plr->lchild;
    p->lchild = plr->rchild;
    plr->lchild = pl;
    plr->rchild = p;

    pl->height = NodeHeight(pl);
    p->height = NodeHeight(p);
    plr->height = NodeHeight(plr);


    return plr;
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
    }else if(BalanceFactor(root) == 2 && BalanceFactor(root->lchild) == -1){
        return LRRotation(root);    
    }
    return root;
}







int main() {
    Tree t1;
    t1.root = t1.RecInsert(t1.root, 50);
    t1.root = t1.RecInsert(t1.root, 10);
    t1.root = t1.RecInsert(t1.root, 20);
    t1.Inorder(t1.root);
    t1.root = t1.LRRotation(t1.root);
    
    return 0;
}

/*
        In fact, the root should be 50, then lchild 10 then lchild of 10,  20, but after running LRRotation, the root is 20, 50 is rchild and 10 is lchild. 
        You can debugg it and can see in local variables section.

*/
    /*



        ANALYSIS:   
            Functions used in here:
            LRRotation(): O(1) in time and space, does a few opeartion as similar to swap algorithm, and returns root;
  
    */