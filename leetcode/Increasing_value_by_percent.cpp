#include<iostream>
using namespace std;

//Task1 - Write a program which takes a struct of employees and increases its salary by given percent
//Passing a struct by reference
//Modifying the original object
struct Employee{

    string name;
    float salary;
};

void increaseByPercent(Employee &e1, float percent){

    e1.salary = e1.salary + (e1.salary*percent);
    cout << "New Salary: "<<e1.salary;
}


int main(){

    Employee e1 = {"Jawid", 2000};
    cout << "Before: " << e1.salary << endl;
    increaseByPercent(e1, 0.10);


    return 0;
}