#include<iostream>


/*Write a recursive function that returns the reversed number.

Example
Input:
12345

Output:
54321

Restrictions:

No strings.
No arrays.
No global variables.
1
*/
class Recursion{
    public:
        int reverseNumber(int n, int result);
};

int Recursion::reverseNumber(int n, int result = 0){
   if (n >= 0 && n <= 9){
    return result * 10 + n;
   }
   return reverseNumber(n / 10, result * 10 + n % 10);
}



int main(){

    Recursion r1;
    int a = 3;
    std::cout << r1.reverseNumber(a);
    
    return 0;
}