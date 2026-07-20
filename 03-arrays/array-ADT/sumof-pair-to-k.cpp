#include<iostream>


//Sum of a pair that makes k.



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
        void sumPair(int k);

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
    In this problem, we will use nested loop, one loop to start the index and the other one to compare it with the rest of the elements. 
    
    let's code then.
*/


// Finding a pair with sum k

void ArrayADT::sumPair(int k){
    if(size == 0){
        std::cout << "Array is empty\n";
        return;
    }
    int i, j;
    std::cout << "Sum of pairs(indices) =  " << k << "\n";
    for( i = 0; i<size; i++){
        for(j = i+1; j<size; j++){
            if(A[i] + A[j] == k){
                
                std::cout << "( "<< i << " , " << j << " ) \n";
            }
        }
    }
}



int main()
{
    int Values[10] = {3, 6, 7, 9, 1, 4, 5, 12, 7, 8};
    ArrayADT arr(10);
    for(int i = 0; i<10; i++){
        arr.append(Values[i]);
    }    
    arr.sumPair(10);       

    return 0;           
}


/*
    ANALYSIS:

        O(n^2)
        As we can see a nested loop, this function does a work of O(n^2). we have two loops, and each loop does a work of n. First loop traces all indices and gives it to
        second loop, and second loop compares with with all other indices and the check is if any two index makes = k, then print them.
        So two nested loop can be n*n = n^2. 

        -For those which space is more important than time, this algorithm is the best. 
        -For those which time is more important than space, then hash table algorithm is the suitable choice. 
*/