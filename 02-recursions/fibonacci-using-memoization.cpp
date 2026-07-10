#include<iostream>
using namespace std;

/* Fibonacci series

    Fibonacci series are an important Discrete Mathematics content.
    Fibonacci numbers are shown with F and is: Every number n, is the sum of two previous numbers, n-1 + n-2. which mathematically: F(n) = F(n-1) + F(n-2);

*/

// Recursive function | Execessive Recursive. O(2^n);
// This function calls itself recursively 2 times and we can declare as 2fibo(n-1), so it is O(2^n);
/*
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
*/ 
// We have implemented both of the functions for fibonacci series, the recursive function was O(2^n);
// Can we really reduce the complexity? is it really possible? YES, IT IS. 
// Logically, if we look carefully, we call function 2 times recursively, do we need that? at least do we need to call each of them one by one until its end? NO.
// Actually, we call some of the calls twice, for example, in fib(5), we calculate fib(3) and fib(4), so these both calls will calculate fib of 0, 1, 2, 3, so that means we calculate them twice. 
// Why shouldnt we calculate them only once, maybe using a static variable, to storing the data from past calls? How about an array to store index by index that which term did we already calculate?
// something like: fib: -1 -1 -1 -1 -1 -1   // we used -1 here inside array coz we dont know what will be inside that index.
//                 n  :  0  1  2  3  4  5   // in this way, if we calculate fib(3) in first call, we will not need to calculate it again, coz we already stored it in index 3 of array;

// For this method, we call it MEMOIZATION METHOD. 
// So here we go:

int Storage[10]; // global variable for storing the calculated terms; as we discussed, we need to fill this with -1, for conveineicy we will do it in main();

int Fibonacci(int n){
    if (n <= 1){
        Storage[n] = n;
        return n;
    }else{
        if (Storage[n-2] == -1){ // means we dont know what is there in storage[n-2];
            Storage[n-2] = Fibonacci(n-2); }
        if (Storage[n-1] == -1){
            Storage[n-1] = Fibonacci(n-1);
        }
        return Storage[n-1] + Storage[n-2];
    }  // So, here we saved our time by not calculating the terms that we already have calculated them. so the complexity is O(n) here.
}




int main(){

    // Filling storage[10] with -1;
    for(int i = 0; i<10; i++){
        Storage[i] = -1;
    }
    cout << Fibonacci(10);  // O/P: 55;


    return 0;
}
