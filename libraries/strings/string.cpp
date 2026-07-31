#include<iostream>
#include "string.hpp"


MyString::MyString(const char *s){
    size = 0;
    while(s[size]!= '\0') size++;

    capacity = size;
    data = new char[capacity + 1];

    for(size_t i = 0; i<size; i++){
        data[i] = s[i];
    }
    data[size] = '\0';
}

MyString::MyString(const MyString &other){
    size = other.size;
    capacity = other.capacity;
    data = new char[capacity + 1];
    for(size_t i = 0; i <= size; i++) data[i] = other.data[i];
}

MyString::~MyString(){
        delete []data;
}




//Display
void MyString::display() const{
    for(int i = 0; data[i]!='\0'; i++){
        std::cout << data[i];
    }
    std::cout << std::endl;
}

//length

int MyString::length() const{
    return size;
};

// is Full
bool MyString::isFull() const{
    if(size == capacity){
        return true;
    }
    else return false;
}

// is Empty
bool MyString::isEmpty() const{
    if(size == 0){
        return true;
    }
    else return false;
}



// Uppercase to Lowercase

void MyString::ToLowerCase(){

    for(int i = 0; data[i]!='\0'; i++){
        if(data[i] >= 'A' && data[i] <= 'Z'){
            data[i] = data[i] + 32;
        }
        std::cout << data[i];
    }
}

//Lowercase to Uppercase

void MyString::ToUpperCase(){
    for(int i = 0; data[i]!='\0'; i++){
        if(data[i] >= 'a' && data[i] <= 'z'){
            data[i] = data[i] -32;
        }
        std::cout << data[i];
    }
}

//Toggle case

void MyString::ToggleCase(){
    for(int i = 0; data[i]!='\0'; i++){
        if(data[i] >= 'A' && data[i] <= 'Z'){
            data[i] = data[i] +32;
        }else if(data[i] >= 'a' && data[i] <= 'z'){
            data[i] = data[i] - 32;
        }
        std::cout << data[i];
    }
}


// Check if string is alphabetic
bool MyString::isAlphabetic() const{
    for(int i = 0; data[i]!='\0'; i++){
        if(!((data[i] >= 'A' && data[i] <= 'Z') || (data[i] >= 'a' && data[i] <='z'))){
            return false;
        }
    }
    return true;
}

// Check if at least on character exist in a string
bool MyString::hasAtleastOneChar() const{
    for(int i = 0; data[i]!='\0'; i++){
        if((data[i] >= 'A' && data[i] <= 'Z') || (data[i] >= 'a' && data[i] <='z')){
            return true;
        }
    }
    return false;
}


// Check whether every character is a digit
bool MyString::isNumeric() const{
    for(int i = 0; data[i]!='\0'; ++i){
        if(!(data[i] >= '0' && data[i] <= '9')){
            return false;
        }
    }
    return true;
}

// check if at least one number exist
bool MyString::hasLeastOneNum() const{
    for(int i = 0; data[i]!='\0'; ++i){
        if((data[i] >= '0' && data[i] <= '9')){
            return true;
        }
    }
    return false;
}


// Checks if given string is valid identifier
bool MyString::isValidIdentifier() const{
    if (size == 0) return false;

    if (!( (data[0] >= 'A' && data[0] <= 'Z') ||
           (data[0] >= 'a' && data[0] <= 'z') ||
           data[0] == '_' )) {
        return false;
    }
    for(int i = 1; data[i]!='\0'; i++){
        if (!( (data[i] >= 'A' && data[i] <= 'Z') ||
               (data[i] >= 'a' && data[i] <= 'z') ||
               (data[i] >= '0' && data[i] <= '9') ||
               data[i] == '_' )){
                return false;
               }
    }
    return true;
}

// Compare two strings
 void MyString::compareStrings(MyString S1, MyString S2) const{
        int i, j;
        for(i = 0, j = 0; S1.data[i]!='\0' && S2.data[j]!='\0'; i++, j++){
            if(S1.data[i] != S2.data[j]){
                std::cout << "Strings are not equal\n";
                break;
            }
        }
        if(S1.data[i] > S2.data[j]){
            std::cout << "First string is Bigger\n";
        }
        else if(S1.data[i] < S2.data[j]){
            std::cout << "Second string is bigger\n";
        }
        else{
            std::cout << "Both strings are equal\n";
        }
 }


 // Equality check
 bool MyString::equalityCheck(MyString &S1, MyString &S2) const{
        int i, j;
        for(i = 0, j = 0; S1.data[i]!='\0' || S2.data[j]!='\0'; i++, j++){
            if(S1.data[i] != S2.data[j]){
                return false;
            }
        }
        return true;
}  

// Linear Search
void MyString::linearSearchChar(char A) const{
    bool found = false;
    int i;
    for(i = 0; data[i]!='\0'; i++){
        if(A == data[i]){
            found = true;
            std::cout << A << " Found at index " << i << " \n";
            break;
        }
    }
    if(!found){
        std::cout << "Not Found\n";
        return;
    }
}

// Count Vowels
void MyString::countVowels() const{
    int i, vowels = 0;
    for(i = 0; data[i]!='\0'; i++){
        if(data[i] == 'a' || data[i] == 'e' || data[i] == 'i' || data[i] == 'o' || data[i] == 'u' || 
           data[i] == 'A' || data[i] == 'E' || data[i] == 'I' || data[i] == 'O' ||data[i] == 'U'){
            vowels++;
           }
    }
    std::cout << "Vowels: " << vowels << "\n";
}

// Count Constants
void MyString::countConstants() const{
    int i, constants = 0;
    for(i = 0; data[i]!='\0'; i++){
        if(data[i] != 'a' && data[i] != 'e' && data[i] != 'i' && data[i] != 'o' && data[i] != 'u' && 
           data[i] != 'A' && data[i] != 'E' && data[i] != 'I' && data[i] != 'O' &&data[i] != 'U'){
            constants++;
           }
    }
    std::cout << "Constants: " << constants << "\n";
}

// Count words
void MyString::countWords() const{
    int i, words=0;
    for(i = 0; data[i]!='\0'; i++){
        if(data[i] == ' '){
            words++;
        }
    }
    std::cout << "Words: "<< words+1 << "\n";       //+1 coz of first word
}