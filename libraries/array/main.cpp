#include<iostream>
using namespace std;
#include "array.h"




int main(){

    Array arr(5);
    arr.append(20);
    arr.append(16);
    arr.append(17);
    arr.append(18);
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
    cout << arr.get(4) << endl;
    arr.set(4, 9);
    arr.transpositionLinearSe(9);
    arr.display();
    arr.transpositionLinearSe(9);
    arr.display();
    arr.movetoFrontLinearSe(17);
    arr.display();
    arr.movetoFrontLinearSe(17);
    arr.display();
}