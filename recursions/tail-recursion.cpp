#include<iostream>


/*
Recursions;
Types of Recursions
Tail Recursion;
*/

// Whenever the last statement of a function is recursive, then it is tail recursion;
// As we know, the difference between a loop and recursion is returning something in recursion where its only calling in loops. 




class Recursion{
    public:
        void tailRecursion(int n) const;
        void tailRecinLoop(int n) const;
};

// This is a tail recursion, there is nothing to call after the last statement which is recursive
void Recursion::tailRecursion(int n) const
{
    if(n > 0){
        std::cout << n;
        tailRecursion(n-1);
    }

}

// We can easily convert a tail recursion into loop. LET'S SEE.

void Recursion::tailRecinLoop(int n) const{
    while (n > 0){
        std::cout << n;
        n--;
    }
}


int main(){

    Recursion r1;
    r1.tailRecursion(3); //Outpt: 321
    r1.tailRecinLoop(3); // Outpt: 321
     
    return 0;
}

// Time Complexity: In tail recursion: The time complexity depends on n, so in here n = 3 and we made a call of O(n); In loop, on other hand, we made the same thing with minor differences, 
// so tail recursion in loop and recursive are both O(n);
// But if we talk about space(actually, activation recall), the recursive gets a frame on each call of n-1, where the loop gets only one frame. 
// So, the loop consumes an O(1) of space where recursion consumes O(n);
// As a result, we can say that Loop is more efficient in case of space than Recursion