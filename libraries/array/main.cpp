#include<iostream>
using namespace std;
#include "array.h"




int main(){

    Array arr(5);
    arr.append(15);
    arr.append(16);
    arr.append(17);
    arr.insert(0, 15);
    arr.display();
    arr.Delete(6);
    arr.display();
    cout << arr.length() << endl;
    cout << arr.Max();
    cout << arr.Min() << endl;
    cout << arr.sum() <<endl;
    cout << arr.average() << endl;
    arr.linearsearch(20);
}