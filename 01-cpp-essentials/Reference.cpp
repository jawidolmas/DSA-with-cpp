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
