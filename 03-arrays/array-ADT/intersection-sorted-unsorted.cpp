#include<iostream>
using namespace std;

// SETS: 

// Intersection of two arrays. 

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
        ArrayADT unionOfSet(ArrayADT &arr1, ArrayADT &arr2);
        ArrayADT unionOfSetSorted(ArrayADT &arr1, ArrayADT &arr2);
        ArrayADT intersectionSorted(ArrayADT &arr1, ArrayADT &arr2);
        ArrayADT intersectionUnsorted(ArrayADT &arr1, ArrayADT &arr2);
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


// Intersection Unsorted:

ArrayADT ArrayADT::intersectionUnsorted(ArrayADT &arr1, ArrayADT &arr2){
    
    ArrayADT arr3(arr1.size + arr2.size);           // Distination Array;
    int i, j, k;
    i = j = k = 0;

    bool match = false;     // we will use this for checking if elements in B matched elements in C or not. if so, then we will add, if not, skip. 
    for(; i < arr1.size; ++i){
        for(j = 0; j<arr2.size; ++j){
            if(arr1.A[i] == arr2.A[j]){
                match = true;  
            }
        }
        if(match){
        arr3.A[k++] = arr1.A[i];
        arr3.size++;
        }
        match = false;
    }
    return arr3;
}



// Intersection in sorted array;

ArrayADT ArrayADT::intersectionSorted(ArrayADT &arr1, ArrayADT &arr2){
    ArrayADT arr3(arr1.size + arr2.size);           // Distination Array;
    int i, j, k;
    i = j = k = 0;
    
        // We will use the logic of merge.   check the merge-sorted-array.cpp in same directory
            while(i < arr1.size && j < arr2.size){
                if(arr1.A[i] < arr2.A[j]){
                    i++;
                   
                }
                else if(arr1.A[i] > arr2.A[j]){
                    j++;
                }
                else{
                    arr3.A[k++] = arr1.A[i++];
                    j++;
                    arr3.size++;
                }
            }
    return arr3;
}



int main()
{
    int Values[] = {1, 8, 12, 31, 85};
    int Values2[] = {10, 8, 1, 12, 90};
    ArrayADT arr(5);
    for(int i = 0; i<5; i++){
        arr.append(Values[i]);
    }    
    ArrayADT arr2(5);
    for(int i = 0; i<5; i++){
        arr2.append(Values2[i]);
    }   
    
    ArrayADT arr3 = arr.intersectionUnsorted(arr, arr2);        
    arr3.display();
    return 0;           
}




/*
    ANALYSIS:

       UNSORTED ARRAY (intersectionUnsorted):
        -This function also does a work of quadratic, same story as unsorted union. For each of the n elements in arr1, we search
        through all m elements of arr2 to check if a match exists. So total work is n * m, and if we count m = n, it becomes 
        theta(n^2), exactly like unionOfSet.
        -The only real difference from union is the condition is flipped: union inserts when NOT found, intersection inserts
        when found. Same nested-scan shape, same cost, just the opposite decision at the end.
        -Same tradeoff discussion applies here as it did for union: to beat n^2 without sorting first, we'd need some other
        structure (like the "brand new array" idea, or hashing) to answer "does this exist?" faster than a full scan.

      SORTED ARRAY (intersectionSorted):
        -This function does a work of O(n+m). reason: same as unionOfSetSorted, the arrays are sorted, so we only ever move
        forward, never backward, and every step of the while loop advances i or j (or both) by exactly one. 
        -Since i can advance at most n times total and j can advance at most m times total across the ENTIRE function's
        lifetime, the loop can run at most n+m times, not n*m times.
        -To conclude, sorting turns the "does this exist in the other array" question from a full re-scan (costly) into a
        single comparison against wherever the pointer currently sits (cheap), because sorted order guarantees we never
        need to look backward or re-check something we've already passed.
*/