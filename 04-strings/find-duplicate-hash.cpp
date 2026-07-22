#include<iostream>

//  Finding duplicates in a string

// Using hash table

    /* Hash table:
        We get a new array size 26, as we are working on characters, all 26 chars can be stored in that array. 
        What is the procedure? We use the same thing as we did in array, the space complx. will grow but time will reduce. 
        we use the numbers or ascii codes to manipulate and determine the duplicatness
    */

void HashFindDuplicate(char *A){
    int Hash[26] = {0};
    for(int i = 0; A[i]!= '\0'; i++){       
        (Hash[A[i]- 97]) += 1;
    }
    for(int i = 0; i<26; i++){      // Print hash table.
        if(Hash[i] > 1){
            std::cout << char(i+97) << " Duplicated " << Hash[i] << " times\n";
        }
    }
}


int main()
{
    char S[12] = "madam"; 
    HashFindDuplicate(S);
    return 0;
}

