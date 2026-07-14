#include<iostream>
#include "array.h"




int main(){

    Array arr(5);
    arr.append(15);
    arr.append(16);
    arr.append(17);
    arr.insert(0, 10);
    arr.insert(0, 10);
    arr.display();
    arr.Delete(6);
    arr.display();
}