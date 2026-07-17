#include<iostream>
using namespace std;

// Sort negatives on one side and positives on other side

class ArrayADT{
    private:
        int *A; // pointer to point to array's first add in heap
        int capacity; // number of indices inside array;
        int size;     // number of real value elements in array;
    public:
        ArrayADT(int cap);
        ~ArrayADT();     
        void append(int value); 
        void sortPosandNeg();
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


// Swap function for sorting;

void swap(int &a, int &b){
    int temp = 0;
    temp = a;
    a = b;
    b = temp;
}



//sort Pos and Neg:

void ArrayADT::sortPosandNeg(){
    if(size == 0){
        std::cout << "Array is empty\n";
        return;
    }
    int i = 0, j = size-1;
    while(i<j){
        while(A[i] < 0){
            i++;
        }
        while(A[j] >= 0){
            j--;
        }
        if(i<j){
        swap(A[i], A[j]);
    }
}
}


int main()
{
    int Values[] = {12, -2, -10, 1, 9, 8, -25, -98, 85, 78, 50};
    ArrayADT arr(10);
    for(int i = 0; i<10; i++){
        arr.append(Values[i]);
    }       
    arr.sortPosandNeg();        // Output: -98 -2 -10 -25 9 8 1 12 85 78 
    arr.display();
    return 0;           
}




/*
    ANALYSIS:
        -This function is O(n) time overall. Although there are nested while loops, they aren't truly nested in the traditional multiplicative sense
        the inner loops advance i and j monotonically inward across the array, and combined, i and j each traverse their portion of the array at most once
        from start to finish over the life of the whole function. 
        -So the total work across all iterations of both inner loops together is bounded by size, not size squared. 
        -Space complexity is O(1), since swapping is done in place with no auxiliary array.
*/