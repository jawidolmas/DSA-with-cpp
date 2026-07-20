#include<iostream>


// Finding Missing Elements: 

// Finding more than one missing element in a sorted array. 

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
        void MorethanoneMissedSorted() const;

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
       
        We will use the same method, so when we have a diff = 6 - 0, then it gives how many values are missing, so if we have 10 12 15, then 6 + index will not give the 
        missing element, so what we gonna do? suppose we reached a place where we got two missing element, it is 10 12 15, when we come to 12, what if we increment diff by one
        in that case, the incremented diff will give us for what we are looking, see: 1 + first element - index, so diff = 7 - index, and for 14, we will do 8 - index, and so one.. 

        let's see it in code.
*/



// Finding more than one missed element in sorted array.

void ArrayADT::MorethanoneMissedSorted() const{
    if(size == 0){
        std::cout << "Array is empty\n";
        return;
    }
    int l = A[0];
    int diff = l - 0;
    for(int i=0; i<size; i++){
        if(A[i]-i != diff){
            while(diff < A[i]-i){
                std::cout << "Missing element: " << i + diff << "\n";
                diff++;
             }
        }
    }
}


int main()
{
    int Values[5] = {4, 6, 7, 9, 11};
    ArrayADT arr(5);
    for(int i = 0; i<5; i++){
        arr.append(Values[i]);
    }    
    arr.MorethanoneMissedSorted();            // 5, 8, 10 is missing


    return 0;           
}


/*
    ANALYSIS:

      -When we all first see this function's code(  MorethanoneMissedSorted(); ), we may think, "Hey, we have a nested loop and it highly should be O(n^2).", but it is NOT.
      -Why? if we look carefully, there is one loop that really doing the hard work. for loop, which is traversing each index one by one, and it will give us n+1 step of 
      work, so the order of for loop is O(n). Now, what about while loop? how much work does while loop do? While loop is responsible to print missing elements and also to 
      increment the diff. Does it really doing a work as for? do we need n*n = n^2 ? of course not. what if we dont have any missing elements? or only one? then it is n * 1, isnt it? 
      so from here, we can say that while loop is neglegible, it does work dependent for the number of missing elements. So, we simple count it as constant and we dont count it 
      in time complexity. 
      -TO CONCLUDE, WE CAN SAY THAT THIS FUNCTION DOES A WORK OF n AND IT IS O(n). 

*/