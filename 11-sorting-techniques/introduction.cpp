#include<iostream>
using namespace std;

        /*
                SORTING TECHNIQUES:
                    Sorting techniques are used to sort lists in ascending or descending order, or simply to rearrange lists or data according to a particular rule. 
                    We have different kind of sortings like bubble sort, insertion sort and etc... 

                    CRITERIA FOR ANALYSIS:
                        We can analyze a sorting algorithm according to these criteria:
                            1. Number of Comparisons: How many comparison will be made while sorting a datas. 
                            2. Number of Swaps: How many data swap will be done. 
                            3. Adaptive: it means an algorithm gets advantages of an input, for example if an input is already sorted, then that algorithm can benefit the input
                            4. Stable: This means in a given input list, if there is a duplicate, then PRESERVING THE ORDER OF THOSE KEYS IS CALLED STABLE. For example, if a list 
                               contains 4, 2, 8, 5, 4, 5, 10. in here, 5 is duplicated, so when algorithm comparing 5 with 5, it does no work in there, so it doesnt swap those two 
                               elements and preserve how they actually were. 
                            5. Extra Memory: We have algorithms that uses extra memory for a time trade off, like Radix sort. 

                    1. Bubble sort, 2. Insertion Sort, 3. Selection Sort -> O(n^2) and Camparison based sorts
                    4. Heap Sort, 5. Merge Sort, 6. Quick Sort, 7. Tree Sort. ->O(nlogn) and Comparison Sorts
                    8. Shell Sort ->O(n^3/2) faster than O^2 and slower than nlogn, Camparison Based sort
                    9. Count Sort, 10. Bucket/Bin Sort, 11. Radix Sort -> O(n)->extra space -> Index Based Sort

                    We will implement and analyze all of these techniques one by one. MOSTLY IN ARRAYS

        */

class Sort{
    private:
        int *A;
        int capacity;
        int size;
    public:
        Sort(int cap);
        ~Sort();
};

Sort::Sort(int cap){
    capacity = cap;
    A = new int[capacity];
    size = 0;
}   

Sort::~Sort(){
    delete []A;
}



int main()
{



    return 0;
}