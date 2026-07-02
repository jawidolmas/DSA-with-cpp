#include<iostream>
#include<string>


/*Create a class named BankAccount.

It should store:

Owner name
Balance

Create member functions to:

Input the information.
Deposit an amount.
Display the final balance.
Expected Output
Enter owner: John
Enter balance: 1000
Enter deposit amount: 250

Final Balance: 1250*/

class BankAccount{
        private:
            std::string name;
            double balance;
        public:
            void setData(std::string username, double bal){
                name = username;
                if (bal >= 0) balance = bal;
                else{
                    std::cout << "Invalid amount\n";
                    balance = 0.0;
                }
            }
            void deposite(double amount){
                if(amount > 0){
                   balance += amount;
                   std::cout << "Operation done successfully\n";
            }else std::cout << "Invalid amount to deposite\n";
            }
            void display() const{
                std::cout << "Final balance: " << balance;
            }



};


int main(){

    std::string inputname;
    double inputbalance;
    double inputamount;
    std::cout << "Username: ";
    std::cin>>inputname;
    std::cout << "Balance: ";
    std::cin >> inputbalance;
    BankAccount u1;
    u1.setData(inputname, inputbalance);
    std::cout << "Enter deposite amount: ";
    std::cin >> inputamount;
    u1.deposite(inputamount);
    u1.display();

    return 0;
}