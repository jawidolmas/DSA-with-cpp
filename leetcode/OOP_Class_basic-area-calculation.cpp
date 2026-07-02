#include<iostream>
#include<string>


/*Task 2 — Rectangle Class

Create a class named Rectangle.

It should store:

Length
Width

Create member functions to:

Input the values.
Calculate the area.
Display the area.
Expected Output
Enter length: 8
Enter width: 5

Area = 40.*/

class Rectangle{
    private:
        int length;
        int width;
    public:
        void setData(int a, int b){
            length = a;
            width  = b;
        }
        int CalcArea() const{
            return width * length;
        }
        void display() const{
            int result = CalcArea();
            std::cout << "Area:  " << result << std::endl;
        }

};


int main(){

    int inputLength;
    int inputWidth;
    std::cout << "Enter length: ";
    std::cin >> inputLength;
    std::cout << "Enter width: ";
    std::cin >> inputWidth;
    Rectangle r1;
    r1.setData(inputLength, inputWidth);
    r1.display();

    return 0;
}