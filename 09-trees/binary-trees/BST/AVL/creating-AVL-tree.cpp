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
        int NodeHeight(node *root);
        int BalanceFactor(node *root);
        node* LLRotation(node *root);
        node* RRRotation(node *root);
        node* LRRotation(node *root);
        node* RLRotation(node *root);
        node* RecInsert(node *root, int key);
        node* RecDelete(node *root, int key);
        node* FindMin(node *root);
        int Inorder(node *root);
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

// RR Rotation
node* Tree::RRRotation(node *p){
    node *pr = p->rchild;
    node *prl = pr->lchild;

    pr->lchild = p;
    p->rchild = prl;

    p->height = NodeHeight(p);
    pr->height = NodeHeight(pr);

    return pr;
}

// RL Rotation
node* Tree::RLRotation(node *p){
    node *pr = p->rchild;
    node *prl = pr->lchild;

    pr->lchild = prl->rchild;
    p->rchild = prl->lchild;
    prl->rchild = pr;
    prl->lchild = p;

    pr->height = NodeHeight(pr);
    p->height = NodeHeight(p);
    prl->height = NodeHeight(prl);

    return prl;
}

// Insert
node* Tree::RecInsert(node *root, int key){
    if(root == nullptr){
        node *temp = new node;
        temp->data = key;
        temp->height = 1;
        temp->lchild = temp->rchild = nullptr;
        return temp;
    }

    if(key < root->data){
        root->lchild = RecInsert(root->lchild, key);
    } else if(key > root->data){
        root->rchild = RecInsert(root->rchild, key);
    } else {
        return root; // no duplicates
    }

    root->height = NodeHeight(root);
    int bf = BalanceFactor(root);

    if(bf == 2 && BalanceFactor(root->lchild) >= 0)
        return LLRotation(root);
    if(bf == 2 && BalanceFactor(root->lchild) == -1)
        return LRRotation(root);
    if(bf == -2 && BalanceFactor(root->rchild) <= 0)
        return RRRotation(root);
    if(bf == -2 && BalanceFactor(root->rchild) == 1)
        return RLRotation(root);

    return root;
}







int main() {
    Tree t1;
    t1.root = t1.RecInsert(t1.root, 50);
    t1.root = t1.RecInsert(t1.root, 10);
    t1.root = t1.RecInsert(t1.root, 20);
    t1.Inorder(t1.root);
    
    return 0;
}
