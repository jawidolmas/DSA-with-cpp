#include<iostream>

using namespace std;

/*
    This program is a basic struct operations in C++. 
    In this program, you can see how a struct groups varaibles. 
    Moreover, you can investivate the critical difference between copying memory (by value) and pointing to memory (by reference).

   */

struct Student
{   
    string name;
    int id;
    float gpa;
};

void printStudentByValue(Student s1){
    // This creates a complete copy of structure in memory, which can be inefficient for large dataset. 
    cout <<"Name: " <<  s1.name << endl; 
    cout <<"ID  : " <<  s1.id << endl;
    cout <<"GPA : " <<  s1.gpa << endl;
}

void updateGpaByReference(Student &s1, float new_gpa){
    // This is modifies the student's original data inside the struct as function passing by reference. 
    s1.gpa = new_gpa;
}

struct MyStruct{
    double x; // 8 bytes
    int  y; //  4 bytes;
    char z; // 1 byte. 
};  // The total size of this struct is not 13, it is 16. CPU works for speed, not for efficiency. The size of a struct must be the multiple of the largest members alignement. here the double is 8, so 
    // the total size of array should be mutilple of 8 which is 16. eg. when we go to a pharmacy, they give us a stripe not only one tablet, coz it is easy for pharmacist to sell one stripe than one tablet. 

struct MyStruct2{
    char x;
    double y;
    int z;
};     // This struct size is 24, not 16. because, the char is 1 byte + 7 padding bytes, double is 8 bytes, int is 4 + 4 padding bytes. so its simply 24 bytes. 24 is the multiple of 8 which is double's size.

int main(){

    // Size of a struct is the total size of all its members plus any padding added for alignment.
    
    Student s2;
    s2.name = "Jawid";
    s2.id  = 125;
    s2.gpa = 3.28;
    printStudentByValue(s2);
    updateGpaByReference(s2, 3.14);
    printStudentByValue(s2);
    return 0;
}
