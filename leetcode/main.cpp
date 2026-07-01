#include<iostream>
using namespace std;


// Structs as parameter


struct test{

    int a;
    int b;
};

// We are passing a struct by value in this function which sums 2 numbers.
int addNumbers(test t2){

    return t2.a + t2.b;
}

// Passing by reference:changes the value:functions as direct code of main()

void changeNumbers(test &t3, int n){
    t3.b = n;  // This function will change the vlaue of b
}


//passing by address

int byAddress(test *t4){

    t4->a = 12; // when passing by address in a struct, we need to use arrow ->. the dot . member access method does not work here. 
    t4->b = 24;
    return t4->a * t4->b;
}

// How passing methods will work when we have an array inside the struct
// An array will always passed by address as the array itself is an address. but when we are dealing with arrays inside struct, then we can pass it by value as well. 
struct withArray{

    int A[5];
    int n;
};

void passByValue(withArray array){
    array.A[0] = 1;
    cout << array.A[0];  // The value in index 0 will not change in main.

}

//passing by address
void func(withArray *ptr){

    ptr->n = 8;  // changes the 7 to 8 in main function.
    cout << ptr->n;
}


int main(){

    test t1 = {1, 3};
    cout << addNumbers(t1);
    changeNumbers(t1, 5); 
    cout << t1.b; // output: 5 
    int x = byAddress(&t1);
    cout << x; // output: 288, which is the product of 12 and 24
    
    withArray arr = {{5, 6, 7, 8, 9}, 7};
    passByValue(arr);
    for (int i = 0; i<5; i++){
        cout << arr.A[i];
    }

    func(&arr);
    
    return 0;
}