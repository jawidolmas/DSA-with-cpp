#include<iostream>


// Array operations implementation in OOP.

class Array{                 // The class itself does not have time/space complexity by existing. 
    private:
        int A[10];
        int capacity;
        int size;
    public:
        Array() : A(), capacity(10), size(0){ // O(1) on runtime. reason: constructor initailizes the class
            
        }

        void Append(int element);
        void Insert(int index, int element);
        void display() const;
};

void Array::Append(int element){    // Complexity: O(3) -> O(const) -> final: O(1)
    if (size >= capacity) return;    // O(1)
    A[size] = element;              // O(1)
    size++;                         // O(1);
}

void Array::Insert(int index, int element){       // Complexity:  1 + n + n + 1 + 1 = n + 3. the Big O notation depends on degree of polynom. so its O(n)
    if (size < capacity && size >= index && index >= 0){   // One check: O(1) 
        for(int i = size - 1; i >= index; --i){ // Imagine a line of people, when I want to add a new people between those lines, I need to shift them backward or forward in order to not destroy people(data) in line. In here, we made people to go back and we add element. 
             // i from size - 1 to index, so it iterates each time and depends on size of SIZE and INDEX. so it is O(n).
            A[i + 1] = A[i];    
        }
        A[index] = element;  // One initialization. O(1)
        size++;              // One increment. O(1)
}   
}

void Array::display() const{            // Complexity: 1 + n + n = n + 1-> function of complexity. big O is O(n) 
    std::cout << "Array Elements:\n";   // One printing. O(1)
    for (int i = 0; i<size; i++){       // One loop, and it goes from 0 to size, it depends on size of SIZE. its O(n)
        std::cout << A[i] << "\n";      
    }

}

int main(){             // Complexity: 1 + 1 + 1 + 1 + 1 + 1 + 1 + 1 + 1 = 9n^0 and n^0 = 1 O(1).  O(const) -> O(1)  
    
    Array arr;          // One command and give control to append. O(1)
    arr.Append(10);     // One command and gives control to append. O(1) + function complexity
    arr.Append(20);     // One command and give control to append. O(1)  + function complexity
    arr.Append(30);     // One command and give control to append. O(1)  + function complexity
    arr.Insert(0, 5);   // One command and give control to append. O(1)  + function complexity
    arr.Insert(8, 40);   /* (One command and give control to append. O(1)) + function complexity .  This is technically possible, the 8th index is alredy a garbage value and insert(8, 40) can shift those values back and forth.  
                        The problem is the policy of class. the functions append, insert, display only trust in class. so display will care on until size. It does not care 
                        wether the value in index 8th is real or a grabage value.*/
    arr.display();      // One command and give control to append. O(1) + function complexity.

    return 0;           // One command and give control to append. O(1)
}


// The total Time Complexity for this program is the total Complexity of the main() which is all executed instructions.(including all instructions, not main itself)