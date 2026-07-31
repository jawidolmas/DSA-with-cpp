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
    lin.append(40);
    lin.append(50);
    lin.display();                             // 10 20 30 40 50
    std::cout << "length: " << lin.length() << std::endl; // 5

    std::cout << "-- isEmpty after append --\n";
    std::cout << lin.isEmpty() << std::endl;   // expect 0

    std::cout << "-- prepend 5 --\n";
    lin.prepend(5);
    lin.display();                             // 5 10 20 30 40 50

    std::cout << "-- insert 999 at index 2 --\n";
    lin.insert(2, 999);
    lin.display();                             // 5 10 999 20 30 40 50

    std::cout << "-- getElement(0), getElement(3) --\n";
    std::cout << lin.getElement(0) << " " << lin.getElement(3) << std::endl;

    std::cout << "-- setElement(3, 111) --\n";
    lin.setElement(3, 111);
    lin.display();                            // 5 10 999 111 30 40 50

    std::cout << "-- linearSearch(111), linearSearch(7777) --\n";
    std::cout << lin.linearSearch(111) << " " << lin.linearSearch(7777) << std::endl;

    std::cout << "-- removeFirst --\n";
    std::cout << "removed: " << lin.removeFirst() << std::endl;
    lin.display();

    std::cout << "-- removeLast --\n";
    std::cout << "removed: " << lin.removeLast() << std::endl;
    lin.display();

    std::cout << "-- removeIndex(1) --\n";
    std::cout << "removed: " << lin.removeIndex(1) << std::endl;
    lin.display();

    std::cout << "-- reverse --\n";
    lin.reverse();
    lin.display();

    std::cout << "-- length before clear: " << lin.length() << std::endl;

    std::cout << "-- clearList --\n";
    lin.clearList();
    lin.display();                             // expect "List is empty"
    std::cout << "isEmpty: " << lin.isEmpty() << std::endl; // expect 1
    std::cout << "length: " << lin.length() << std::endl;   // expect 0

    std::cout << "-- removeFirst/removeLast/removeIndex on empty list --\n";
    std::cout << lin.removeFirst() << std::endl;   // expect  error code -1
    std::cout << lin.removeLast() << std::endl;
    std::cout << lin.removeIndex(0) << std::endl;

    return 0;
}