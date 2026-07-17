#include<iostream>
using namespace std;

// Adding a data in a sorted array which remains sorted;


class ArrayADT{
    private:
        int *A; // pointer to point to array's first add in heap
        int capacity; // number of indices inside array;
        int size;     // number of real value elements in array;
    public:
        ArrayADT(int cap);
        ~ArrayADT();     
        void append(int value); 
        void addValuetoSrotedArr(int x);
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



// Adding data in a sorted array;

void ArrayADT::addValuetoSrotedArr(int x){
    if(size == capacity){
        std::cout << "Array is full\n";
        return;
    }
    int i = size-1;
    while(A[i] > x){
      A[i+1] = A[i];
      i--;
    }
    A[i+1] = x;
    size++;
}




int main()
{
    int Values[] = {1, 2, 8, 25, 50};
    ArrayADT arr(6);
    for(int i = 0; i<5; i++){
        arr.append(Values[i]);
    }       
    arr.addValuetoSrotedArr(15);
    arr.display();
    
    
    return 0;
}




/*
    ANALYSIS:

        -This function is O(n) in the worst case. The capacity check is O(1). The while loop shifts elements one-by-one to make room for x, 
        and in the worst case (when x is smaller than every existing element), it shifts all size elements, so the loop runs O(n) times.
        The final insertion is O(1). Space complexity is O(1), no auxiliary array is used, elements are shifted in place.
        -Compare this to append() (O(1), since it just writes to the end) — insertion into a sorted array costs more precisely because of the 
        shifting needed to preserve order.

*/