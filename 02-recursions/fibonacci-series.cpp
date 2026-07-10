#include<iostream>
using namespace std;

/* Fibonacci series

    Fibonacci series are an important Discrete Mathematics content.
    Fibonacci numbers are shown with F and is: Every number n, is the sum of two previous numbers, n-1 + n-2. which mathematically: F(n) = F(n-1) + F(n-2);

*/

// Recursive function | Execessive Recursive. O(2^n);
// This function calls itself recursively 2 times and we can declare as 2fibo(n-1), so it is O(2^n);
int fibo(int n){

    if (n == 0){
        return (0);
    }
    if (n == 1){
        return (1);
    }
    return fibo(n-1) + fibo(n-2);
}

// Using loop; | O(n);
int usingloop(int n){

    if(n<=1){
        return (1);
    }
    int t0=0, t1 = 1, sum = 0; // 1 step
    for (int i =2; i<=n; i++){ // n steps
        sum = t0 + t1;          // n-1 steps
        t0 = t1;                // n -1 steps
        t1 = sum;               // n-1 steps
    }
    return sum;
}

int main(){

    cout << fibo(10) << endl;  //O/P = 55;
    cout << usingloop(10);     //O/P = 55;
    return 0;
}
