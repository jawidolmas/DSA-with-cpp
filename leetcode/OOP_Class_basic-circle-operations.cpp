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

// When we create a class for a specific data type such as integer, and after a period of time if we need another class type of double, 
//we must create a new class of type double. BUT THAT WILL WASTE OF TIME and bad programming. 
// Template gives us the ability to create any type of data within the same class. 
template<class T>
class Circle{

    private:
        T radius;
        const double pi = 3.14;
    public:
        Circle(){radius = 0;}
        Circle(T rad);
        T circum() const;
        T area() const;
};

    template<class T>
    Circle<T>::Circle(T rad){
        radius = rad;
    }
    template<class T>
    T Circle<T>::circum() const{
        return 2 * pi * radius;
    }
    template<class T>
    T Circle<T>::area() const{
        return pi * (radius * radius);
    }



int main(){

    double rad;
    std::cout << "Enter Radius: ";
    std::cin >> rad;

    Circle<double> c(rad);
    std::cout << "Area: " << c.area() << std::endl;
    std::cout << "Circumferance: " << c.circum() << std::endl;

    return 0;
}
