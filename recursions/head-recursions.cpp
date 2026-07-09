#include<iostream>


/*
Recursions;
Types of Recursions
Head Recursion;
*/

// Whenever the First statement of a function is recursive, then it is head recursion;
// As we know, the difference between a loop and recursion is returning something in recursion where its only calling in loops. 




class Recursion{
    public:
        void headRecursion(int n) const;
        void headRecinLoop(int n) const;
};

// This is a head recursion, the recursive call is the very 1st statement in function.
void Recursion::headRecursion(int n) const
{
    if(n > 0){
        headRecursion(n-1);
        std::cout << n;
    }

}

// We cannot easily implement head recursion using loops, but it is possible. 
/* If we want to directly conver it, then it will not work as recursion works:

    void HeadLoop(int n){
        while (n > 0){
            n--;
            std::cout << n;
            
        }
    
    }
    
    This function prints 210, but expected result was 123; 

*/

// But as we said, its possible to get the same result. 
 void Recursion::headRecinLoop(int n) const{
    int i = 1;
    while ( i <= n){
        std::cout << i;
        i++;
    }
}

    

int main(){

    Recursion r1;
    r1.headRecursion(3);  //Outpt: 123
    r1.headRecinLoop(3);  // Outpt: 123
     
    return 0;
}

// Time Complexity: In head recursion, the time complexity is O(n) as calls are depend on n. In loop, it is also n which i's loop depends on n.
// so head recursion in loop and recursive are both O(n);
// But if we talk about space(actually, activation recall), the recursive gets a frame on each call of n-1, where the loop gets only one frame. 
// So, the loop consumes an O(1) of space where recursion consumes O(n);
// As a result, we can say that Loop is more efficient in case of space than Recursion