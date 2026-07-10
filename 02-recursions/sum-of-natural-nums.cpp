#include<iostream>
using namespace std;
// Sum of first N natural numbers;

// using direct mathematical formula
// This method is the fastest methon. both in space and time complexity. it takes only on varaible for space which is O(1). 
// It also does 3 operations, one multiply, one addition of n+1, and one division. so it costs 3 so its O(1);
int sumofNaturalNumbers(int n){

    if (n == 0){
        return 0;
    }
    else{
    return n*(n+1)/2;
}
}

// using recursion
// This method costs the most. this is recursion and it takes n+1 stack frame and n+1 calls, which both time and space complx. is O(n); 
int usingRecursion(int n){
    if (n == 0){
        return 0;
    }else{
        return usingRecursion(n-1)+n;
    }
}

// Using iterative loop
// This method is second fastest, it takes 3 int variables so its O(1) for space. and for time it is O(n), as shown below in function;
int usingLoop(int n){
    int i, s=0;             // 1 step
    for(i = 1; i<=n; i++){ // Usually, a loop is n+1 steps;
        s = s + i;         // it does n steps, on each iteration of i, it sums up. 
    }
    return s;             // 1 step
 } // SO this func is Order of n;


int main(){

    int result = sumofNaturalNumbers(25);
    int result1 = usingRecursion(25);
    int result2 = usingLoop(25);
    cout << result << endl << result1 << endl << result2 << endl;
    return 0;
}
