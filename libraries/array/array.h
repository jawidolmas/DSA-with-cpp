class Array{
    private: 
        int *A;
        int capacity;   // Number of slots or indices in array
        int size;       // number of real values in each index.
        void swap(int &a, int &b);

    public:
        Array(int cap);
        ~Array();
        void append(int n);
        void insert(int index, int n);
        void Delete(int index);
        void display() const;
        int  length() const;
        bool isEmpty() const;
        bool isFull() const;
        int  Max() const;
        int  Min() const; 
        int  sum() const;
        double average() const;
        void linearsearch(int n) const;
        int get(int index) const;
        void set(int index, int value);    
        void transpositionLinearSe(int value);
        void movetoFrontLinearSe(int value);
};