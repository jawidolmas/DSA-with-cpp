#include<iostream>


// SETS: 

// Difference of two arrays. 

// A set mathematically can not have internal duplicates. so inputs should suit this rule. 


class ArrayADT{
    private:
        int *A; // pointer to point to array's first add in heap
        int capacity; // number of indices inside array;
        int size;     // number of real value elements in array;
    public:
        ArrayADT(int cap);
        ~ArrayADT();     
        void append(int value); 
        void display() const;
        void FindMissingElement() const;

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


/*  Logic:
        Logic is simple in here, first we will go with best case, if given array is first N natural elements. For sure there are more than one method to do this,
        one method is using the sum of numbers. As we know, that array is sorted, and only one element is missing. 
        what if we sum up all values in array, and then subtract it with sum of N natural numbers, for example, 1 2 3 4 5 7 8 9, we sum them all 
        and then sum the N first natural numbers, with n(n+1)/2. sounds?




*/

// Finding one missing element in a sorted array

void ArrayADT::FindMissingElement() const{
    if(size == 0){
        std::cout << "Array is empty\n";
        return;
    }
    int sum = 0;
    for(int i = 0; i < size; i++){
            sum += A[i];
    }
    int num = size+1;
    int N = (num*(num+1))/2;
    int Diff = N - sum;
    std::cout << "The missing number is: " << Diff;

}


int main()
{
    int Values[] = {1, 2, 3, 4, 5, 6, 8, 9, 10};
    ArrayADT arr(9);
    for(int i = 0; i<9; i++){
        arr.append(Values[i]);
    }    
    arr.FindMissingElement();


    return 0;           
}


/*
    ANALYSIS:

      Finding missing array: 
            This function is order of N, as we scan all the elements and add them one by one, then we will do a work on n. our first check is 1 step work, then for loop
            which is n + 1, and the summation is n step work. so to conclude, we will have O(n). 
*/