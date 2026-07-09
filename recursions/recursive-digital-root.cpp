#include<iostream>
using namespace std;

/*Write a recursive function that repeatedly sums the digits of a number until only one digit remains.

Example
Input: 9875
Output:2

Explanation: 9875 = 9+8+7+5 = 29

29 = 2+9 = 11

11 = 1+1 = 2

Restrictions:
No loops inside the recursive function.
No strings.
No arrays.*/

int sumDigits(int n){
    if(n == 0){         // The base case for when to stop summing, when there is no number left. 
        return 0;
    }
    int temp = n % 10;
    return temp + sumDigits(n/10);
}

int digitalRoot(int n){     // Checking the condition of task, if the summation is a digit or not yet a digit.
    if (n < 10){            // think simply, when a number n will be a digit, when its smaller than 10.
        return n;
    }
    int result = sumDigits(n);  // if not <10, then call summation and tell him to sum it up. 
    return digitalRoot(result); // then recheck it, if its still not a digit, re-run the sumDigits, if it is a digit, then simply return n; 
}

int main(){
    
    int sum = digitalRoot(9875);
    cout << sum;

    return 0;
}
