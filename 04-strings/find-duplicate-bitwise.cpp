#include<iostream>

//  Finding duplicates in a string

// Using Bitwise method

    /* Bitwise:
        In this method, we use bits, in the core of a computer, and we do operations as shifting, masking, and meging. 

        1. Shifting: 1 byte is 8 bits, and bits are all 2s powers. so if we have a bit like 00000001, then it is 1, like x = 1; as we know about most and least significant
        bits, most = rightthand, least= lefthand bit. shifting means we will shift MSB by n bits. syntax C: x = x<<2, means shift x by 2 bits and now x is 4. 

        2.ANDing(masking): This operation is used to check if any bit in a byte is ON(1) or OFF(0). we perform AND opeartion in two bytes to find out which bits are ON or OFF.
        1-0 = 0, 0-1 = 0, 0-0 = 0, 1-1 = 1; So performing AND will give us 0 if any bit is already OFF, and will give 1 for any bit that was already ON. 

        3. ORing(merging): This operation is used to set a bit ON or OFF. if a bit is ON, ORing makes it OFF, if OFF, makes it ON. if we have two int, x and y
        x | y = perfomrs or operation, 1-0 = 1, 0-1 =1, 1-1 = 1, 0-0=0; So, this operation can modify any bit using CPU's ALU. arithmetic logic unit

        These operations used to find if any character is duplicated in a string. However, I don't know yet, that if we can find out how many times a character duplicated. 
        For a high possibility, I don't think we can find it out. coz bits are only 1 and 0. 
    */

void Bitwise(char *A){
    int H = 0, x = 0;
    for(int i = 0; A[i]!='\0'; i++){
        x = 1;
        x = x<<(A[i]-97);       // Shift x by A[i] - 97 bits
        if((x & H) > 0){
            std::cout << A[i] << " duplicated\n";
        }
        else{
            H = x | H;
        }
    }
}


int main()
{
    char S[12] = "madam"; 
    Bitwise(S);
    return 0;
}


/*  Analysis:
        The time complexity is O(n). We have a single loop that traverses the string once,
        and inside it we only do a constant number of operations: one shift, one AND check,
        one OR update. No nested loops, so it's an absolute O(n).
        
        Space is O(1). We only have H, x, and i variables, which at most takes 12 bytes.
        No extra array or buffer is created regardless of how long the string is.
        O(constant) = O(1).
*/