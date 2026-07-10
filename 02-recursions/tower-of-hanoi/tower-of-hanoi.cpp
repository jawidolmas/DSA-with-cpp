#include<iostream>
using namespace std;

/*
Tower of Hanoi Problem
----------------------
We have three rods (pegs): Source (A), Auxiliary (B), Destination (C),
and n disks of different sizes initially stacked on A in decreasing size
(largest at bottom, smallest at top).

Goal: Move the entire stack from rod A to rod C.

Rules:
1. Only one disk can be moved at a time.
2. Only the top disk of any rod can be moved.
3. A larger disk can never be placed on top of a smaller disk.

Recursive idea (for n disks from A to C using B):
- We will move n-1 disks from A to B (using C as auxiliary).
- Then, move the largest disk from A to C.
- and finally move the n-1 disks from B to C (using A as auxiliary).

Base case:
- If n == 1, just move the single disk directly from source to destination.

Time complexity: O(2^n) moves (minimum number of moves is 2^n - 1).
Space complexity: O(n) due to recursion stack.

This is a classic example of recursion and divide-and-conquer.

Before, this problem was known us with no solution, which is impossible to solve. Thanks to recursion, it helped to solve a probem easily than it seem. 
*/


void TOH(int n, int a, int b, int c){
    if (n>0){
        TOH(n-1, a, c, b);
        cout << "Take disk From " << a << " To " << c << " and then, "<< endl;
        TOH(n-1, b, a, c); 
    }
}




int main(){

    TOH(3, 1, 2, 3); // O/P: 10;
    cout << "Thats it, you are done with a problem that seems impossible\n";

    return 0;
}
