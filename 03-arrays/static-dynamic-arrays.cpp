#include<iostream>
using namespace std;

// Static vs Dynamic arrays;

// Statis arrays are arrays that gets memory from stack, and they are static;
// Dynamic arrays are allocating memory in heap, using a pointer.

// We can change the size of Dynamic array using methods, but static arrays can never be modified after running.



int main()
{
    int A[5] = {1, 2, 3, 4, 5}; // static;
    
    // We can init. the dynamic array as static. assume the pointer P is the name of array;
    int *p;
    p = new int[5]; // Dynamic;
    p[0] = 2;
    p[1] = 5;
    p[2] = 7;
    p[3] = 9;
    p[4] = 11;

    // We also can access both Dynamic and Static in a same way;
    for (int i = 0; i<5; i++){
        cout << A[i] << " ";
    }
    cout << endl;
    for ( int i=0; i<5; i++){
        cout << p[i] << " ";
    }
    return 0;
}


// In cpp, the size of array will be decided in runtime; but in C lang, the size of array will be decided in compile time;

/* lets see diff:

C lang.
int n;
scanf("%d", &n);
int Arr[n];
-This is impossible in C lang, because it needs to be decided in compile time, not while running;

C++.
int n;
cin >> n;
int Arr[n];

-This is possible, becuase in Cpp, it will be decided in run time. 

*/