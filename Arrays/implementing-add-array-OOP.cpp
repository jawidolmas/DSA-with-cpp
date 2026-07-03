#include<iostream>


//Simple implementaion of add(element) function using OOP

class DynamicArray{
    private:
        int *data;
        int capacity;
        int size;

        void resize(){
            capacity *= 2;
            int *newData = new int[capacity];
            for (int i=0; i<size; ++i){
                newData[i] = data[i];
            }
            delete []data;
            data = newData;
        }
    public:
        DynamicArray(int initialcapacity = 4) : capacity(initialcapacity), size(0) {
            if (capacity <= 0) capacity = 4;
            data = new int[capacity];
        }
        ~DynamicArray(){
            delete []data;
        }
        void add(int element);
};

void DynamicArray::add(int element){
    if (size == capacity){
        resize();
    }
    data[size] = element;
    size++;
}


int main(){
    DynamicArray arr;
    arr.add(7);


    return 0;
}