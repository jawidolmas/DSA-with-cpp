#include<iostream>
#include "string.hpp"
using namespace std;


int main()
{
    MyString s1("aaAAiiEEookakaka olmas jawid olmas");
    MyString s2("catdogsdfsdfsdfsdfsfgsrthyutejeyudukyudkhkuydk");
    s1.display();
    cout << endl;
    cout << s2.equalityCheck(s1, s2) << endl;
    s1.linearSearchChar('j');
    s1.countVowels();
    s1.countConstants();
    s1.countWords();
    


    return 0;
}