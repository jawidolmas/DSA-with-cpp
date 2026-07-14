class Array{
    private: 
        int *A;
        int capacity;   // Number of slots or indices in array
        int size;       // number of real values in each index.

    public:
        Array(int cap);
        ~Array();
        void append(int n);
        void insert(int index, int n);
        void Delete(int index);
        void display() const;
    
};