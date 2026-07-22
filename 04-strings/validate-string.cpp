#include<iostream>

// Validating a string


        /*
            As we can in real world, there are some checks that prevent users from doing an undefined behavior. For example, instagram username, OS naming files, 
            passwords, emails. They all validate what the users type, email must be end with @DNS.com, or instagram username should only contain chars and numbers with comma.
            How it happens? This is very simple, we travers each element, and check if it is in the range of safe zone or not. And return validness or invalidness.
            Let's see/
        
        */


// Validate a string
// We will check if a string contains only chars and numbers
int ValidString(std::string &S){
    int i;
    for(i = 0; S[i] != '\0'; i++){
        if(!(S[i] >= 48 && S[i] <= 57) && !(S[i] >= 65 && S[i] <= 90) && !(S[i] >= 97 && S[i] <= 122)){
                return 0;
        }
    }
    return 1;
}


int main()
{
    std::string name = "jawid20##";
    if(ValidString(name)){   std::cout << "Valid String\n";}
    else{                    std::cout << "Invalid String\n";}

    return 0;
}

//  O/P: Invlaid string

/*  Analysis:
       This function also is O(n) in terms of time and const in terms of space. HOW? we traverse each index and we have a condition that we discussed. 
       if conditions true, do a work, if not dont do anything. at the end return. that's it. 
       -To conclude, it is O(n) in time, and O(1) in space.
*/