#include<iostream>

// Reversing string


        /*
            ***Important: IN C++, STRINGS ARE MUTABLE, MEANS THEY CANNOT BE MODIFIED. IF WE HAVE A STD::STRING POINTER POINTING TO AN ADDRESS, WE CANNOT CHANGE IT. 
            SO, FOR REVERSING, WE NEED TO USE CHARACTER ARRAY IN ORDER BE ABLE TO MODIFY THE CHARACTER. without using auxilary array. 


            We can solve this problem in more than one method. 
            1. We can create an auxilary array and fill that array in reverse order, so we reversed the string. 
            2. We can swap the elements from last to first. So, last element goes to first, first comes to last, and so on...

            Let's see
        
        */

// Auxilary Array method
void Method1(char *A, int size){
    char B[size];       // std::vector<char> B(size); this will be better, but I NEED TO BE SURE WITH THAT. 
    // Let's bring the i to the end of main array.
    int i, j = 0;
    for(i = 0; A[i]!='\0'; i++){}
    i = i-1; // i = \0 and i-1 brings it to last character.
    for(;  i >= 0; i--, ++j){
        B[j] = A[i];
    }
    B[j] = '\0'; // Last element should be null character as its a string.
    std::cout << B << std::endl;
}


// Second Method. Direct reverse.
void Method2(char *A, int size){

    int i, j = 0;
    for(i = 0; A[i]!='\0'; i++){}
    i = i-1;
    for(; i>j; i--, j++){
        //swap
        char temp = A[j];
        A[j] = A[i];
        A[i] = temp;
    }
    std::cout << A <<  std::endl;
}



int main()
{
    char S[12] = "Jawid";
    Method2(S, sizeof(S));  
    return 0;
}

//  O/P: diwaJ

/*  Analysis:
        Method1: This function is O(n) in both time and space. we have a loop and it traces all elements once, so time is O(n), and we get a new helper array
        which gets a space depends on size of main array, so space is also O(n).

        Method2: This function is also O(n), in terms on time only. However, method 2 is more space-efficient which is O(1). Becuase we don't get any space that depends
        on size of maina array, we only have two int variables, which takes 8 bytes at most. 
*/



// std::vector<char> B(size); this will be better, but I NEED TO BE SURE WITH THAT. Waiting a trusted response. 