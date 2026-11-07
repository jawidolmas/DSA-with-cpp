// Adding include guards in header files. 
// Include guards are a strict protective codes that prevents the .h files from being compiled twice.
// If we have a header file array.h and it is included in linkedlist.h and linkedlist.h is included in main.cpp, then array.h is going to be
// read twice, once inside linkedlist.h and once inside main.cpp
// To prevent this, we use #ifndef NAME_HEADER_FILE(array.h) - means if not defined yet, #define array.h, and once it is defined, second time it does not define it again, coz it is already define once. 
// at the end #endif to end the conditional clause.
// In modern c++, we can change all of those three statements with one statement which is #pragma once
// modified on 2026-11-07 21:33

#ifndef OLMAS_STRING_HPP
#define OLMAS_STRING_HPP

class MyString{
    private:
        char *data;
        size_t size;
        size_t capacity;
    public:
        MyString(const char *s = "");
        MyString(const MyString &other);
        ~MyString();
        void display() const;
        int length() const;
        bool isFull() const;
        bool isEmpty() const;
        void clear();
        void ToLowerCase();
        void ToUpperCase();
        void ToggleCase();
        bool isAlphabetic() const;
        bool hasAtleastOneChar() const;
        bool isNumeric() const;
        bool isAlphanumeric() const;
        bool hasLeastOneNum() const;
        bool isValidIdentifier() const;
        void compareStrings(MyString S1, MyString S2) const;
        bool equalityCheck(MyString &S1, MyString &S2) const;
        void linearSearchChar(char A) const;
        void countVowels() const;
        void countConstants() const;
        void countWords() const;
        void duplicateCharDetect() const;
};

#endif