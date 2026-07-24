#include<iostream>

//  MATRIX:


        /*
            In this chapter, we will see Special Matrices, the matrices that are square matrix, nxn. 
            These matrices contains a lot of zero. As zero in an array means empty, we wont store them in memory, we will only store real values and will not do anything
            to indices that are zero. This gives us a good advantages in terms of space and computation time.
            
            2. Lower Traingle Matrix: A matrix that has all zero above the daigonal. 
                There are somthings we need to know:
                -let i be Row and j be Column indices. In a LowTr matrix, the i value can be bigger or equal to j, any j index that is bigger than i is zero. 
                -The total number of values other than zero in lower tra is n*(n+1)/2.
                -We have two formulas and methods to access an index in Lower tr. 1. Row Major Formula 2. Coulmn Major Formula

                1. Row Major Formula:   Index([i][j]) = i*(i-1)/2 + j-1;
                2. Column Major Formula:  Index([i][j]) = n*(j-1) - ((j-1)(j-2))/2

                We will use these two method to access any index and perform operations.
        
        */

class matrix{
    private:
        int *A;
        int n;      //Dimension of matrix;

    public:
        matrix(int n);
        void set( int i, int j, int x);
        int get( int i, int j) const;
        void display() const;

};

matrix::matrix(int dim){
    n = dim;
    A = new int[(n * (n+1))/2]();
}

// Using Row Major Formula


void matrix::set(int i, int j, int x){
    if(i >= j){
        A[i*(i-1)/2 + (j-1)] = x;               //RMF
    }
}

int matrix::get(int i, int j) const{
    if(i >= j){
        return A[i*(i-1)/2 + (j-1)];        //RMF
    }
    else{           // When matrix is empty, all zero.
        return 0;       
    }
}


void matrix::display() const{
    int i, j;
    for(i = 1; i<=n; i++){           // We need to print until i is equal or greater than j
        for(j=1; j<=n; j++){
            if(i >= j){             
                std::cout << A[i*(i-1)/2 + (j-1)] <<" ";        // RMF
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
    arr.set(1,1,5);
    arr.set(2,1,7);
    arr.set(2,2,7);
    arr.set(3,1,5);
    arr.set(3,2,9);
    arr.set(3,3,9);
    arr.set(4,1,1);
    arr.set(4,2,3);
    arr.set(4,3,6);
    arr.set(4,4,6);
    std::cout << arr.get(2, 2) << std::endl;   // O/P: 4
    arr.display();
    return 0;
}


/*Output:

        5 0 0 0 
        7 7 0 0 
        5 9 9 0 
        1 3 6 6  

    In fact, we did not stored those 0s, we only have a linear array that stores non-zero values. 
*/