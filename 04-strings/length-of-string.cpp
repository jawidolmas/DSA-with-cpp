#include<iostream>


int main()
{
    std::string name = "Jawid";
    int i;
    for( i = 0; name[i]!='\0'; i++){
    }
    std::cout << i;
}



/*  Analysis:
        This code is O(n). reason: This code traveses each index one by one and when it reached at the end of string which is '\0', it stops. 
        The space complx. is O(1), as we only use i for travers.

        Note: The space and time complexity does not depend on input. such that, name Jawid takes 6 bytes in memory, but we wont count it in complexity, 
        because complexity is measured how much the alogrithms grows in terms of space and time, according to the input. In here, if not Jawid, but a million character
        instead, it again will be O(1). 

*/