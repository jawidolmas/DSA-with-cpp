#include<iostream>

// This function shows an implementation of local variable in a recusrsion. 
// Local varaibles get its own copy on each frame of new calls. for example the x belong to fun(3) is not equal or belong to x of fun(4);
// We may assume that x increments on each call and the final result is 25, but NO, x gets a brand new copy of x = 0 on each activation recall. 
int fun(int n){
    int x = 0;
    if (n>0){
        x++;
     return fun(n-1) + x; 
    }
    return 0;
}

// For solving the problem in function fun(int n); we will use static variable. static and global variables stores in code section of the 
// memory, not in stack or heap. They do not get a copy on each frame and they remain with thier one original copy in code section regardless of any update.
int fun2(int n){
    static int x = 0;
    if(n>0){
        x++;
        return fun2(n-1) + x;
    }
    return 0;
}

int main(){

    int a = 5;
    std::cout << fun(a);   // output: 5
    std::cout << fun2(a); // output: 25

    return 0;
}