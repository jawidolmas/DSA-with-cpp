#include <iostream>
using namespace std;


        /*      HEAP:
                   **Heap in Data Structures are fundamentally different from heap in memory. 
                    *Heap in DS is an abstract, ordered data structures like priority queues, while heap inside memory is an unorganized region of raw memories which
                    taken by OS/runtime. 

                    In here we will highly learn about Binary heap:
                        Conditions for a Binary heap:
                          1. Should always be a complete binary tree. There should be no blank in between of two index when stored in an array
                          2. Every node should have elements which are greater or equal to its descendants which means elements can be duplicated as well. This heap is
                             called max heap.
                          3.Every node should  have elements which are smaller or equal to its descendants. This heap is called min heap.

                        Important:
                          1. We use arrays mostly to store a heap, becuase as heaps are complete binary tree and storing complete binary tree in arrays is much more
                             suffecient than storing in linked list. we can use linked list as well, but we use array mostly. 
                          2. Height of a binary tree will always be logn. 
                          3. Heap is not used for searching conversely to BST. 
                          
                        How can we create a binary heap? 
                          -For creating binary heap, the logic is simple, we will have an array and that is should start from 1 index, as to meet the rules of storing a 
                           tree in array. For the very first index, we must have a value in array which represents root, if not we cannot have anything to compare the 
                           insertion with it. That means, we will have an array which index 0th will be 0 and 1st index will be root value, after that, we will use the 
                           logic of insertion for all other values entering the heap. if we have an array like {10, 20, 30, 5, 4, 69, 56}, then only 10 will be inside heap
                           and all other values will get in heap when they inserted, if not, they will remain out of heap. 
                        Now How insertion works?
                          -Insertion is similar to inserting a value in an array, we will take the value which is going to be inserted, save it in a temp array and then 
                           we will compare it to its parents, if temp value is greater than its parent, then we will replace/inplace the parent with child, the again will 
                           compare child to its grandparent and so on, when child gets smaller than any of its parents, then we will simply insert it before its greatest parent. 
                        We have a formula for finding parents: (Arrays only)
                           1. For finding left child: 2*i 
                           2. For finding right child: 2*i + 1
                           3. For finding parent of a child: i/2 ->floor 
                
                Let's code insert first, as we will gonna use insert inside create. 
        */


class Heap{
        private:
                int *A;
                int capacity;
                int size;
        public:
                Heap(int cap);
                ~Heap();
                void Insert(int *A, int n);
                void Createheap();
};

Heap::Heap(int cap){
        capacity = cap;
        A = new int[capacity];
        size = 0;
}

Heap::~Heap(){
        delete []A;
}

// Insert
void Heap::Insert(int *A, int n){
        int temp, i = n;
        temp = A[n];
        while(i>1 && temp > A[i/2]){
                A[i] = A[i/2];
                i = i/2;
        }
        A[i] = temp;
}


