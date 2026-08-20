#include <iostream>
using namespace std;

/*  HEAP:
    Heapify:
        -Heapify is a method of creating a max or min heap faster than insertion method.
        HOW? we know that while creating or inserting in a heap, we adjust the nodes from leaf towards root. So, when root is 10 and leaf is 20, we
        send 20 to root and 10 to leaf to get a max heap, how many times it takes? it takes logn times for one insertion and takes nlogn times for
        n insertion. Can we create a little bit faster? YEAH, that is heapify.
        In heapify, logic is vice versa, in insertion we compare leaf to root, but in hear, we compare root to leaf, So, if an array given to us,
        we check its parent with leaf, as heap is a complete bin tree, there is logn leafs, so we dont modify those leafs because they are already sorted
        and no need to modify them, coz they dont have any child, in this case, we can reduce the time taken from nlogn for n. so HEAPIFY IS O(n).
*/

class Heap {
private:
    int *A;
    int capacity;
    int size;
    void swap(int &a, int &b) {
        int temp = 0;
        temp = a;
        a = b;
        b = temp;
    }
public:
    Heap(int cap, int root);
    ~Heap();
    void heapify(int i);
    void BuildHeap(){
    for(int i = size/2; i >= 1; i--)
        heapify(i);
    }
    void Fill(int *Ar, int n){
    for(int i = 0; i < n; i++)
        A[i+2] = Ar[i];
    size = n + 2;
}
    void display() const;
};

Heap::Heap(int cap, int root) {
    capacity = cap;
    A = new int[capacity];
    A[0] = 0;
    A[1] = root;
    size = 2;
}

Heap::~Heap() {
    delete []A;
}

// Heapify
void Heap::heapify(int i){
    int largest, left, right;

    while(true){
        largest = i;
        left = 2*i;
        right = 2*i + 1;

        if(left < size && A[left] > A[largest])
            largest = left;

        if(right < size && A[right] > A[largest])
            largest = right;

        if(largest == i)
            break;

        swap(A[i], A[largest]);
        i = largest;
    }
}

//Display
void Heap::display() const {
    for (int i = 1; i < size; i++) {
        cout << A[i] << " ";
    }
    cout << endl;
}

int main()
{
    Heap h1(10, 20);
    int Ar[] = {3, 45, 67, 89, 10};
    int size = 5;
    h1.Fill(Ar, size);
    h1.BuildHeap();
    h1.display();

    return 0;
}
