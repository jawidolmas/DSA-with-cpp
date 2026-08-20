#include <iostream>
using namespace std;


        /*      HEAP:   
                        Deletion in Bin Heap
                        For deleting, in a heap, we cannot delete the leaf or any other node we want, we can only and only delete by root, that means WE CAN DELETE 
                        ONLY BY PRIORITY QUEUE. but how we can handle the bin heap rules when we delete from root? what will get the place of root?
                        When we delete the root, we will bring the last element in heap in root, that means, the last leaf will take the place of root, after that
                        we will sort it, check for child of root, which one is bigger, then swap root with that bigger child if root is smaller than childs too. and 
                        do this until we get to end of heap, means size. 

                        -ONE EXCLUSIVELY IMPORTANT THING:
                                *When we delete a value from array, we simply take that value in a temp varaible, then should we throw it away? NO, coz we have place inside
                                 array which is outside of heap, it means, when we moved the last leaf node to the root, now the place of that leaf node is empty, and is out
                                 of heap, we can simply store the value we deleted in there, and if we do this for n times, then we will have a sorted array. THIS IS CALLED
                                 HEAP SORT. 

                                 How to get a heap sort?
                                        1. CREATE A HEAP
                                        2. DELETE THE HEAP
                                           HERE WE GO, WE HAVE A SORT HEAP NOW. 
                
        */


class Heap{
        private:
                int *A;
                int capacity;
                int size;
                void swap(int &a, int &b){
                        int temp = 0;
                        temp = a;
                        a = b;
                        b = temp;
                }
        public:
                Heap(int cap, int root);
                ~Heap();
                void Insert(int n);
                void Createheap(int *Ar, int n);
                void InsertValue(int val);
                void display() const;
                void Delete();
};

Heap::Heap(int cap, int root){
        capacity = cap;
        A = new int[capacity];
        A[0] = 0;
        A[1] = root;
        size = 2;
}

Heap::~Heap(){
        delete []A;
}

// Insert
void Heap::Insert(int n){
        int temp, i = n;
        temp = A[n];
        while(i>1 && temp > A[i/2]){
                A[i] = A[i/2];
                i = i/2;
        }
        A[i] = temp;
}

// If we want to use Insert standalone
void Heap::InsertValue(int val){
    A[size] = val;
    Insert(size);
    size++;
}

// Create
void Heap::Createheap(int *Ar, int n){
        int i;
        for(i = 0; i<n; i++){
                A[i+2] = Ar[i];
        }
        size = n+2;
        for(i = 2; i<size; i++){
                Insert(i);
        }
}

//Display
void Heap::display() const{
        for (int i = 1; i<size; i++){
                cout << A[i] << " ";
        }
        cout << endl;
}

// Delete
void Heap::Delete(){
        int i, x, j;
        size--;
        x = A[1];
        A[1] = A[size];
        i = 1;
        j = 2*i;
        while(j <= size-1 && j < capacity){
                if(j+1 <= size-1 && A[j+1] > A[j]){
                        j = j+1;
                }
                if(A[i] < A[j]){
                        swap(A[i], A[j]);
                        i = j;
                        j = 2*j;
                }else break;
        }
        A[size] = x;
}


int main()
{
        Heap h1(10, 20);
        int Ar[] = {3, 45, 67, 89, 10};
        int size = 5;
        h1.Createheap(Ar, size);
        h1.display();
        h1.Delete();
        h1.display();   // 67 45 20 3 10
        return 0;
}



                /*
                        ANALYSIS:
                                Delete function is O(nlogn), becuase for each deletion we do logn units of work, and for how many times we repeat it? for n times, 
                                so it is O(nlogn), the space is O(1) as we only have i,j,x regardless of input. 
                */