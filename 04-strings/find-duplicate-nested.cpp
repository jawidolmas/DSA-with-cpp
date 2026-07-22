#include<iostream>

//  Finding duplicates in a string



void findDuplicate(char *A){
    int i = 0;
    for(; A[i] != '\0'; i++){
        int count = 0;
        int j;
        for(j = i + 1; A[j] != '\0'; j++){
            if(A[i] == A[j]){
                count++;
            }
        }
        if(count > 0){
        std::cout << A[i] << " Duplicated " << count << " times\n";
        }
    }
}


int main()
{
    char S[12] = "madam"; 
    findDuplicate(S);
    return 0;
}

