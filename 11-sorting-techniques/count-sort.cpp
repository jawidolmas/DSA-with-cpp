#include<iostream>
using namespace std;

        /*
                SORTING TECHNIQUES:
                        COUNT SORT:
                            Count sort is the fastest algorithm for sorting a list. 
                            How it works? REMMEMBER finding duplicates in an array using hash method, we would take another array of size with biggest element in that 
                            array, and then we would traverse the array and if we see any value, we would increment the value in that index by 1, where initially they were 
                            0, that means, if list had 6, then index 6 at hash table will be 1. if appeard twice, it will be 2. 
                            This is exactly what COUNT sort does. it does the exact same procedure, and does one extra thing at the end, after hash table, it again copies 
                            the index number of those values that are not 0. for example index 6 is 2, then it will write 6 twice in sorted array. 
                            

                            Let's code




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
        void count();
        int max();
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

// Max for finding max element in list
int Sort::max(){
    int maximum = A[0];
    for(int i = 0; i<size; i++){
        if(A[i] > maximum){
            maximum = A[i];
        }
    }
    return maximum;
}

// Count Sort
void Sort::count(){
    int Max = max();
    Sort s1(Max+1);
    for(int i = 0; i<s1.capacity; i++){        // init new array 0
        s1.A[i] = 0;
        s1.size++;
    }
    for(int i = 0; i<size; i++){
        s1.A[A[i]]++;
    }
    int i = 0, j = 0;
    while(i<Max+1){
        if(s1.A[i]>0){
            A[j++] = i;
            s1.A[i]--;
        }else{
            i++;
        }
    }
}


int main()
{
    int List[10] = {10, 20, 30, 40, 50, 3, 2, 65, 7, 8};
    Sort s1(10);
    s1.creatlist(List);
    s1.display();
    cout << "Sorted List:";
    s1.count();
    s1.display();



    return 0;
}

/*
            10 20 30 40 50 3 2 65 7 8 
            Sorted List:2 3 7 8 10 20 30 40 50 65 
*/


    /*     ANALYSIS:
              This function is fastest function among sort algorithms, but it consumes more space, suppose we have an array with size 5, and the value in index 3 is
              1000000, that means we will get array size 10000000 for just only to sort 5 elements. 
              Function is O(n) in both terms, space and time. so it belongs what n is. actually the space is belong to what exactly the largest element in array is, so we 
              can say O(n) for both as they are polynomail with degree 1.
    */