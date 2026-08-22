#include<iostream>
using namespace std;

        /*
                SORTING TECHNIQUES:
                        MERGE SORT:
                            Merge sort iterative version

                                We can code merges in recursive and iterative ways. 

                                Let's code.




        */

class Sort{
    private:
        int *A;
        int capacity;
        int size;
        void swap(int &a, int &b){
            int temp = a;
            a = b;
            b = temp;
        }
    public:
        Sort(int cap);
        ~Sort();
        void creatlist(int *B);
        void Merge( int l, int mid, int h);
        void MergeIterative();
        void display(){
            for(int i = 0; i<size; i++){
                cout << A[i] << " ";
            }
            cout << endl;
        }
};

Sort::Sort(int cap){
    capacity = cap;
    A = new int[capacity];
    size = 0;
}   

Sort::~Sort(){
    delete []A;
}

void Sort::creatlist(int *B){
    for(int i = 0; i<capacity; i++){
        A[i] = B[i];
        size++;
    }
}


// Merge Sort: Second case: One array and merging them inside
void Sort::Merge(int l, int mid, int h){
    int i=l, j=mid+1, k=0;
    Sort l3(h-l+1);
    while(i<=mid && j<=h){
        if(A[i] < A[j]){
            l3.A[k++] = A[i++];
            l3.size++;
        }else{
            l3.A[k++] = A[j++];
            l3.size++;
        }
    }
    for(; i<=mid; i++){
        l3.A[k++] = A[i];
        l3.size++;
    }
    for(; j<=h; j++){
        l3.A[k++] = A[j];
    }
    for(int i = 0; i<k; i++){
        A[l+i] = l3.A[i];
    }
}

// Iterative Merge Sort
void Sort::MergeIterative(){
    int p, i, l, mid, h;
    for(p = 2; p<=size; p=p*2){
        for(i = 0; i+p-1<size; i=i+p){
            l = i;
            h = i+p-1;
            mid = (l+h)/2;
            Merge(l, mid, h);
        }
    }
    if(p/2 < size){
        Merge(0, p/2-1, size-1);
    }
}


int main()
{
    int List[10] = {10, 20, 30, 40, 50, 3, 2, 65, 7, 8};
    Sort s1(10);
    s1.creatlist(List);
    s1.display();
    cout << "Sorted List:"; 
    s1.MergeIterative();
    s1.display();



    return 0;
}

/*
            10 20 30 40 50 3 2 65 7 8 
            Sorted List:2 3 7 8 10 20 30 40 50 65 
*/


    /*     ANALYSIS:
                Merge sort is O(n log n) in all cases (best, average, worst), in terms of time and O(n) in terms of space (auxiliary array). It works by
                dividing the list into two halves, recursively sorting each half, then merging the two sorted halves back together. Merge itself is O(n)
                per call, since it's just a linear scan comparing fronts of both halves, and there are log n levels of splitting, hence O(n log n) always.
                No worst case blowup like quicksort, since splitting is always balanced regardless of input order. MERGE SORT IS STABLE, since equal
                elements from the left half are always placed before equal elements from the right half during merge. IT IS NOT IN-PLACE, requires extra
                array space to hold merged result.

    */