#include<iostream>
using namespace std;

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
        ArrayADT differenceSorted(ArrayADT &arr1, ArrayADT &arr2);
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





// difference in sorted array;

ArrayADT ArrayADT::differenceSorted(ArrayADT &arr1, ArrayADT &arr2){
    ArrayADT arr3(arr1.size + arr2.size);           // Distination Array;
    int i, j, k;
    i = j = k = 0;
    
        // We will use the logic of merge.   check the merge-sorted-array.cpp in same directory
            while(i < arr1.size && j < arr2.size){
                if(arr1.A[i] < arr2.A[j]){          
                    arr3.A[k++] = arr1.A[i++];       // arr1's value is smaller, can't be in arr2 -> belongs in the difference
                    arr3.size++;
                }
                else if(arr1.A[i] > arr2.A[j]){
                    j++;                            // arr2's value is smaller, irrelevant to arr1 -> just skip it, no insert
                }
                else{
                    i++;                              // equal -> exists in both -> excluded from difference, no insert
                    j++;
                }
            }
            for(; i < arr1.size; ++i){
                arr3.A[k++] = arr1.A[i];
                arr3.size++;
            }
    return arr3;
}



int main()
{
    int Values[] = {1, 8, 12, 31, 85};
    int Values2[] = {1, 8, 9, 29, 90};
    ArrayADT arr(5);
    for(int i = 0; i<5; i++){
        arr.append(Values[i]);
    }    
    ArrayADT arr2(5);
    for(int i = 0; i<5; i++){
        arr2.append(Values2[i]);
    }   
    
    ArrayADT arr3 = arr.differenceSorted(arr, arr2);        
    arr3.display();
    return 0;           
}




/*
    ANALYSIS:

      SORTED ARRAY:
        -This function does a work of O(n+m), same reasoning as unionOfSetSorted and intersectionSorted: since both arrays 
        are sorted, i and j only ever move forward, never backward, and every step of the while loop advances i or j 
        (or both) by exactly one.
        -i can advance at most n times total, j can advance at most m times total, across the entire function's lifetime -
        so the while loop runs at most n+m times, not n*m times.
        -The tail loop at the end only ever copies leftover elements from arr1 (never arr2), since by definition anything
        still remaining in arr1 once arr2 is exhausted was never matched, and therefore belongs in the difference. This
        tail loop runs at most n times in the worst case, so it doesn't change the overall O(n+m) bound.
        -To conclude, same story as the other two sorted set operations: sorting lets us turn "does this exist in the 
        other array" from a full re-scan into a single pointer comparison, because sorted order guarantees we never need 
        to look backward.
*/