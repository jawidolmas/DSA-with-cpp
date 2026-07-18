#include<iostream>
using namespace std;

// SETS: 

// Union of two sets. A+B;

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
    Union: 
      -Union of two set means the combination of elements in A and B, but under a condition which is in sets, there will not any copy of same element. 
      -If we are given with two arrays that are not sorted, and asked to find the union of those arrays, then the things will go very slow, becuase operations are 
      become quadratic. 
      -but WHY? when there is two arrays not sorted, we should create a new array for union, copy the first array and then copy the second array, but this time, 
      we need to make a search operation too, we need to search if elements in new array is there or not, if there dont take it, coz it will copy the same element. 
      if not there take it to array C. but, if we are given with sorted array, then we will not need to search, we will use the MERGE function logic.
      visit merge-sorted-array.cpp in same directory to get more about MERGE logic. 

*/

//First let's code an unsorted array. 

ArrayADT ArrayADT::unionOfSet(ArrayADT &arr1, ArrayADT &arr2){
    
    ArrayADT arr3(arr1.size + arr2.size);           // Distination Array;
    int i, j, k;
    i = j = k = 0;
    // First, we need to copy the first array's all elements to destination. 
    for(; i<arr1.size; i++){
        arr3.A[k++] = arr1.A[i];
        arr3.size++;                // Becuase size in desetination array need to be incremented on each operation, to be able to not lose track.
    }

    // Now, lets copy the second array, but need to search in order to not copy the existed element.
    bool found = false;     // we will use this for checking if elements in B matched elements in C or not. if not, then we will add, if found, skip. 
    for(; j < arr2.size; ++j){
        for(k = 0; k < arr3.size; ++k){
                if(arr2.A[j] == arr3.A[k]){
                    found = true;       // Matched value from B in C. skip this one. 
                }
        }
        if(!found){
            arr3.A[k++] = arr2.A[j];    // We need to bump the k after each right, this is independet of ++k in loop. 
            arr3.size++;
        }
        found = false;      // Reset the found for the next search. 
    }
    return arr3;
}

// Now let's code sorted array. 

ArrayADT ArrayADT::unionOfSetSorted(ArrayADT &arr1, ArrayADT &arr2){
    ArrayADT arr3(arr1.size + arr2.size);           // Distination Array;
    int i, j, k;
    i = j = k = 0;
    
    // We will use the logic of merge.   check the merge-sorted-array.cpp in same directory
    while(i < arr1.size && j < arr2.size){
        if(arr1.A[i] < arr2.A[j]){
            arr3.A[k++] = arr1.A[i++];
            arr3.size++;
        }
        else if(arr1.A[i] > arr2.A[j]){
            arr3.A[k++] = arr2.A[j++];
            arr3.size++;
        }
        else{
            arr3.A[k++] = arr1.A[i++];
            arr3.size++;
            j++;
        }
    }

        for(; i<arr1.size; i++){
            arr3.A[k++] = arr1.A[i];
            arr3.size++;
        }
        for(; j<arr2.size; ++j){
            arr3.A[k++] = arr2.A[j];
            arr3.size++;
        }
    

    return arr3;
}




int main()
{
    int Values[] = {1, 8, 12, 31, 85};
    int Values2[] = {-34, 1, 8, 32, 90};
    ArrayADT arr(5);
    for(int i = 0; i<5; i++){
        arr.append(Values[i]);
    }    
    ArrayADT arr2(5);
    for(int i = 0; i<5; i++){
        arr2.append(Values2[i]);
    }   
    
    ArrayADT arr3 = arr.unionOfSetSorted(arr, arr2);
    arr3.display();
    return 0;           
}




/*
    ANALYSIS:

       UNSORTED ARRAY:
        -This function, does a work of quadratic, as we discussed in explanation, this uses a writing from A to C, then searching and comparing all elements in B 
        with C. so this really does a very hard work, which makes the program slow.
        -We do a work of n for copying A to C, then we will do a work of m(m is size of B) for Copying B to C, but we also do a work of n for searaching and comparing,
        in fact, we will do n + m*n works, so if we count n as const, and m = n, then it will be n^2 and we will have theta(n^2).
        
        -Currently, with this level of knowledge, I dont know that if we can bring it back 
        to O(n), or even logn, I am sure that we cannot bring this case in logn, or even in n, but again, there is a way that made me to think aloud. 

        -In we do only one search, and save all elements of B in a brand new array, then compare the arrays in C with this brand new array, this way, we may save time, 
        but we will use more space than we need to. So, it may depends on what is important for us, but again, this is what I think, maybe this is impossible, or maybe
        there is better ways. we need to be sure of what tradeoffs we do. 
        -We also can sort the array first, and then take its union, also, if we store the arr3 in a new array, then do we really need to search element by element? I dont 
        think so, but again, this is what I personally think. 

      SORTED ARRAY:
        -This function does a work of O(n). reason: the sets are sorted, and we only do one work on each write, the while does only one camparison. thats it. 
        -To conclude, this function gives us the ability to save time, from quadratic to linear. 
*/