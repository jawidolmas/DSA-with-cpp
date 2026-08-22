#include<iostream>
using namespace std;

        /*
                SORTING TECHNIQUES:
                        Shell Sort:
                            This sort uses the method of insertion but a little bit flexible and improved. 

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
        void Shell();
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

// Shell Sort:
void Sort::Shell(){
    int gap, i, j, temp;
    for(gap = size/2; gap>=1; gap/=2){
        for(i=gap; i<size; i++){
            temp = A[i];
            j = i - gap;
            while(j>=0 && A[j] > temp){
                A[j+gap] = A[j];
                j = j - gap;
            }
            A[j+gap] = temp;
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
    s1.Shell();
    s1.display();



    return 0;
}

/*
            10 20 30 40 50 3 2 65 7 8 
            Sorted List:2 3 7 8 10 20 30 40 50 65 
*/


    /*     ANALYSIS:
                This function is O(nlogn) and sometimes it is analyzed as O(n^3/2). This uses a gap method and scans each index for n times, after that, there will be 
                logn passes for n value. Shell method has been named upon the person who discovered this method. 
                
    */