#include<iostream>
using namespace std;

struct name{
   char x;
   int y;
   double z;
};


int main(){

    int a = 30;
    int *p; // declaring a pointer.
    p = &a; // initiailizing the pointer p to the address &a of the a;
    cout << a << endl; // output: 30;
    cout << p << endl; // output: the address in the stack section of memeory. 
    cout << *p << endl; // output: 30; reason: compiler telling CPU, go to address of a and read the data inside it; simple it is DEREFERENCING.

    int Arr[] = {1, 2, 3, 4, 5};
    int *p2 = Arr; // we dont use & for initializing a pointer to an array, because the array itself is a pointer pointing to the first index address. so we could do int *p = &Arr[0];
    for (int i=0; i<5; i++){
        cout << p2[i];
    }  //output: 12345
    
    //The size of a pointer is 8 bytes, regardless of its data type.
    int *ptr1;
    char *ptr2;
    double *ptr3;
    float *ptr4;
    name *ptr5; // struct.
    cout << sizeof(ptr1);
    cout << sizeof(ptr2);
    cout << sizeof(ptr3);
    cout << sizeof(ptr4);
    cout << sizeof(ptr5);  
    // output: 8 8 8 8 8. reason: Pointers are all take 8 bytes of memeory. 
    
 

    // right now, all of the datas are storing inside the stack. So, if we want to store it inside heap, then we use memory allocation using NEW. 
    int *p4;
    p4 = new int[5]; // We allocated 20 bytes inside heap. 5 * 4 bytes = 20 bytes.
    p4[0] = 10;
    p4[1] = 20;
    p4[2] = 30;
    p4[3] = 40;
    p4[4] = 50;
    for(int i=0; i<5; i++){
        cout << p4[i];
    }
    
    delete []p4; // Remmember to delete the allocated memory in the heap to prevent overflow. 

    return 0;
}
