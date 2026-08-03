#include <iostream>


    /*  ***STACK***:
            -What is a stack? A stack is a type of storing lists in a policy of LIFO. Last in-First Out. what does it mean by LIFO. Any data that has been entered the 
             list lastly will comes out of list firstly. If a list has 20->15->10->5, the 20 needs to be the 0st index, but NO, it is not. 20 entered lastly, so it must
             get out firstly. Think of a one way parking. when there is 3 cars, first cars in, then second, then third. there is only one way to get out. Then who should
             first come out of parking? of course car third, then second then first. This is how stack works. 
             
            -Recursion to Iterative: We know that a recursion uses stack by defualt, but We also believe that we can convert a recursion into iterative. so here is the 
             question: when we change the recursion to iteration, then what about stacks? is it by defualt? NO, it is not, coz recursion uses stack by defualt, not loop. 
             then who builds it? We will gonna build the stack and it is called programmers stack. 

            -We have two physical Data Structure. 1. Arrays, 2. Linked Lists. 
             We can implement stack using both of them, first we will go with arrays and then we will come to linked lists. 

            -We always have a top variable type integer, coz it points to index number of the last entered element. the top gonna increment on each push, coz adding at 
             last of an array is effecient than adding at first. if we want to add at index 0, then we need to shift all other datas by one index. waste of time. 
    */

class StackArray{
    private: 
        int *A;
        int capacity;       // The size of array
        int size;          //  Actual elements
        int top;          //   Points to top element. 
    public:
        StackArray(int cap){};
        ~StackArray();
};

// Constructor
StackArray::StackArray(int cap){
    capacity = cap;
    A = new int[cap];
    size = 0;
    top = -1;           // Array is empty. 
}

// Destructor
StackArray::~StackArray(){
    delete []A;
}




int main()
{
    StackArray(5);      // stack of capacity 5 created in heap. 



    return 0;
}