#include <iostream>
using namespace std;
#define SIZE 10


/*
        HASH TABLE:
            Full explanation has been done in iPad notes.



            Let's code Linear Probling technique



*/

int Hash(int key){
    return  key % SIZE;
}

int probe(int H[], int key){
    int index = Hash(key);
    int i = 0;
    while(H[(index + i)%SIZE] != 0){
        i++;
    }
    return (index+i)%SIZE;
}

void insert(int H[], int key){
    int index = Hash(key);
    if(H[index] != 0){
        index = probe(H, key);
    }
    H[index] = key;
}

int search(int H[], int key){
    int index = Hash(key);
    int i = 0;
    while(H[(index+i)%SIZE] != key){
        i++;
    }
    return (index+i)%SIZE;
}




int main()  
{
    int A[10] = {0};
    insert(A, 22);
    insert(A, 32);
    insert(A, 25);
    insert(A, 76);


    return 0;
}