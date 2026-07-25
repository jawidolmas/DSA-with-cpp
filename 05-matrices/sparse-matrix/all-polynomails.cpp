#include<iostream>
using namespace std;        // Only use it on daily small tasks.


        /*
            Polynomail Representation
        */


struct term{

   int coeff;       // Coeffecient of poly.
   int expo;        // Expo of poly. Natural numbers
};

struct poly{
    int n;          // Number of terms
    term *t;
};

// Create
void create(poly &p){
    cout << "Enter number of non-zero terms: ";
    cin >> p.n;
    p.t = new term[p.n];    
    cout << "Enter Coeff & Expo\n";
    for(int i = 0; i<p.n; i++){
        cout << "Term number: " << i+1 << " \n";
        cout << "Coeffecient: ";
        cin >> p.t[i].coeff;
        cout << "Exponential: ";
        cin >> p.t[i].expo;
    }
}
//Power
int pow(int var, int power){
    if(power == 0){
        return 1;
    }
    return var * pow(var, power-1);
}


// Evalaute polynomail

int evaluate(poly p){
    int x = 5; 
    int sum = 0;
    for(int i = 0; i<p.n; i++){
        sum += p.t[i].coeff * pow(x, p.t[i].expo);
    }
    return sum;
}

// Addition
poly *addition(poly &p1, poly &p2){
    poly *sum;
    int i, j, k;
    i = j = k = 0;
    sum = new poly;
    sum->t = new term[p1.n + p2.n];    
    while(i < p1.n && j < p2.n){
        if(p1.t[i].expo > p2.t[j].expo){
            sum->t[k++] = p1.t[i++];
        }
        else if(p1.t[i].expo < p2.t[j].expo){
            sum->t[k++] = p2.t[j++];
        }
        else{
            sum->t[k].expo = p1.t[i].expo;
            sum->t[k++].coeff = p1.t[i++].coeff + p2.t[j++].coeff;
        }

    }
    for(; i<p1.n; i++) sum->t[k++] = p1.t[i];
    for(; j<p2.n; j++) sum->t[k++] = p2.t[j];
    sum->n = k;
    return sum;
}

// Display

void display(poly p){
    for(int i = 0; i<p.n; i++){
        cout << p.t[i].coeff << "x^" << p.t[i].expo;
        if(i < p.n - 1) cout << "+";
    }
    cout << "\n";
}

int main(){
    poly p, p1, *p2;
    create(p);
    create(p1);
    p2 = addition(p, p1);
    cout << "First Polynomail\n";
    display(p);
    cout << "Second Polynomail\n";
    display(p1);
    cout << "Sum of Polynomails\n";
    display(*p2);




    delete[] p.t;
    delete[] p1.t;
    delete[] p2->t;
    delete p2;
    
    return 0;
}



/*
    Output:

        Enter number of non-zero terms: 3
        Enter Coeff & Expo
        Term number: 1 
        Coeffecient: 4
        Exponential: 3
        Term number: 2 
        Coeffecient: 5
        Exponential: 2
        Term number: 3 
        Coeffecient: 6
        Exponential: 1
        Enter number of non-zero terms: 3
        Enter Coeff & Expo
        Term number: 1 
        Coeffecient: 7
        Exponential: 3
        Term number: 2 
        Coeffecient: 9
        Exponential: 2
        Term number: 3 
        Coeffecient: 6
        Exponential: 1
        First Polynomail
        4x^3+5x^2+6x^1
        Second Polynomail
        7x^3+9x^2+6x^1
        Sum of Polynomails
        11x^3+14x^2+12x^1
*/