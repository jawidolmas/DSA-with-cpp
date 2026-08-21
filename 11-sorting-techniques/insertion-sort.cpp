#include<iostream>
using namespace std;

        /*
                SORTING TECHNIQUES:
                    INSERTION SORT:
                            Insertion sort comes from inserting, we assume that list has only one key and one key is sorted by defualt and then insert keys one by one in
                            sorted order. thats it.

                            Insertion sort is adaptive by nature, so we dont flag it manually, it is adaptive by defualt.
                            Insertion sort is also stable. so it can preserve the duplicated keys as they were. 

                            ***INSERTION SORT IS DESIGNED FOR LINKED LIST. BECUASE IT IS MORE BETTER FOR LINKED LIST THAN ARRAYS


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
        void Insertion();
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

// Insertion Sort
void Sort::Insertion(){
    int i, j, x;
    for(i = 1; i<size; i++){ //i = 1, means first key is already sorted, coz only one key exist
        j = i - 1;
        x = A[i];
        while(j >-1 && A[j] > x){
            A[j+1] = A[j];
            j--;
        }
        A[j+1] = x;
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
    s1.Insertion();


    return 0;
}

/*
            78 44 33 22 10 
            Sorted List:10 22 33 44 78 

*/


    /*     ANALYSIS:
                Insertion sort is O(n^2) in terms of time and O(1) in terms of space. It has a nested loop and on each iteration it does two things and both of them will be 
                done for 1+2+3+4+....n-1 times, shifting and comparison will be done for these unit of time and makes it O(n^2), adaptive insertion sort is O(n). coz its
                the minimum time it can take if already sorted.  

    */