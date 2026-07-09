#include<iostream>


/*
Recursions;
Types of Recursions
Indirect Recursion;
*/

// Indirect recursion is a type of recursion which where more than one function calls each other and creates a cycle to solve a problem.
// A-> B-> C-> A

class Recursion{
    public:
        void indirectRecursionA(int n) const;
        void indirectRecursionB(int n) const;
};

void Recursion::indirectRecursionA(int n) const{
        if (n > 0){
            std::cout << n;
            indirectRecursionB(n-1);
        }
}

void Recursion::indirectRecursionB(int n) const{
        if(n>1){
            std::cout << n;
            indirectRecursionA(n/2);
        }
}




int main(){

    Recursion r1;
    // We call only function A, it indirectly calls function B to solve our problem
    r1.indirectRecursionA(20);  // output: 201998431
    return 0;
}
