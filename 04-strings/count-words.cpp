#include<iostream>

// Counting Words of a paragraph


        /*
            As we know, a space creates words. So, with the help of space, we can count the number of words. If the visited i is a space, then increment word. 
            But here is a problem, as the word icrements when i see a space, then what if there is a white space(more than one space continously)?
            such as: Hey How are   you. see, here is 3 spaces between are and you. if we blidnly increment and print the word, we will get a wrong answer. 
            What we can do? We simply add a check, if you are a space, and your previous index was also a space, then dont increment word, otherwise increment.
            SIMPLE, ISNT IT?
        
        */


// Count words

void CountWords(std::string &S){
    int i, words = 1;       // We initialized words to 1, because number of words are one more of number of space. LOGICALLY, words are number of space. 
    for(i = 0; S[i]!='\0'; i++){
        if(S[i] == 32 && S[i-1] != 32){     //32 is the ASCII code for space. we could use S[i] == ' ' && S[i-1] != ' ' as well.
            words++;
        }   
    }
    std::cout << "Words: " << words << std::endl;
}


int main()
{
    std::string name = "Hey, How are you      man";
    CountWords(name);

    return 0;
}

// O/P: Words: 5

/*  Analysis:
       This function also is O(n) in terms of time and const in terms of space. HOW? we traverse each index and we have a condition that we discussed. 
       if conditions true, do a work, if not dont do anything. at the end print. that's it. 
       -To conclude, it is O(n) in time, and O(1) in space.
*/