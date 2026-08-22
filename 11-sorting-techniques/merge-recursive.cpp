#include<iostream>
using namespace std;

        /*
                SORTING TECHNIQUES:
                        MERGE SORT:
                            Merge sort recursive version

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
        void Merge(int l, int mid, int h);
        void MergeRecursive(int l, int h);
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
void Sort::MergeRecursive(int l, int h){
    int mid;
    if(l<h){
        mid = (l+h)/2;
        MergeRecursive(l, mid);
        MergeRecursive(mid+1, h);
        Merge(l, mid, h);
    }
}


int main()
{
    int List[10] = {10, 20, 30, 40, 50, 3, 2, 65, 7, 8};
    Sort s1(10);
    s1.creatlist(List);
    s1.display();
    cout << "Sorted List:";
    s1.MergeRecursive(0, 10);
    s1.display();



    return 0;
}

/*
            10 20 30 40 50 3 2 65 7 8 
            Sorted List:2 3 7 8 10 20 30 40 50 65 
*/


    /*     ANALYSIS:
                This function is O(nlogn) in terms of time and is O(n+logn) in terms of space. As we can see in code, that this function splits each list as like a tree
                and then Merges at the last step, that means, it merges left child with right child and grandleftchild with grandrightchild, which is a POSTORDER. 
                left+right+root. 
                it uses logn stack and 2n extra space for Merge sort which gets an extra object. so this is O(n+logn).

    */