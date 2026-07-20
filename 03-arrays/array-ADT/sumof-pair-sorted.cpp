#include<iostream>


//Sum of a pair that makes k in sorted array.



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
        void sumPairSorted(int k);

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


// Finding a pair with sum k in sorted array

void ArrayADT::sumPairSorted(int k){
    if(size == 0){
        std::cout << "Array is empty\n";
        return;
    }
    int i = 0, j = size-1;
    while(i < j){
        if(A[i] + A[j] == k){
            std::cout << "( " << i << ", " << j << " )\n"; 
            i++;
            j--;
        }
        else if(A[i] + A[j] < k){
            j--;
        }
        else i++;
    }

}

int main()
{
    int Values[10] = {1, 2, 5, 7, 8, 10, 12, 15, 18, 19};
    ArrayADT arr(10);
    for(int i = 0; i<10; i++){
        arr.append(Values[i]);
    }    
    arr.sumPairSorted(20);       

    /*  Output:

        ( 0, 9 )
        ( 1, 8 )
        ( 2, 7 )
         
    */

    return 0;           
}


/*
    ANALYSIS:

        This function does a work of n steps. so this is O(n). we have a i and j variable. i is at the beginning and j is at the end, 
        whenever if  i + j is bigger do a work, if equal do another work, if smaller do different work. So these are all constant operations. 
        To conclude, this function does a work of O(n).
*/