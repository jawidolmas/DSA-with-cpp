#include<iostream>
using namespace std;

// 2D arrays. 
// In any programming lang, we can have N dimension arrays, but we may use up to 3 dimension if needed.

int main()
{

    // We can create 2D arrays using different methods.
    // 1st method:

    int A[3][4] = {{1, 2, 3, 4}, {5, 6, 7, 8},{9, 10, 11, 12}}; // All in stack
    // we have an array of 3 rows and 4 columns. so how about memory? Do memory save them as rows and columns in 2D? NO
    // 2D arrays also stored linearly, so if we have an array of [3][4], then we allocate 3x4=12 contigous memory, as if first element is with address of 200, then 
    // we will assign from 200 to 212 linearly.

   // 2nd method: pointer
    int *B[3];  // in Stack
    // remaining in heap;
    B[0] = new int[4];
    B[1] = new int[4];
    B[2] = new int[4];


    // 3rd method: Double pointer
    int **C;    // Stored in stack
    // All remaining in heap
    C = new int*[3];
    C[0] = new int[4];
    C[1] = new int[4];
    C[2] = new int[4];


    // We can access to any element of these arrays by searching for their row and column number. ex: A[0][2] -> 1st row, 3rd column

    // How to operate(maybe print) on 2D arrays? USING nested loops;

    for (int i=0; i<3; i++){
        for(int j=0; j<4; j++){
            cout << A[i][j] << " ";
        }
        cout << endl;
    }
    return 0;
}


