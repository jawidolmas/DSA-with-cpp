#include<iostream>
using namespace std;

/* 
     Combinations - nCr;

     combination is the distributing, when the order is not important. 
     For example: ABC, ABD, BDS, ACBx-> This cannot happen, coz we already have ABC, so ABC and ACB are both same.
     The formula for combinations is: n!/r!*(n-r)!
     as the formula given, we can use direct forumal with one statement which is return formula; but HOW ABOUT FACTORIALS?
     we will use two functions, one for factorial and the other for combination.
     We know from high school, that, for nCr, r can be minimum 0 and max n; so 0 =< r >= n ;
*/

// Factorial

int fact(int n){
    if (n==0){
        return 1;
    }
    return fact(n-1)*n;
}

// Now, we will use the fact() functino to use the direct formula for combination;

int combination(int n, int r){  // Complexity: O(n)
    // We will take 3 varaibles for factorials of followings coz we need in formula, for n, for r and for n-r;
    int t1, t2, t3;
    t1 = fact(n);
    t2 = fact(r);
    t3 = fact(n-r);
    return t1/t2*t3;

}

// Now, can we directly write a recursive function for combination without using direct formula? YES!
// Thanks to Pascal's Traingle. We ALSO know from high school, that, the addition of Pascal's terms gives the combination of those values. 
// So, we absloutely can have a recursive function without using mathematical formula of combination;

int directRecursion(int n, int r){  // Compelexity: Space: O(n)  Time: O(2^n);
    if (r == 0 || n == r){
    return 1;
    }
    else{
    return directRecursion(n-1, r-1) + directRecursion(n-1, r);
}
}

int main(){

    cout << directRecursion(5, 3);  // O/P: 10;


    return 0;
}
