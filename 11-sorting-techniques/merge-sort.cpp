#include<iostream>
using namespace std;

        /*
                SORTING TECHNIQUES:
                        MERGE SORT:
                            Merge sort is sorting two sorted lists in a single sorted list. 
                            There are three kinds of mergin:
                                1. Mergin Two array lists: Mergin two independent A and B array lists into one sorted list C. 
                                2. Mergin two lists in a single array: Having an array with two lists inside, like 2, 4, 5, 12|3, 6, 7, 8 is a single 8 indexed array but we 
                                will merge them inside the same array that sorting happens. it is sorted from 2 to 12 and sorted from 3 to 8 and divided into two segment of 
                                sorted lists inside one array. We will take three variables, low, high and middle, as binary search, and we will compare low with middle + 1 until 
                                until mid and mid will go until high, i and j. After mergin, we will re-fill the original array with the new sorted array. 
                                3. Merging more than two lists, like A, B, C, D. This is called multi-way merging. ABCD will be 4-way merging. In here we can use two methods
                                first is that we can compare each index of all 4 lists, like 0th index of all, and add the smallest in E. 
                                The second one is that we merge A and B in a new list E first, then we wil C and D in new list F, then we will merge E and F. 


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
        void Merge(Sort &l1, Sort &l2);
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


// Merge Sort:
void Sort::Merge(Sort &l1, Sort &l2){
    int i=0, j=0, k=0;
    Sort l3(l1.size+l2.size);
    while(i<l1.size && j < l2.size){
        if(l1.A[i] < l2.A[j]){
            l3.A[k++] = l1.A[i++];
            l3.size++;
        }else{
            l3.A[k++] = l2.A[j++];
            l3.size++;
        }
    }
    for(; i<l1.size; i++){
        l3.A[k++] = l1.A[i];
        l3.size++;
    }
    for(; j<l2.size; j++){
        l3.A[k++] = l2.A[j];
        l3.size++;
    }
    l3.display();
}


int main()
{
    int List[5] = {10, 20, 30, 40, 50};
    int List1[5] = {60, 70, 80, 90, 100};
    Sort s1(5);
    Sort s2(5);
    s1.creatlist(List);
    s2.creatlist(List1);
    s1.display();
    s2.display();
    cout << "Sorted List:";
    s1.Merge(s1, s2);



    return 0;
}

/*
            10 20 30 40 50 
            60 70 80 90 100 
            Sorted List: 10 20 30 40 50 60 70 80 90 100 
*/


    /*     ANALYSIS:
                MOSTLY, we call merge sort is Omega(m+n);
                Merge sort is O(n log n) in all cases (best, average, worst), in terms of time and O(n) in terms of space (auxiliary array). It works by
                dividing the list into two halves, recursively sorting each half, then merging the two sorted halves back together. Merge itself is O(n)
                per call, since it's just a linear scan comparing fronts of both halves, and there are log n levels of splitting, hence O(n log n) always.
                No worst case blowup like quicksort, since splitting is always balanced regardless of input order. MERGE SORT IS STABLE, since equal
                elements from the left half are always placed before equal elements from the right half during merge. IT IS NOT IN-PLACE, requires extra
                array space to hold merged result.

    */