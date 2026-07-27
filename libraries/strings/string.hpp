class MyString{
    private:
        char *data;
        size_t size;
        size_t capacity;
    public:
        MyString(const char *s);
        ~MyString();
        void display() const;
        int length() const;
        bool isFull() const;
        bool isEmpty() const;
        void clear();
        void ToLowerCase();
        void ToUpperCase();
        void ToggleCase();
        void checkAlphabetic() const;
        void checkNumeric() const;
        void checkAlphanumeric() const;
        void validateStringFormat();
        void compareStrings(MyString S1, MyString S2) const;
        void equalityCheck(MyString S1, MyString S2) const;
        void linearSearchChar(char A) const;
        void countVowels() const;
        void countConstants() const;
        void countWords() const;
        void duplicateCharDetect() const;
};


