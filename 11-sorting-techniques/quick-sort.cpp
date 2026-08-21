#include<iostream>
using namespace std;

        /*
                SORTING TECHNIQUES:
                        QUICK SORT
                            Quick sort is not the fastest sort, just in case to now confused with its name.
                            Example: If there is a students with different height and a teacher that wants to arrange them in an increasing order. THERE is two situation 
                            for teacher to do that. 
                            1. Teacher will take each student and arrange one by one, like A first then B and so on
                            2. Teacher will tell students that students should arrange by themselves, teacher will tell students like : Everyone should find the suitable 
                            place for theirselves according to their height. 
                            
                            Now, which one is fast? Of course the second one, students will may just compare thier own height with the ones that they are taller and shorter. 
                            THIS IS CALLED QUICK SORT. 

                            Quick sort works: it takes a list, and selects a key called pivot, the very first element, the i will be at first and j will be at last, after that
                            i checks j, if i value is smaller or equal to pivot, do nothing move forward, if j value is bigger than pivot do nothing move backward.
                            Once i < j, then swap, and do it for a loop which i < j. THIS PROCEDURE IS CALLED PARTITION, that means, we split list into two, and their will be a 
                            middle key, all elements smaller than key will be in left hand side of key and bigger elements in right hand of key. 
                            in fact, the last sentence is QUICK sort itself, we do this recursivly until all elements get solved. in fact we did partition and sorting. 
                            
                            this is the reason we can call Quick sort as PARTITION EXCHANGE and  SELECTION EXCHANGE. COZ IT IS COMBINATION OF RECURSION AND PARTITIONS. 

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
        void Quick(int l, int h);
        int Partition(int l, int h);
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

//Helper Partition function
int Sort::Partition(int l, int h){
    int pivot = A[l];
    int i=l, j = h;
    do{
        do{i++;}while(A[i]<=pivot);
        do{j--;}while(A[j]>pivot);
        if(i<j){
            swap(A[i], A[j]);
        }
    }while(i<j);
    swap(A[l], A[j]);
    return j;
}

// Quick Sort
void Sort::Quick(int l, int h){
    int j;
    if
    (l<h){
        j = Partition(l, h);
        Quick(l, j);
        Quick(j+1, h);
    }
}


int main()
{
    int List[6] = {78, 44, 33, 22, 10, INT_MAX};
    Sort s1(6);
    s1.creatlist(List);
    s1.display();
    s1.Quick(0, 5);
    cout << "Sorted List:";
    s1.display();


    return 0;
}

/*
            78 44 33 22 10  
            Sorted List:10 22 33 44 78

*/


    /*     ANALYSIS:
                Quick sort is O(n log n) average case, O(n^2) worst case, in terms of time and O(log n) in terms of space (recursion stack). It works by picking
                a pivot and partitioning the array around it, so smaller values go left and larger go right, then recursively sorting both sides. Partition
                itself is O(n) per call, and average case gives log n levels of recursion, hence O(n log n). Worst case happens when pivot is always smallest
                or largest element (already sorted input), giving n levels instead of log n, hence O(n^2). QUICK SORT IS NOT STABLE, since swaps during
                partition can change relative order of equal elements. IT IS IN-PLACE, only using extra space for recursion calls.

    */