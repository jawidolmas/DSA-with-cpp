#include<iostream>
#include "string.hpp"


MyString::MyString(const char *s){
    size = 0;
    while(s[size]!= '\0') size++;

    capacity = size;
    data = new char[capacity + 1];

    for(size_t i = 0; i<size; i++){
        data[i] = s[i];
    }
    data[size] = '\0';
}

MyString::~MyString(){
        delete []data;
}




//Display
void MyString::display() const{
    for(int i = 0; data[i]!='\0'; i++){
        std::cout << data[i];
    }
    std::cout << std::endl;
}

//length

int MyString::length() const{
    return size;
};

// is Full
bool MyString::isFull() const{
    if(size == capacity){
        return true;
    }
    else return false;
}

// is Empty
bool MyString::isEmpty() const{
    if(size == 0){
        return true;
    }
    else return false;
}
