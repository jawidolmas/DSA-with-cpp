// Adding include guards in header files. 
// Include guards are a strict protective codes that prevents the .h files from being compiled twice.
// If we have a header file array.h and it is included in linkedlist.h and linkedlist.h is included in main.cpp, then array.h is going to be
// read twice, once inside linkedlist.h and once inside main.cpp
// To prevent this, we use #ifndef NAME_HEADER_FILE(array.h) - means if not defined yet, #define array.h, and once it is defined, second time it does not define it again, coz it is already define once. 
// at the end #endif to end the conditional clause.
// In modern c++, we can change all of those three statements with one statement which is #pragma once


#pragma once


struct node{
    int data;
    node *next;
};

class linkedlist{
    private:
        node* head;
    public:
        linkedlist();
        ~linkedlist();
        int  length() const;
        void display() const;
        bool isEmpty() const;
        void clearList();
        void prepend(int value);
        void append(int value);
        void insert(int index, int value);
        int  removeFirst();
        int  removeLast();
        int  removeIndex(int index);
        int  linearSearch(int key) const;
        int  getElement(int index) const;
        void setElement(int index, int value);
        void reverse();
        void insertAfterValue(int value, int addValue);
        void insertBeforeValue(int value, int addValue);
        int  deleteFirstOccurence(int value);
        int  deleteAllOccurence(int value);
        int  recursiveSearch(node *head, int key) const; 
        int  searchRec(int key) const;


};

