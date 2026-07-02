#include<iostream>
#include<string>


/*Create a class named Calculator.

It stores:

Two numbers

Member functions:

Input numbers.
Add
Subtract
Multiply
Divide

Display all four results.

If the second number is zero, print:

Cannot divide by zero.
Expected Output
Enter first number: 12
Enter second number: 4

Addition: 16
Subtraction: 8
Multiplication: 48
Division: 3*/
class Calculator{
    private: 
        double num;
        double num2;
    public:
        Calculator(double x, double y){
            num = x;
            num2 = y;
        }
        double add() const;
        double subtract() const;
        double multiply() const;
        double divide() const;
        void display() const;
};


double Calculator::add() const{
    return num + num2;
}
double Calculator::subtract() const{
    return num - num2;
}
double Calculator::multiply() const{
    return num*num2;
}
double Calculator::divide() const{
    if (num2 == 0){
        std::cout << "Error: Cant divide by 0\n"; // Just in case anyone calls c1.divide(); directly
        // we need to handle the return, even it is a simple Error message, it again runs the return num/num2 anyway. return -1 fails when num = -5 num2 = 5; currently we cannot handle at this level(we may need external libraries).
    }
    return num/num2;
}

void Calculator::display() const{
    std::cout << "Addition: " << add() << std::endl;
    std::cout << "Subtraction: " << subtract() << std::endl;
    std::cout << "Multiplication: " << multiply() << std::endl;
    if(num2 == 0){
        std::cout << "Cannot divide by zero: " << std::endl;
        return;
    } else{
    std::cout << "Division: " << divide() << std::endl;
    }

}


int main(){
    double number1=0, number2=0;
    std::cout << "Enter Number 1: " << "Enter Number 2:";
    std::cin >> number1 >> number2;
    Calculator c1(number1, number2);
    c1.display();
    return 0;
}