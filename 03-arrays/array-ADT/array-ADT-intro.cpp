#include<iostream>
using namespace std;

/*Array ADT(Abstract Data Type): we may think that what is ADT? 
let's suppose: you are in your home and watching TV, you have a remote and you control the TV with it, you change channel, volume up and donw, 
turning it off and on. so here is the question: do you really know how it works? NO, why? becuase you dont need to know that.
you just use it and pass. the ADT is the exact same thing, in Software Engineering, engineers dont need to know and implement everything from scratch
in a company, there may be 100s of projects, and when a new engineer joins them, they only need to know how to use them, not how to implement everything.


in Array ADT, we have a lot of operations, like insert, get, set, display, remove, and etc... 
As an engineer, we need to know how it can be implemented, but do we really need to implement? or just trust the team and use it.
for good teamwork and effeciency we will use others codes and libraries. 

LET'S start with array ADT.*/

// We can implement array ADT in two ways, 1. direct defined exact size in stack like: int A[10]. 2. using pointer and in heap, int *A;
// In here, we will use OOP and use the second method, which gives us more effecincy and convineice. 



class ArrayADT{
    private:
        int *A; // pointer to point to array's first add in heap
        int capacity; // number of indices inside array;
        int size;     // number of real value elements in array;
    public:
        ArrayADT(int cap);  // Constructor
        ~ArrayADT();        // Destructor

};


ArrayADT::ArrayADT(int cap){
    A = new int[cap];
    capacity = cap;
    size = 0;
}


ArrayADT::~ArrayADT(){
    delete []A;
}



int main()
{
    int n;
    // As we used 2nd method and implement using OOP, we now can add the size of array anything we want.
    ArrayADT arr(10); // We have an array of capacity 10, inside heap;

    // we even can get capacity of array from keyboard;
    
    cout << "Add size of array: ";
    cin >> n;
    ArrayADT arr2(n);
    return 0;
}