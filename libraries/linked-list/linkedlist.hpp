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


};

