#include<iostream>

//  Finding duplicates in a string

// Using Bitwise method

/* Anagram (Hashing / Counting Method):
        In this method, instead of bits, we use a small array H[26] as a "counting table" — one slot
        for each letter of the alphabet ('a' to 'z'). Each slot holds how many times that letter
        appears, instead of just ON/OFF like the bitwise method.

        1. Building the count: We walk through string A once, and for every character we see, we
        increase its slot in H by 1. Since characters are stored as numbers (ASCII), we convert
        a letter to an index using A[i] - 97 (since 'a' is 97). So 'a' goes to H[0], 'b' goes to
        H[1], and so on. After this loop, H holds the full "recipe" of how many of each letter A has.

        2. Consuming the count: We then walk through string B, and for every character we see, we
        decrease its slot in H by 1 instead of increasing. The idea is: if B is truly an anagram
        of A, every letter B uses should already exist in H from A's count, so subtracting should
        never push a slot below 0 — it should just bring matching slots back down toward 0.

        3. Checking for mismatch: If at any point a slot in H goes negative, that means B used a
        letter more times than A had it (or used a letter A never had at all, since H[that letter]
        started at 0 and dropping below 0 is impossible unless it was never incremented). This
        immediately tells us "Not Anagram" — no need to keep checking further.

        4. Checking for leftover: Subtracting is only half the story — B could be shorter than A
        and still never go negative. So after finishing the loop over B, we also check whether A
        was fully "consumed," by comparing lengths (or checking if A[i] also reached '\0' at the
        same point). If A has leftover letters that B never matched, they're not anagrams either.

        This method works because addition/subtraction on a small fixed-size array (26 slots) lets
        us track *counts*, not just presence — which is exactly what the bitwise method (Question 3,
        previous file) couldn't do. Bits can only say "seen" or "not seen," but an int array can say
        "seen, and exactly how many times." So this method solves the count-tracking limitation the
        bitwise approach ran into.
    */

void Anagram(char *A, char *B){
    int H[26] = {0}, i;
    for(i = 0; A[i]!='\0'; i++){
        H[A[i]-97]++;
    }
    for(i = 0; B[i]!='\0'; i++){
        H[B[i]-97]--;
        if(H[B[i]-97] < 0){
            std::cout << "Not Anagram\n";
            return;
        }
    }
    if(A[i] == '\0'){
        std::cout << "Anagram\n";
    }else{
        std::cout << "Not anagram\n";
    }
}


int main()
{
    char S[6] = "jawid"; 
    char B[6] = "diwaj";
    Anagram(S, B);
    return 0;
}


/*  Analysis:
        The time complexity is O(n + m), where n is the length of A and m is the length of B.
        We have two separate loops — one over A, one over B — not nested inside each other, so it's
        two passes, not a multiplied cost. This simplifies to O(n) when A and B are similar in length.

        Space is O(1). We only use a fixed-size array H[26], which never grows no matter how long
        A or B are — it's always exactly 26 integers, since there are only 26 lowercase letters.
        A fixed-size array like this counts as constant space, so O(constant) = O(1).
*/