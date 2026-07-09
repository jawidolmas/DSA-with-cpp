#include<iostream>


/*
Recursions;
Types of Recursions
Nested Recursion;
*/

// Nested recursion is a type of recursion which recursive call has recursive call as a parameter.

class Recursion{
    public:
        int NestedRecursion(int n);
};

int Recursion::NestedRecursion(int n){
    if (n>100){
        return n - 10;
    }
    else{
        return NestedRecursion(NestedRecursion(n+11));
        // This function calculates two recursive call until the condition fails, the inner recursive calculates and  returns a value which then outer recursive uses it.
    }
}



int main(){

    Recursion r1;
    // We call only function A, it indirectly calls function B to solve our problem
    int result = r1.NestedRecursion(95);  // output: 201998431
    std::cout << result; // the functions run until the inner recursive becomes 101 and when it goes to outer recursive, it will be 101 > 100, which is true. it doesnt enter the "else" and returns 101-10 = 91. so O/P: 91
    return 0;
}
