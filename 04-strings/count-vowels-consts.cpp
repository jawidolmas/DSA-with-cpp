#include<iostream>

// Counting Vowels and Constatns


        /*
            Let's think, that, what vowel and constants are, a i o u e are vowels and the rest is constants, isn't it? 
            We must be able to handle this with only one check. A loop that travers each element, then if each visited element is vowel, the increment vowel, 
            else, increment constant. THAT'S IT. 
        
        */


// Count vowels and constants:

void CountVowels(std::string &S){
    int i, vowel = 0, constant = 0;
    for(i = 0; S[i]!='\0'; i++){
        if(S[i] == 'A' || S[i] == 'U' || S[i] == 'I' ||S[i] == 'O' ||S[i] == 'E' 
        || S[i] == 'a' || S[i] == 'u' || S[i] == 'i' || S[i] == 'o' || S[i] == 'e'){
            vowel++;
        }else{
            constant++;
        }
    }   
    std::cout << "Vowels: " << vowel << std::endl;
    std::cout << "Constants: " << constant << std::endl;
}




int main()
{
    std::string name = "JAWID";
    CountVowels(name);
}

/*  Output:
        Vowels: 2
        Constants: 3

*/

/*  Analysis:
        The time complexity is O(n) and Space is O(1). We have a loop that traverses and then we have a condition check, at the end, an increment on each 
        iteration. So this is an absloute O(n). 
        We only have vowel, constant and i varibales, which at most takes 12 bytes. O(constant) = O(1).
*/