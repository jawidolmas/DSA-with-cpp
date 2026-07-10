#include<iostream>


/*
Recursions;
Types of Recursions
TREE Recursion;
*/

// Whenever we have more than one recursive call in a function, then it is a tree recursion.
// Tree recursion is one of most space and time consuming recursions. The reason for this claim is, that it gets stack for each recursive call, 
// for example, if we take a tree recursion function which has 2 recursive call with only an n = 3, we may have 14-15 stack frame. 
// We all know that recursion is always carries tree policy. 

class Recursion{
    public:
        void treeRecursion(int n) const;
};


// This function has 2 recursive call and its  a tree recursion. 
// In this function, we have 3 statements, 1. printing, first rec, second rec. 
// The execution will start with 1st statement, then it will finish the second statement and return, after that, it will jump to the 3rd statement, and once finished, it will return to root. 
void Recursion::treeRecursion(int n) const{
    if (n > 0){
        std::cout << n;
        treeRecursion(n-1);
        treeRecursion(n-1);
    }

    // In this function, we will create 15 activation recall in stack for n=3, so if we see the tree, the calls will go from root to child, 1 + 2 + 4 + 8 = 15;
    // when n = 3, then calls will be 15, so it goes with 2^0 + 2^1 + 2^2 + 2^3 = 15. in fact, for n, it is 2^n+1 - 1, so for 3, 2^4 -1 = 15;
    // So, we can conclude that the time complexity for this func is O(2^n);
    // What about space complexity? Space complexity is the height of tree, in here it is 4, so for 3, it is 4, in that case for n it is n+1;
    // We can conclude that space complexity is O(n);
} 

/*
    void linearRec(int n){
        if (n>0){
        std::cout << n;
        linearRec(n-1);
        std::cout << "This is neither head, not tail, it is normal linear recursion\n";
        }
        std::cout << "Got it?\n";
    }

*/

int main(){

    Recursion r1;
    r1.treeRecursion(3);  // output: 3211211
    return 0;
}
