#include<iostream>
using namespace std;
#include "array.h"




int main(){

    Array arr(5);
    arr.append(10);
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
   
    


}