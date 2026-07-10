#include<iostream>
using namespace std;

// Power of m to n;


// When using recursion, the logic is simple, triggering the n to become 0 so it returns 1, and the recursive calls when descending, they multiply starting with one.
// using recursion: worst case
// 2^3 = 2 * 2 * 2 = 8, so its m * m * m * ... * (n-1) * m;
// This implementation is the worst case implementation, it uses O(n) for both space(n+1 stack frame) and time(n+1 calls) complexity.
int pow(int m, int n){
    if(n == 0){
        return 1;
    }
    return pow(m,n-1)*m;
}

// If we think logically, we can break down problem to half. so, if we have 2^8, we can make it 4^4, so we did (2*2)^8/2 so it is (m*m)^n/2 if n is even;
// and if n is odd, such as 2^9, we can make it 2 * (2*2)^4. so it is m *(m*m, n-1/2);  Let's see in code;
int pow2(int m, int n){
    if (n == 0){
        return 1;
    }
    if (n % 2 == 0){
    return pow2(m*m, n/2);
    }
    else{
        return m * pow2(m*m, (n-1)/2);
    }
    // This function reduces our operations almost in half for both time and space. so if we have 2^9, we make 6 multiplication operations, instead of 9; which is a gain in memory and timel; 
}


// using loop
// This function is way more efficient in terms of space. as its time complx. is O(n), but space complx. is O(1) coz, we only take one frame in stack and it stores 4 varaibles;
int usingloop(int m, int n){
    int i, p = 1;           // 2 steps
    for (i = 1; i<=n; i++){ // n+1 steps
        p = p * m;          // n steps
    }
    return p;               //1 step
}

int main(){

    int result = pow(2, 10);
    int result2 = pow2(2, 10);
    int result3 = usingloop(2, 10);
    cout << result << endl; 
    cout << result2 << endl;
    cout << result3 << endl;

    return 0;
}
