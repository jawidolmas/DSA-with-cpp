#include<iostream>


/*Write a recursive function that returns how many digits an integer has.

Example
Input: 48291

Output:
5

Edge case:

Input: 0

Output:
1
*/
class Recursion{
    private:
        int number;
    public:
        Recursion() : number(0){}
        int numberofDigits(int n) const;
};

int Recursion::numberofDigits(int n) const{
   
    if (n >= 0 && n <= 9){
        return 1;
    }
    return 1 + numberofDigits(n / 10);
}




int main(){

    Recursion r1;
    int a = 48291;
    std::cout << r1.numberofDigits(a);
    return 0;
}