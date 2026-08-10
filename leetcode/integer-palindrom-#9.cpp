class Solution {
public:

    // Reverse the integer first;
    int reverse(int x) {
        int rev = 0; 
        while(x != 0){
            int digit = x % 10;
            if(rev > INT_MAX/10 || (rev == INT_MAX/10 && digit > 7)){
                return 0;
            }
            if(rev < INT_MIN/10 || (rev == INT_MIN/10 && digit < -8)){
                return 0;
            }
            rev = rev * 10 + digit;
            x = x / 10;
        }
        return rev;
    }

    bool isPalindrome(int x) {
        if(x < 0){
            return false;
        }
        if(x != 0 && x % 10 == 0){
            return false;
        }
        int palindrom = reverse(x);
        if(palindrom == x){
            return true;
        }
        return false;
    }
};

// Leetcode Array #9    : Palindrome of and integer
 
// The pattern
    /*
        First Reverse:
        While loop
            digit = x % 10
            x =  x / 10;
            rev = rev * 10 + digit;

        Then simple checks:     
            if x != 0  && x % 10 == 0 return false
            if reversed x = x then true; else false;

    */