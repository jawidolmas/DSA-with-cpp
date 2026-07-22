#include<iostream>

//  Permutation of a string

/*  Permutation & Permutation2:
        Permutation (Position-Fill / Used-Array-Recursion Method): This method builds the result character
        by character. A[10] marks which characters of S have already been "used" in the current
        arrangement (1 = used, 0 = free). Res[10] holds the arrangement being built so far. At each
        call, we try every character in S that isn't marked used yet, place it at position k in Res,
        mark it used, and recurse to fill position k+1. After the recursive call returns, we unmark
        it (A[i] = 0) so it can be reused in a different arrangement (backtracking). Base case: when
        S[k] == '\0', Res has been filled for all positions, so we terminate it and print it.

        Permutation2 (Swap Method): This method builds permutations directly inside S itself, using
        swaps instead of a separate Res array. At each level, position l is fixed by swapping in each
        remaining character (from l to h) one at a time, then recursing on the rest (l+1 to h). After
        each recursive branch, the swap is undone, restoring S for the next choice (backtracking,
        without needing a "used" array). Base case: when l == h, only one character remains, so S is
        already a complete arrangement and gets printed.
*/




// Permutation: Recursion Method
void Permetuation(char *S, int k){
    static int A[10] = {0};
    static char Res[10];
    if(S[k] == '\0'){
        Res[k] = '\0';
        std::cout << Res << std::endl;
    }
    else{
        for(int i = 0; S[i]!='\0'; i++){
            if(A[i] == 0){
                Res[k] = S[i];
                A[i] = 1;
                Permetuation(S, k+1);
                A[i] = 0;   
            }
        }
    }
}


// swap
void swap(char &a, char &b){
    char temp = a;
    a = b; 
    b = temp;
}

// Permutation: Second method: Swap method

void Permutation2(char *S, int l, int h){
    int i;
    if(l == h){
        std::cout << S << std::endl;
    }
    else{
        for(i = l; i<=h; i++){
        swap(S[l], S[i]);
        Permutation2(S, l+1, h);
        swap(S[l], S[i]);
        }
    }

}


int main()
{
    char S[] = "ABC"; 
    int len = 3;
    Permutation2(S, 0, len-1);
    return 0;
}


/*  Analysis:
        Both methods have time complexity O(n!), since there are n! permutations of n distinct
        characters, and each one is fully built and printed, with O(n) work per arrangement — so
        total time is O(n! * n).

        Space differs slightly: Permutation uses O(n) extra space for A[] and Res[], plus O(n)
        recursion depth. Permutation2 needs no extra array, reversing and restoring S in place, so
        its only overhead is O(n) recursion depth — making it slightly more space-efficient.
*/