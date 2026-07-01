#include<iostream>
using namespace std;


// Funtions, passing by value, passing by address, passing by reference(c++ only);
// Funtions are used for grouping the instructions of a program. Simply breaking the solutions into small steps. It is called modular/procedure programming. 
// passing by value, is simply the main function passing a copy of its values inside the function. 
// passing by address is simply passing the address of the value into function so the function be able to modify it. it connects to main indirectly.
// passing by reference only exist in C++, has a simple sytanx and works instead of passing by address. It works as a part of main function. 


//Function:
// This is a function and also passing by value. it does not modify the values in main, it only add them up.
int sum(int a, int b){
    int c; 
    c = a + b;
    return c;
}


void swap(int num1, int num2){

    int temp;
    temp = num1;
    num1 = num2;
    num2 = temp;
}

// passing by address
void realSwap(int *ptr1, int *ptr2)
{
    int temp;
    temp = *ptr1;
    *ptr1 = *ptr2;
    *ptr2 = temp;
}

// passing by reference

void swapByReference(int &num1, int &num2){

    int temp;
    temp = num1;
    num1 = num2;
    num2 = temp;
}

int main(){

    int x = 10;
    int y = 20;
    int z = sum(x, y);
    cout << z << endl;  //output: 30;

    swap(x, y); // the x and y is still the same values as main is passing the value, so the swap() function cannot modify the values.
    realSwap(&x, &y); // we are passing the x and y by address so the function realSwap() is now able to modify and x and y which now x=20, y=10;
    cout << x << endl << y<< endl;
    swapByReference(x, y); // this also changes or modifies the value of x and y. because swapByReference() is now a part of main function, which is directly touching the values. 

    return 0;
}