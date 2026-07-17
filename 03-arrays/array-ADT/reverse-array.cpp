#include<iostream>
using namespace std;

// Reversing an array


class ArrayADT{
    private:
        int *A; // pointer to point to array's first add in heap
        int capacity; // number of indices inside array;
        int size;     // number of real value elements in array;
    public:
        ArrayADT(int cap);
        ~ArrayADT();     
        void append(int value); 
        void Copyreverse();
        void Swapreverse();
        void display() const;
};


ArrayADT::ArrayADT(int cap){
    A = new int[cap];
    capacity = cap;
    size = 0;
}


ArrayADT::~ArrayADT(){
    delete []A;
}


void ArrayADT::display() const{
    // lets check if array is empty;
    if (size == 0){ // means no value in it;
        std::cout << "Array is empty\n";
        return;
    }
    for(int i = 0; i<size; ++i){
        std::cout << A[i] << " ";
    }
    std::cout << std::endl;
}

// Append:
void ArrayADT::append(int n){
    if(size == capacity){   
        std::cout << "Array is full\n";
        return;
    }
    A[size] = n;
    size++;         
}

/*
    Reversing an array
        -For reversing an array we can use two different logic. if we think deeply, we either can take another array, copy its reverse and re-copy it inside main array, or
        we can swap index 0 with last, 1 with last-1, 2 with last-2... until we get a reversed array. 

        Method one: 
            -We will use an auxilary array, a helper array, which we use temporarily, we copy all elements from array A to B. 
            However, we will start copying from last to first, so array B will now have the reverse of the A, after that, we simply copy the B to A, because 
            the array that should be reversed is A, so by copying, we will have the reversed version of A in A. 

        Method two:
            -We will use the logic of swap, we will have a temporary variable temp, and we will use a loop.
            -then swap the last with first, las-2 with 2nd ... until the i is less than j. 

    Let's see both methods.

*/

// Method one: Copying;

ArrayADT arr2(6);

void ArrayADT::Copyreverse(){
        
        if(size == 0){
            std::cout << "Array is empty\n";
            return;
        }
        if(size > arr2.capacity){
            std::cout << "Destination too small\n";
            return;
        }
        int i, j;
        for( i = size-1,  j = 0; i >= 0; --i, ++j){
               arr2.A[j] =  A[i]; 
        }
        for(i = 0; i<size; i++){
            A[i] = arr2.A[i];
        }
}

// Method two: Swap;


void ArrayADT::Swapreverse(){
    if(size == 0){
        std::cout << "Array is empty\n";
        return;
    }
    int temp = 0, i, j;
    for(i = 0, j = size-1; i<j; i++, j--){
        temp = A[i];
        A[i] = A[j];
        A[j] = temp;
    }
}


int main()
{
    int Values[] = {1, 55, 6, 8, -89, 25};
    ArrayADT arr(6);
    for(int i = 0; i<6; i++){
        arr.append(Values[i]);
    }       
    arr.Swapreverse();
    arr.display();
    
    
    return 0;
}




/*
    ANALYSIS:

       Method one:
            -This method is O(n) in both terms of space and time. We copy everything from first array to helper array and the recopy, so we use two loop,
            Remmember that we dont have a nested loop, so it can never be O(n^2).
            -At the same time, as we create a new helper array, we get another same size space as previous array, which makes space as O(n).

        Method two:
            -This method is O(n) in terms of time, as it uses a loop to swap each data index by index. However, this function gives us a huge advantage with a constant
            in terms of space, O(1). As we only have one array and we dont need any other array, we just swap the indices with each other. 
            -For memeory consumption, this function is the best possible function among these two, while they are equally same in terms of time.

*/