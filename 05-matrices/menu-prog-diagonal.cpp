#include<iostream>
using namespace std;

//  MATRIX:

// Menu Driven Program for all operations. 

// Diagonal


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
    A = new int[dim]();
}



// Set
void matrix::set(int i, int j, int x){
    if(i == j){
        A[i-1] = x;             
    }
}


// Get
int matrix::get(int i, int j) const{
    if(i == j){
        return A[i-1];        
    }
    else{         
        return 0;       
    }
}

// Display
void matrix::display() const{
    int i, j;
    for(i = 1; i<=n; i++){           
        for(j=1; j<=n; j++){
            if(i == j){             
                std::cout << A[i-1] <<" ";        
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
    // For Diagonal
    
    int choice, size = 0, row, col, value;
    cout << "Enter the size of dimension: ";
    cin>>size;  
    matrix arr(size);

    do{
    cout << "1. Set\n";
    cout << "2. Get\n";
    cout << "3. Display\n";
    cout << "Enter your choice: ";
    cin >> choice;

    switch(choice){
        case 1: {
            cout << "Setting elements(Add 3 info: ROW, COL, VALUE)\n";
            for(int i = 0; i<size; i++){
                cout << "ROW:   ";
                cin >> row;
                cout << "COL:   ";
                cin>>col;
                cout << "Value:";
                cin>>value;
                arr.set(row, col, value);
            }
            break;
        }
        case 2: {
            cout << "Getting element(Add 2 info: Row, Col)\n";
            cout << "ROW:  ";
            cin >> row;
            cout << "COL:  ";
            cin>>col;
            cout << arr.get(row, col) << endl;
            break;
        }
        case 3: {
            arr.display();
            break;
        }
        default: {
            cout << "Invalid choice\n";
            break;
        }
    
    }
                }while(choice != 4);


    return 0;
}


