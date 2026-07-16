#include<iostream>
using namespace std;

// Search
// We have 2 foundational searches, 1. Linear search; 2. Binary search; of course we have other algorithms too.
// LINEAR SEARCH


class ArrayADT{
    private:
        int *A; // pointer to point to array's first add in heap
        int capacity; // number of indices inside array;
        int size;     // number of real value elements in array;
    public:
        ArrayADT(int cap);  // Constructor
        ~ArrayADT();        // Destructor
        void append(int value); // Append means add a value at the end of an array;
        void linearSearch(int key);
        void transmission(int key);
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
    if(size == capacity){   // Check if array is already full;
        std::cout << "Array is full\n";
        return;
    }
    A[size] = n;
    size++;         // increment size coz the latest index is occupied by new value n;
}



// Linear Search
/* What is linear search? A linear search is a search of index by index, it visits all indices until the value in index meets the key(value we are searching for)
   The best case can be when the key is at index 0 which will be constant O(1).
   The worst case can be when the key is at the last index which will be O(n).
   The average case, however, the calculation is hard, as a deep analysis we can see the: 
   we do 1 + 2 + 3 + ... + n search for a key, and this can be shown n(n+1)/2, so when we take the average of this, we divide by the full cases which is n;
   so n(n+1)/2/n, we can get n+1/2. 
   so to conclude, the average case will be O(n);
   */

void ArrayADT::linearSearch(int key){
    if(size == 0){
        std::cout << "Empty array\n";
        return;
    }
    bool found = false;
    for(int i = 0; i<size; i++){
        if(A[i] == key){
            std::cout << "The key " << key << " Found at index " << i << "  ";       
            found = true;
        }
    }
    if(!found){
    std::cout << "The key " << key << " not found\n";
}
}


/* As we can see it is O(n), what do you think if we could be able to reduce the work by only one step on each search?
    What it means? Right now, if we search for 6, it takes O(n) = O(6), what if we search for 6 again? do we need to do O(n) steps again?
    what if we shift 6 to index 4 and index for to 5th; in that case, if we search 6 again, we can find it by slightly less time than before, and if we 
    keep searching for 6, finally, we will reduce O(n) to O(1); The search engines should definitely use these algorithms somehow. so lets see. 
    We name this algorithm as Transmission search, which is improved version of linear search; 
*/


// Lets build a swap function for swaping vlaues quickly;

void Swap(int &a, int &b){
    int temp = 0;
    temp = a;
    a = b;
    b = temp;
}

// Transmission linear search
void ArrayADT::transmission(int key){
    if(size == 0){
        std::cout << "Empty array\n";
        return;
    }
    bool found = false;
    for(int i = 0; i<size; i++){
        
        if(A[i] == key){
            if(i > 0){      // if i = 0, then dont do this step because A[0] -> A[-1], -1 is invalid in array and C++ silently writes it. DANGEROUS;
            Swap(A[i], A[i-1]);
            }
            std::cout << "The key " << key << " Found at index " << i << "  ";       
            found = true;
        }
    }
    if(!found){
    std::cout << "The key " << key << " not found\n";
}
}




int main()
{
    int Values[] = {1, 2, 3, 4, 5, 6};
    ArrayADT arr(6);
    for(int i = 0; i<6; i++){
        arr.append(Values[i]);
    } 
    arr.transmission(6);
    return 0;
}


/*

So, now if we run this: 
    arr.transmission(6);
    arr.display();
    arr.transmission(6);
    arr.display();
    arr.transmission(6);
    arr.display();
    arr.transmission(6);
    arr.display();

then we will get: 

The key 6 Found at index 5  1 2 3 4 6 5 
The key 6 Found at index 4  1 2 3 6 4 5 
The key 6 Found at index 3  1 2 6 3 4 5 
The key 6 Found at index 2  1 6 2 3 4 5 

*/