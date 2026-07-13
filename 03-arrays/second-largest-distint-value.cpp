#include<iostream>
using namespace std;

/*Given an array of integers, find the second largest distinct element.

Example
Input: 8 4 9 2 9 7 5 8 6

Output:  Second Largest = 8

*/

// The main thing we need to care about this problem is: Dont let the Biggest value inside array should pretend to be second largest. What it means?
// if we have an array with two 9s, so if we want to find the second largest, then it must print 8, not the repeated second 9 as second largest. 

int findSecMax(int *arr, int size){
    int Max=0;
    int secondMax = 0;
    int *ptr = arr + (size);
    while(arr != ptr){
        if (*arr > Max){
            secondMax = Max;
            Max = *arr;
        }
        else if (*arr == Max){
            Max = Max;
        }
        else if(*arr < Max && *arr > secondMax){
            secondMax = *arr;
        }
        arr++;
    }
    return secondMax;
}

int main()
{

    int A[9] = {8, 4, 9, 2, 9, 7, 5, 8, 6};
    cout << findSecMax(A, 9);


    return 0;
}