#include<iostream>

//  MATRIX:


        /*
            In this chapter, we will see Special Matrices, the matrices that are square matrix, nxn. 
            These matrices contains a lot of zero. As zero in an array means empty, we wont store them in memory, we will only store real values and will not do anything
            to indices that are zero. This gives us a good advantages in terms of space and computation time.
            
            1. Diagonal Matrix: A matrix that has values other than zero only in daigonals, all other are zero. 
                *How we store this matrix in memory?
                    -Actually, as we discussed, if we have a 4x4 diagonal matrix, we dont store all of them, we only store the values we care. 
                    if we have a matrix M, and if M[i, j] = 0. then this can never be diagonal, coz j!=i. if M[i, j], If j == i, THEN THIS IS DIAGONAL. 
                    in that case, we only store j and i, all other already are zero. THAT'S IT. 

        
        */

class matrix{
    private:
        int A[10];  // We could allocate memory as well, I just used fixed array in here. 
        int n;      //Dimension of matrix;

    public:
        matrix(int n);
        void set( int i, int j, int x);
        int get( int i, int j) const;
        void display() const;

};

matrix::matrix(int dim){
    n = dim;
}

void matrix::set(int i, int j, int x){
    if(i == j){
        A[i-1] = x;         // We could make A[j-1] as well, as i == j. The reason for i-1 is matrices starts with 1 ROW, COL. and array starts with 0 indexing in C/C++.
    }
}

int matrix::get(int i, int j) const{
    if(i == j){
        return A[i-1];
    }
    else{           // When matrix is empty, all zero.
        return 0;       
    }
}


void matrix::display() const{
    int i, j;
    for(i = 0; i<n; i++){
        for(j=0; j<n; j++){
            if(i == j){             // if a diagonal matrix
                std::cout << A[i] <<" ";
            }
            else{
                std::cout << "0 ";
            }
        }
        std::cout << "\n";
    }

}

int main()
{
    matrix arr(4);
    arr.set(1, 1, 2); arr.set(2, 2, 4); arr.set(3, 3, 6); arr.set(4, 4, 8);
    std::cout << arr.get(2, 2) << std::endl;   // O/P: 4
    arr.display();
    return 0;
}


/*Output:

    2 0 0 0 
    0 4 0 0 
    0 0 6 0 
    0 0 0 8 

    In fact, we did not stored those 0s, we only have a linear array that stores 2, 4, 6, 8. 
*/