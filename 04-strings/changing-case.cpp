#include<iostream>

// Changing Cases


        /*
            -Uppercase to lower case: The logic is simple. We all know that machines only understand bits, so they dont recognize A as A, but A as 65.
            B as 66, C as 67... and a as 97, b 98 and .... can you see the pattern? if I add 32 to 65, it gets 97, and 32 to 66 it gets 98. That means, 
            if I have a loop, and traverse each index, and on each index, if I inject 32, then I simple get UPPERCASE to lower case, CRYSTAL?
            -The same logic works in lowercase to UPPERCASE. We will just subtract 32 from chars, and we will get lowercase. 
        
        */


// Uppercase to lowercase:
// Input needs to be all UPPERCASE
void UpperToLower(std::string &S){
    int i;
    for(i = 0; S[i]!='\0'; i++){
        S[i] = 32 + S[i];
    }
    std::cout << S << std::endl;
}



// lowercase to Uppercase:
// Input needs to be all lowercase
void LowerToUpper(std::string &S){
    int i;
    for( i = 0; S[i]!='\0'; i++){
        S[i] = S[i] - 32;
    }
    std::cout << S << std::endl;
}

// Tangle case: 
// Input can be anything
// This function will change upper to lower, lower to upper and if not a character in range of A to Z, a to z, then it wont touch it at all. 
void TanglingCase(std::string &S){
    int i;
    for(i = 0; S[i]!='\0'; ++i){
        if(S[i] >= 65 && S[i] <= 90){           // We either can check with ascii code
            S[i] += 32;
        }
        else if(S[i]>= 'a' && S[i] <= 'z'){     // Or direct letter range itself
            S[i] -= 32;
        }
    }
    std::cout << S << std::endl;
}

int main()
{
    std::string name = "JAWID";
    std::string name2 = "jawid";
    std::string name3 = "JaWiDOLmaS20";
    UpperToLower(name);
    LowerToUpper(name2);
    TanglingCase(name3);
}

/*  Output:
    jawid
    JAWID
    jAwIdolMAs20

*/

/*  Analysis:
        -We can see 3 functions, and all of them are O(n) in terms of time and O(1) in terms of space. Reason: on all of them, we travers the character array element
        by element, and do one operation in 2 first funtions, and in second, we do at least one and at most two condition checks and then the operation.
        -If we look carefully, we only assing the i as an integer in algorithm, so we take only 4 byte in memory, which is constant. 

*/