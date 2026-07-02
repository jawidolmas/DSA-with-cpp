#include<iostream>
#include<string>


/*Create a class named Temperature.

It stores:

Celsius

Member functions:

Input Celsius.
Convert to Fahrenheit.
Display both values.

Formula:

F = (C × 9 / 5) + 32
Expected Output
Enter Celsius: 25

Celsius: 25
Fahrenheit: 77*/
class Temprature{
    private: 
        int celsius;
    public:
        Temprature(int t){
            celsius = t;
        };
        int convertToFehre();
        void display();
};

int Temprature::convertToFehre(){
    int Feh = (celsius * 9)/5 + 32;
    return Feh;
}

void Temprature::display(){
    std::cout << "Celsius: " << celsius << std::endl;
    std::cout << "Fehrenheit: " << convertToFehre() << std::endl; 
}

int main(){
    int inputCel;
    std::cout << "Enter Celsius:";
    std::cin >> inputCel;
    Temprature t1(inputCel);
    t1.display();
    return 0;
}