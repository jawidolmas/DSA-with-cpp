#include<iostream>
using namespace std;
#include "array.h"




int main(){

    int Value[5] = {1, 2, 3, 8};
    int Value1[5] = {6, 8, 9, 12, 15};
    Array arr(5);
    Array arr2(5);

    for(int i = 0; i<4; i++){
        arr.append(Value[i]);
        arr2.append(Value1[i]);
    }
    std::cout << arr.isSorted() << std::endl; 
    arr.insertSorted(5);
   /* arr.append(10);
    arr.append(20);
    arr.append(30);
    arr.append(40);
    arr.insert(0, 10);
    arr.display();
    arr.Delete(6);
    arr.display();
    cout << arr.length() << endl;
    cout << arr.Max();
    cout << arr.Min() << endl;
    cout << arr.sum() <<endl;
    cout << arr.average() << endl;
    arr.linearsearch(10);
    cout << arr.get(4) << endl;
    arr.display();
    arr.BinarySearchRecursive(0, 5, 40);
    */
    arr.display();
    
   
    


}