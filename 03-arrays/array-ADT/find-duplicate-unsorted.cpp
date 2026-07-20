#include<iostream>


// Duplicates of elements: 

// Finding  duplicate of  elements  in unsorted array

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
        void FindduplicateUnsorted();

};


ArrayADT::ArrayADT(int cap){
    A = new int[cap](); 
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
    The problem is simple, We need to trace each index by index and after that, compare one index by all n index, then if duplicated exist, take a variable and increment
    it for printing. The idea in here is that we dont need to overcount. so how we can handle that? if we have 8 6 7 6 1 6 19 6. then, if we start from index 0, then 1, we 
    can see that value in index 1 is duplicated, so what if we reach in index 3? again count++ and 3 more value 6? NO. so whenever we see there is a duplicate, we will 
    modify it to -1, and act like it is empty. A[duplicated index] = -1; This way, we can handle overcount of values.

    let's code then.
*/


// Finding missing element in unsorted array

void ArrayADT::FindduplicateUnsorted(){
    if(size == 0){
        std::cout << "Array is empty\n";
        return;
    }
    int i, j, count;
    for(i = 0; i < size-1; i++){
        count = 1;
        if(A[i] != -1){
            for(j = i+1; j < size; j++){     
                if(A[i] == A[j]){
                    count++;
                    A[j] = -1;
                }
            }
            if(count > 1)
                std::cout << "The number " << A[i] << " appeared " << count << " times\n";
        }
    }
}



int main()
{
    int Values[10] = {3, 6, 8, 8, 10, 8, 15, 15, 15, 20};
    ArrayADT arr(10);
    for(int i = 0; i<10; i++){
        arr.append(Values[i]);
    }    
    arr.FindduplicateUnsorted();       

    return 0;           
}


/*
    ANALYSIS:

        As we can see a nested loop, this function does a work of O(n^2). we have two loops, and each loop does a work of n. First loop traces all indices and gives it to
        second loop, and second loop compares with with all other indices and if duplicate found, increment count and modify the index. 
        So two nested loop can be n*n = n^2. 

        -For those which space is more important than time, this algorithm is the best. 
        -For those which time is more important than space, then hash table algorithm is the suitable choice. 
*/