#include<iostream>
using namespace std;

// Rotating array


class ArrayADT{
    private:
        int *A; // pointer to point to array's first add in heap
        int capacity; // number of indices inside array;
        int size;     // number of real value elements in array;
    public:
        ArrayADT(int cap);
        ~ArrayADT();     
        void append(int value); 
        void rotateArray();
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
    Rotating an array:
        -An array rotation is rotating the values index by index. If you ever have seen an electric banner saying welcome, and it is moving linearly from left 
        to right and coming back and seems like there is a loop rotation each time. watch it one: https://youtube.com/shorts/NKVlgasXDVM?si=CQLOePiRH8R2zaKu 
        
        -How we are going to rotate it?
            -Suppose we have an array of 1 2 3 4 5 with 5 index. so the rotation will happen as 2 3 4 5 0 and 1 will be deleted. we will put that delete 1 in 
            last index which is now 0. as we put the 1 in last index, we created a cycle, and that is why we are calling it rotation or shift. 
            -We have right rotation as well as left rotation/shift. 

*/

// Left rotating

void ArrayADT::rotateArray(){
    if(size == 0){
        std::cout << "Array is empty\n";
        return;
    }
    int temp = A[0];
    for(int i = 0; i<size-1; i++){
        A[i] = A[i+1];
    }
    A[size-1] = temp;
}



int main()
{
    int Values[] = {1, 55, 6, 8, -89, 25};
    ArrayADT arr(6);
    for(int i = 0; i<6; i++){
        arr.append(Values[i]);
    }       
    arr.rotateArray();
    arr.display();
    
    
    return 0;
}




/*
    ANALYSIS:
        -This function is order of n, we have a check whcih is one step, if the array is empty, stop, if not, enter the loop, the loop runs n times and its body runs n-1 times
        because the condition check for i is until size - 1, which makes the n to n-1. and at the end, it will modify the last index. 
        -So to conclude, it is O(n) in terms of time and O(1) in terms of space. 

*/