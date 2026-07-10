#include <iostream>
using namespace std;

//Write a C++ program to implement a recursive function to find the maximum and minimum elements in an array.

void findMaxMin(int arr[], int n, int index, int &maxVal, int &minVal){
    
        if (index == n-1){
            maxVal = minVal = arr[index];
            return;
        }
        findMaxMin(arr, n, index+1, maxVal, minVal);
        if (arr[index] > maxVal){
            maxVal = arr[index];
        }
        if (arr[index] < minVal){
            minVal = arr[index];
        }
}

int main(){
    int arr[] = {3, 7, 1, 9, 2};
    int n = 5;
    int maxVal, minVal;

    findMaxMin(arr, n, 0, maxVal, minVal);

    cout << "Max: " << maxVal << ", Min: " << minVal << endl;
    return 0;
}