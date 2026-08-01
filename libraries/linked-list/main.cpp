#include <iostream>
#include "linkedlist.hpp"

int main()
{
    linkedlist lin;

    std::cout << "-- isEmpty on new list --\n";
    std::cout << lin.isEmpty() << std::endl;   // expect 1

    std::cout << "-- append 10,20,30,40,50 --\n";
    lin.append(10);
    lin.append(20);
    lin.append(30);
    lin.append(50);
    lin.append(50);
    lin.display();                             // 10 20 30 40 50
    std::cout << lin.searchRec(60) << std::endl;
    lin.display();
    

    return 0;
}