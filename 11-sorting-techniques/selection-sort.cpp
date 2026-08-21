#include<iostream>
using namespace std;

        /*
                SORTING TECHNIQUES:
                        SELECTION SORT:
                            Selection sort is kind of sorting technique which uses selection, that means it selects a position and search for the list who should sit in 
                            there, like having a seat and searching for the smallest student to sit in that chair. 

                            IT IS NIETHER STABLE NOR ADAPTIVE. the original order of values can not be preserved and also INSERTION sort is always O(n^2). it cannot get 
                            advantages from a sorted list. 


                            lets code

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
        void Selection();
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

//Selection Sort
void Sort::Selection(){
    int i, j, k;
    for(i = 0; i<size-1; i++){
        for(j=k=i; j<size; j++){
            if(A[j] < A[k]){
                k = j;
            }
        }
        swap(A[i], A[k]);
    }
    cout << "Sorted List:";
    display();
}


int main()
{
    int List[5] = {78, 44, 33, 22, 10};
    Sort s1(5);
    s1.creatlist(List);
    s1.display();
    s1.Selection();


    return 0;
}

/*
            78 44 33 22 10 
            Sorted List:10 22 33 44 78 

*/


    /*     ANALYSIS:
                Selection sort is O(n^2) in terms of time and O(1) in terms of space. It has a nested loop and on each iteration it does two things and one of them will be 
                done for 1+2+3+4+....n-1 times, comparison will be done for these unit of time and makes it O(n^2), While swap is done for n-1 times which is O(n), THIS IS THE
                ONLY ALGORITHM WHICH HAS THE MINIMUM NUMBER OF SWAP. 

    */