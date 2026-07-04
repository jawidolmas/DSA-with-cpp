#include<iostream>


/*Given an integer, recursively return the sum of only even digits.

Example
Input:
48237

Output:
14
*/

class Recursion{
    public:
        int sumOfEven(int n);
};

int Recursion::sumOfEven(int n)
{
    
    if (n == 0){
        return 0;
    }
    int temp = n % 10; 
    if(temp % 2 == 0){
        return temp + sumOfEven(n/10);
    }
    return sumOfEven(n/10);
}


int main(){

    Recursion r1;
    int a = 3234;
    std::cout << r1.sumOfEven(a);  // output: 6; reason: 2+4 = 6
     
    return 0;
}