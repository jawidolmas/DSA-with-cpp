#include<iostream>
using namespace std;

        /*
                SORTING TECHNIQUES:
                    BUBBLE SORT:
                        First of all, why BUBLLE? 
                            Bubble sort named BUBBLE becuase, anything wieghted in a water will go down while anything lighter will come at top of water. Suppose, we 
                            are throwing a stone in water, so stone will go down while BUBBLE will go up, so the algortihm works the exact same way, the largest values 
                            will go down in a vertical represented list on each pass, and eventually will give us a sorted list where lighter things in top and wieghted things 
                            in bottom. 

                            The Bubble sort is Comparison Based algorithm, so we compare and swap. thats the idea. 
                            Bubble sort is adaptive, in fact, we make it adaptive by giving a helper varaible 'flag', if an swap action happened, flag = 1, if not flag=0
                            so we can know in here if the algorithm is benefited from input or not. 
                            Bubble sort is stable also, if a two same value compared there will be no swap, coz the condition is A[j]>A[j+1].

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
        void Bubble();
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


// Bubble Sort
void Sort::Bubble(){
    int flag, i, j;
    for(i = 0; i<size-1; i++){
        flag = 0;
        for(j=0; j<size-1-i; j++){
            if(A[j] > A[j+1]){
                swap(A[j], A[j+1]);
                flag = 1;
            }
        }
        if(flag == 0){
            if(i==0){           // First pass, no swaps happened
                cout << "Already Sorted\n";
                return;
            }
            break;
        }
    }
    cout << "Sorted List: ";
    display();
}





int main()
{
    int List[5] = {2, 12, 3, 4, 78};
    Sort s1(5);
    s1.creatlist(List);
    s1.display();
    s1.Bubble();


    return 0;
}

/*
        2 12 3 4 78 
        Sorted List: 2 3 4 12 78 

*/


    /*     ANALYSIS:
                Bubble sort is O(n^2) in terms of time and O(1) in terms of space. It has a nested loop and on each iteration it does two things and both of them will be 
                done for 1+2+3+4+....n-1 times, swap and comparison will be done for these unit of time and makes it O(n^2), adaptive bubble sort is O(n). 

    */