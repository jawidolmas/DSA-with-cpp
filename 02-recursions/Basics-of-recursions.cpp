#include<iostream>


// Simple code for defining recursion;
// Recursion is a function which it calls itself for solving a problem until a base case gets false.
// The difference between a recursion and loop is they both repeat an instruction. However, recursion has two phases of calling and returning where loop has only one phase of calling(ascending); 
// All recursions uses tree.
class Recursion{
    private: 
        int n;
    public:
        Recursion() : n(0){}
        void func1(int num) const;
        void func2(int num2) const;
};

void Recursion::func1(int num) const{
    // First prints the data, then calls it self to decrement the number until num becomes less than 0;
    if (num > 0){
        std::cout << num;
        func1(num - 1);
    }
}

void Recursion::func2(int num2) const{
    // First does the decrementation, after hitting the base case, it returns each value as a tree. 
    if(num2 > 0){
        func2(num2 - 1);
        std::cout << num2; 
    }
}




int main(){             
    
    Recursion r1;
    r1.func1(3);
    std::cout << std::endl;
    r1.func2(3);


    return 0;
}


