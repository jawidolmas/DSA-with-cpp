#include<iostream>
using namespace std;

// Merge two sorted arrays 

class ArrayADT{
    private:
        int *A; // pointer to point to array's first add in heap
        int capacity; // number of indices inside array;
        int size;     // number of real value elements in array;
    public:
        ArrayADT(int cap);
        ~ArrayADT();     
        void append(int value); 
        ArrayADT Merge(ArrayADT &arr1, ArrayADT &arr2);
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
    Merge: 
        -Merging two arrays has a logic of having third array, so if I have two arrays with 5 elements in each, I need to have a third array with size 10 to be able to merge
        two arrays. For making it happen, as we are mergin sorted arrays, and the merged arrays also should be sorted. Becuase of this 
        process, we need three index variables, i, j, k. i will hold the 0th index address in array A, j in B and k in C. as we go ahead with that, we will use i and j 
        to compare two values in same index, is the value in A in index 0th is bigger than B? if smaller, copy it in array C and increment i, if bigger do the same for j.
        
        -So now there we have a problem: No matter what, we will end up with one variable that we cannot compare it with anything, the biggest or the last value in either 
        A or B, because the last one must be bigger than the rest of them, because it is sorted. So the QUESTIONS IS HERE: "HOW WE WILL COPY THAT LAST ELEMENT IN ARRAY C?"

        -This answer is simple: Just copy the last element in C, for making it happen, we will use a for loop, that starts from whereever i or j is, then copy and increment 
        i OR j AND k. 

        see? Mergin is so simple. Lets code;

*/

// We get the type of function the class itself, because we will return the full arr3 directly. as for readiness and comfort;

ArrayADT ArrayADT::Merge(ArrayADT &arr1, ArrayADT &arr2){
    
    ArrayADT arr3(arr1.size + arr2.size);           // Distination Array;
    int i, j, k;
    i = j = k = 0;
    while( i < arr1.size  && j < arr2.size){        // The loop should iterate until we get to end of both arrays, so simple to size;
            
        if(arr1.A[i] < arr2.A[j]){
            arr3.A[k++] = arr1.A[i++];             // Add the value from arr1 to arr3 and increment both k and i; 
            arr3.size++;
        }
        else{
            arr3.A[k++] = arr2.A[j++];            // Vice versa, if j is smaller, write the j in k and increment.
            arr3.size++;
        }
    }    
        // Now, we need to copy the last element, as we dont know which array will hold the biggest element, we will use two  loop for each of them.
    
        for(; i < arr1.size; i++){      // ; means where ever the i is currently. 
            arr3.A[k++] = arr1.A[i];
            arr3.size++;
        }
        for(; j < arr2.size; j++){      // ; means where ever the j is currently;
            arr3.A[k++] = arr2.A[j];
            arr3.size++;
        }
    return arr3;
}



int main()
{
    int Values[] = {1, 2, 3, 4, 5};
    int Values2[] = {-34, 6, 7, 9, 12};
    ArrayADT arr(5);
    for(int i = 0; i<5; i++){
        arr.append(Values[i]);
    }    
    ArrayADT arr2(5);
    for(int i = 0; i<5; i++){
        arr2.append(Values2[i]);
    }   
    
    ArrayADT arr3 = arr.Merge(arr, arr2);
    arr3.display();
    return 0;           
}




/*
    ANALYSIS:
        - This function is different from what we have seen so far. How much work does this function do?
        - This function is a copy function, so each elements from A and B gets copied to B. if we say m to size of elements in A and n to size of elements in B, 
        then the function will do a work of sizes in A and B which is m + n. as, other we are taking about complexity, not the time function, then the complexity for 
        this function will be theta of m + n. not Order of m + n, this is the first time we are using theta instead of O, in merge, we always use theta. 
        - To conclude, this function is theta(m + n). 
*/