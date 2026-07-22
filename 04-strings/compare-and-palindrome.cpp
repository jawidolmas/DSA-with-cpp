#include<iostream>

//  Compare two strings and palindrome


        /*
            -To compare two strings, we simply check character by character, if characters are equal, then strings are equal, if A has some where e and B has f instead, 
            then A is smaller than B, as e's code is smaller the f's code, and vice versa, if B is e and A is f, then B is smaller. 

            -PALINDROME: any string or data, that is stays same if you reverse it. 121 -> reverse -> 121, madam -> reverse -> madam. same. PALINDROME.
            -For palindrome, we use REVERCSE and COMPARE. If we join these two algorithms, then we will have an algorithm to check if string is palindrome or not.

            let's code. 
        */


// REVERSE
void reverse(char *A, char *B, int size){     
    int i, j = 0;
    for(i = 0; A[i]!='\0'; i++){}
    i = i-1; 
    for(;  i >= 0; i--, ++j){
        B[j] = A[i];
    }
    B[j] = '\0'; 
    std::cout << B << std::endl;
}

//Compare two strings

void Compare(char *A, char *B){
    int i,  j;
    for(i = 0, j = 0; A[i]!='\0' && B[j]!='\0';  i++, j++){
        if(A[i] != B[j]){
            std::cout << "Strings are not equal\n";
            break;
        }
    }
        if(A[i] > B[j]){
            std::cout << "First String is SMALLER\n";
        }else if(A[i] < B[j]){
            std::cout << "First String is BIGGER\n";
        }else{
            std::cout << "Both Strings are equal\n";
        }
    
}



// Palindrome: Combination of Reverse and Compare. 1. Reverse 2. Compare. 
void Palindrome(char *A, int size){
    int i;
    char B[size];
    reverse(A, B, size);
    for(i = 0; A[i]!='\0' && B[i]!='\0'; i++){
        if(A[i] != B[i]){
            std::cout << "Not palindrom\n";
            break;   // mismatch found
        }
    }
    if(A[i] == '\0' && B[i] == '\0'){
        std::cout << "Palindrome\n";   // both ended at the same length, all chars matched
    }
}


int main()
{
    char S[12] = "madam"; 
    char F[12] = "Jawed";
    Compare(S, F);
    Palindrome(S, 12);
    return 0;
}

/*
    Output:

        Compare(S, F);
        Strings are not equal
        First String is SMALLER
        
        Palindrom(S, 12);
        madam
        Palindrome

*/

/*  Analysis:
        Compare function takes O(n) time and O(1) space. 
        Palindrome takes O(n) time by itself. The space taken by palindrom is O(1). independent of reverse function.
*/
