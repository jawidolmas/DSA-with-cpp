#include<iostream>
using namespace std;

/* Tylor series - e^x 

    e^x = 1 + x/1 + x^2/2! + x^3/3! + ..... n terms

    as we can see here, tylor series is combination of factorial, summation, and power(exponentials). We will use these 3 things to solve the problem
    we need to save the result, and variable(power part) as well as number(factorail part), which variables for power and fact should be static, so they should store what they get 
    on each call. 
*/


double e(double x, double n){
    static double p = 1, f = 1;
    double result;
    if(n == 0){
        return (1);
    }
    else{
        result = e(x, n-1);
        p = p * x;
        f = f * n;
        return result + p/f;
    } 
}

int main(){
    
    double final = e(4, 15); // Means e^5 and run it up to 4 terms. 
    cout << final;

    return 0;
}
