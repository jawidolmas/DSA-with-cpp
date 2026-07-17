#include<iostream>
using namespace std;

// SUM, AVERAGE, LENGTH, 


class ArrayADT{
    private:
        int *A; // pointer to point to array's first add in heap
        int capacity; // number of indices inside array;
        int size;     // number of real value elements in array;
    public:
        ArrayADT(int cap);
        ~ArrayADT();     
        void append(int value); 
        int sum(); 
        double avg();
        int lenght() const;
};


ArrayADT::ArrayADT(int cap){
    A = new int[cap];
    capacity = cap;
    size = 0;
}


ArrayADT::~ArrayADT(){
    delete []A;
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

// sum

int ArrayADT::sum(){
    int total = 0;
    if(size == 0){
        std::cout << "Array is empty\n";
        return 0;
    }
    for(int i = 0; i<size; ++i){
        total += A[i];
    }
    return total;
}


// lenght

int ArrayADT::lenght() const{
    if(size == 0){
        std::cout << "Array is empty\n";
    }
    return size;
}


// Average

double ArrayADT::avg(){
    double avg = 0.0;
    if(size == 0){
        std::cout << "Array is empty\n";
        return 0;
    }
    avg = (double) sum()/lenght();
    return avg;
}






int main()
{
    int Values[] = {1, 2, 6, 8, 11, 25};
    ArrayADT arr(6);
    for(int i = 0; i<6; i++){
        arr.append(Values[i]);
    }
    
    cout << arr.sum() << endl;
    cout << arr.lenght() << endl;
    cout << arr.avg() << endl;

    return 0;
}




/*
    ANALYSIS:

        Sum:
            -The complx for this function is O(n). The reason is behind the loop and its body that does works n times;

        Length:
            -This function could be O(n) in normal array length functions, as we already have a variable that memorizes the length of array and is up to date, we just 
            return that variable, which is size; returning size makes this function O(1), instead of O(n).
        
        Average:
            -This function is constant, because it depends on work of size and lenght. In fact, the function itself does not do a work of O(n), if only does one operation
            which is division. in division, it gives control to sum() and length and then divide the values returned from these two function;
            -To conclude, the function avg() itself is constant which is O(1);


*/