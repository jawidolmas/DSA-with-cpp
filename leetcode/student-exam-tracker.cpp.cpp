#include<iostream>
#include<string>


/*Task 1 — Exam Result

Create a class named Exam.

It stores:

Student name
Three exam scores

Member functions:

Input the data.
Calculate the average.
Print whether the student Passed or Failed.

A student passes if the average is 50 or higher.

Expected Output
Enter name: Jawid
Enter score 1: 80
Enter score 2: 65
Enter score 3: 55

Average: 66.67
Result: Passed*/

template<class T>
class Exam{
    private:
        std::string name;
        T a, b, c;
        const int exams = 3;
    public:
        Exam() : name(""), a(0), b(0), c(0) {}
        Exam(std::string username, T a, T b, T c);
        T calculateAvg();
        void status();
};

template<class T>
Exam<T>::Exam(std::string username, T a, T b, T c){
    name = username;
    this->a = a;
    this->b = b;
    this->c = c;
}



template<class T>
T Exam<T>::calculateAvg(){
    if (a < 0 || b < 0 || c < 0){
        std::cout << "Invalid marks! Marks should be bigger than 0\n";
        return 0.0;
    } 
    T avg = (a + b + c) / exams;
    return avg;
}

template<class T>
void Exam<T>::status(){
    double final = calculateAvg();
    std::cout << "Username: " << name << std::endl;
    std::cout << "Average:  "<< final << std::endl;
    if (final < 50){
        std::cout << "Status: Failed\n";
    } 
    else{
        std::cout << "Status: Passed\n";
    }
}


int main(){

    Exam<float> e1("Jawid", 80, 50, 60);
    e1.status(); 
    return 0;
}