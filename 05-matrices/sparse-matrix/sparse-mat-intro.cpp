#include<iostream>
using namespace std;        // Only use it on daily small tasks.


        /*
            SPARSE MATRIX:
                -A sparse matrix is a matrix that contains a lot of zero elements. 
                -A sparse matrix can be mxn and we can do all matrix operations on them. 
                -If we look carefully, when a matrix exist that is full of zero elements, then that means we need to be careful when storing them. 
                Becuase storing zero elements will be a waste in time and space. for example, what 0 + 0 is? its again 0. Does it worth to do an opeartion which is 
                waste of computation time and two inte + one result int, 3 integer waste. 
                -Instead, we have methods to store these kind of arrays in sufficient ways. 

                1. Coordinate List/3-Column Representation: In this method, we take an array that store 3 info, column info, row info and non-zero info. 
                   We store them coordinate by coordinate. like in row 3 and col 5 we have element of 10. 

                2. Row Sparse Representaion: In this method, we store the infos using how many elements on each row exist, then add them in a cummulative way. We also store 
                   number of colunms that non-zero elements exist, in the same we, we store the non-zero elements itself. 


                For coding, we will use 2 structures, for saving infos.
                Let's Code:
        
        
        
        */


struct element{

    int i;             //Number of rows
    int j;            // Number of cols
    int x;           //  Non-zero elements
};

struct sparse{
    int m;          //Dimension Row
    int n;         // Dimension Col
    int num;      //  Non-zero elements
    element *e;   //  pointer for taking an array of element shape in heap
};

// Create
void create(sparse *s){
    cout << "Add dimensions\n";
    cout << "Add Number of Rows: ";
    cin >> s->m; 
    cout << "Add Number of Cols: ";
    cin >> s->n; 
    cout << "Add Number of non-zerp elements: ";
    cin >> s->num;
    s->e = new element[s->num];
    cout << "Add Non-zero elements\n";
    for(int i = 0; i<s->num; i++){
        cout << "ROW: ";
        cin >> s->e[i].i;
        cout << "Col: ";
        cin >> s->e[i].j;
        cout << "Non-Zero Element: ";
        cin >> s->e[i].x;
    }
}

// Display

void display(sparse s){
    int i, j, k = 0;
    for(i = 0; i<s.m; i++){
        for(j = 0; j<s.n; j++){
            if(i == s.e[k].i && j == s.e[k].j){
                cout << s.e[k++].x << " ";
            }
            else{
                cout << "0 ";
            }
        }
        cout << endl;
    }
}


// Addition
sparse *addition(sparse *s1, sparse *s2){
    sparse *sum;
    int i , j, k;
    i = j = k = 0;
    sum = new sparse;
    sum->e = new element[s1->num + s2->num];
    while(i<s1->num && j<s2->num){
        if(s1->e[i].i < s2->e[j].i ){
            sum->e[k++] = s1->e[i++];
        }
        else if(s1->e[i].i > s2->e[j].i){
            sum->e[k++] = s2->e[j++];
        }
        else{
            if(s1->e[i].j < s2->e[j].j){
                sum->e[k++] = s1->e[i++];
            }
            else if(s1->e[i].j > s2->e[j].j){
                sum->e[k++] = s2->e[j++];
            }
            else {
                sum->e[k] = s1->e[i];
                sum->e[k].x = s1->e[i].x + s2->e[j].x;
                i++;
                j++;
                k++;
            }
        }
    }
    for(; i<s1->num; i++){
        sum->e[k++] = s1->e[i];
    }
    
    for(; j<s2->num; j++){
        sum->e[k++] = s2->e[j];
    }
    sum->m = s1->m;
    sum->n = s1->n;
    sum->num = k;

    return sum;
}


int main(){
    sparse s1, s2, *s3;
    create(&s1);
    cout << "Now Second Matrix:\n";
    create(&s2);
    s3 = addition(&s1, &s2);
    cout << "First Matrix\n";
    display(s1);
    cout << "Second Matrix\n";
    display(s2);
    cout << "Third Matrix\n";
    display(*s3);



    delete[] s1.e;
    delete[] s2.e;

    delete[] s3->e;
    delete s3;

    return 0;
}