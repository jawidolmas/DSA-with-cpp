#include<iostream>
#include<string>


/*Create a class named Circle.

It should store:

Radius

Create member functions to:

Input the radius.
Calculate the circumference.
Calculate the area.
Display both results.

Use π = 3.14.

Expected Output
Enter radius: 7

Area = 153.86
Circumference = 43.96*/

class Circle{

    private:
        double radius;
        double pi = 3.14;
    public:
        Circle(){radius = 0;}
        Circle(double rad);
        double circum() const;
        double area() const;
};

    Circle::Circle(double rad){
        radius = rad;
    }
    double Circle::circum() const{
        return 2 * pi * radius;
    }
    double Circle::area() const{
        return pi * (radius * radius);
    }



int main(){

    double rad;
    std::cout << "Enter Radius: ";
    std::cin >> rad;

    Circle c(rad);
    std::cout << "Area: " << c.area() << std::endl;
    std::cout << "Circumferance: " << c.circum() << std::endl;

    return 0;
}