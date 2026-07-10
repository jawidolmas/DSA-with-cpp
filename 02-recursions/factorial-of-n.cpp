#include<iostream>
using namespace std;
// Factorial of N nums;
// The complexities are both O(n) in recursion, as they make n calls which takes n frames in stack. so time and space both are O(n);

int factorial(int n){
    if (n == 0){
        return 1;
    } else{
        return factorial(n-1)*n;
    }
}

//using LOOP
// The complexity in here is O(1) for space, which it takes 3 int memory, and time is O(n); 
int usingloop(int n){
    int i, mult=1;
    for(i=1; i<=n; i++){
        mult = mult * i;
    }
    return mult;
}


int main(){

    int result = factorial(5);
    int result1 = usingloop(5);
    cout << result << endl << result1 << endl;
    return 0;
}
