#include<iostream>
#include "string.hpp"
using namespace std;


int main()
{
    MyString s1("__init__");
    MyString s2("Jawid");
    s1.display();
    std::cout << s1.length() << endl;
    s1.ToggleCase();
    cout << endl;
    cout << s1.isAlphabetic();
    cout << s1.isNumeric();
    cout << s1.hasAtleastOneChar();
    cout << s1.hasLeastOneNum();
    cout << endl;
    cout << s1.isValidIdentifier() << endl;
    s1.compareStrings(s1, s2);
    


    return 0;
}