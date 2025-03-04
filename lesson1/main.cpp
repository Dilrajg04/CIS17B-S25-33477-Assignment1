//
//  main.cpp
//  lesson1
//
//  Created by Dilraj Grewal on 3/2/25.
//

#include <iostream>
using namespace std;

//class
class BankAccount{
    
private:
    string accountHolderName;
    int accountNumber;
    double balance;

public:
//functions
//contructor
    BankAccount(string a_name, int accNum, double s_balance){
        accountHolderName = a_name;
        balance = s_balance;
    }
    
    void deposit(double amount){
        balance += amount;
    }
    
    void withdraw(double amount){
        balance -= amount;
       
    }
    //returns the balance
    double getBalance(){
        return balance;
    }
    //gets the name
    string getName(){
        return accountHolderName;
    }
    
    
};
//input validation function
bool isNotNegative(double num){
    if(num < 0){
        return false;
    }
    return true;
}
int main(int argc, const char * argv[]) {
    //variables
    int option = 0;
    int option2 = 0;
    string name;
    double balance = 0;
    int acnum;
    double dmoney;
    double wmoney;
    bool isString = false;
    //display menu
    cout << "1. Create an account." << endl;
    cout << "2. Deposit." << endl;
    cout << "3. Withdraw." << endl;
    cout << "4. Check balance." << endl;
    cout << "5. Exit." << endl;
    cout << endl;
    cout << "Choose an option: ";
    cin >> option;
    //aborts if 5 is entered.
    if(option == 5){
        return 0;
    }
    
    else if(option == 1){
        while(isString == false){
            try {
                cout << "To create your account, please enter your name: ";
                cin >> name;
                //loop to check if the digits entered are characters or integers.
                for(char c : name){
                    if(isdigit(c)){
                        throw invalid_argument("Please enter a string.");
                    }
                    else{
                        isString = true;
                    }
                }
            } catch (const invalid_argument &e) {
                //e.what is used to reference the exception values
                cout << e.what() << "Try again." << endl;
            }
        }
        
        cout << "Enter a number for your account: ";
        cin >> acnum;
        //account number validation - no negative numbers.
        while(isNotNegative(acnum) != true){
            cout << "Please enter a valid account number: ";
            cin >> balance;
            break;
        }
        cout << "Enter initial deposit amount: $";
        cin >> balance;
        //deposit validation - no negative numbers.
        while(isNotNegative(balance) != true){
            cout << "Try again. Enter intial deposit: $";
            cin >> balance;
            break;
        }
        BankAccount account(name,acnum,balance);
        cout << endl;
        cout << "Account create sucessfully!" << endl;
        cout << endl;
        
        //actions for post account creation
        while(option2 != 4){
            cout << "1. Deposit." << endl;
            cout << "2. Withdraw." << endl;
            cout << "3. Check balance." << endl;
            cout << "4. Exit." << endl;
            cout << endl;
            cout << "Choose an option: ";
            cin >> option2;
            
            switch(option2){
                case 1:
                    cout << "Enter the amount to deposit: $";
                    cin >> dmoney;
                    account.deposit(dmoney);
                    cout << "Deposit successful" << endl;
                    cout << "New balance: $" << account.getBalance();
                    cout << endl;
                    break;
                case 2:
                    cout << "Enter money to withdraw: $";
                    cin >> wmoney;
                    if(wmoney > account.getBalance()){
                        cout <<"Infsufficient funds!" << endl;
                        cout << endl;
                    }
                    else if(wmoney <= 0){
                        cout << "Please use a valid expression!";
                        cout << endl;
                    }
                    else{
                        account.withdraw(wmoney);
                        cout << "Money withdrawn successfully!" << endl;
                        cout << endl;
                    }
                    break;
                case 3:
                    cout << "Current balance : $";
                    cout << account.getBalance();
                    cout << endl;
                    break;
                case 4:
                    cout << "Thank you for banking with us" << endl;
                    break;
                    return 0;
                default:
                    cout << "Invalid input. Please select one of the following options." << endl;
                    
            }
            
            
        }
        
        
    }
    
    //Begining of the second loop with "no account detected" line
    while(option != 1){
        cout << "No account detected " << endl;
        cout << "Please create an account" << endl;
        cout << endl;
        cout << endl;
        cout << "1. Create an account." << endl;
        cout << "2. Deposit." << endl;
        cout << "3. Withdraw." << endl;
        cout << "4. Check balance." << endl;
        cout << "5. Exit." << endl;
        cout << endl;
        cin >> option;
        
        
        if(option == 5){
            return 0;
        }
        //to check if information entered is characters or integers.
        while(isString == false){
            try {
                cout << "To create your account, please enter your name: ";
                cin >> name;
                //loop for input validation.
                for(char c : name){
                    if(isdigit(c)){
                        throw invalid_argument("Please enter a string.");
                    }
                    else{
                        isString = true;
                    }
                }
            } catch (const invalid_argument &e) {
                cout << e.what() << "Try again." << endl;
            }
        }
        cout << "Enter a number for your account: ";
        cin >> acnum;
        //input validation loop
        while(isNotNegative(acnum) != true){
            cout << "Please enter a valid account number: ";
            cin >> balance;
            break;
    }
            cout << "Enter initial deposit amount: $";
            cin >> balance;
        //deposit validation - no negative numbers.
            while(isNotNegative(balance) != true){
                cout << "Try again. Enter intial deposit: $";
                cin >> balance;
                break;
            }

            BankAccount account(name,acnum,balance);
            cout << endl;
            cout << "Account create sucessfully!" << endl;
            cout << endl;
            
            
            while(option2 != 4){
                cout << "1. Deposit." << endl;
                cout << "2. Withdraw." << endl;
                cout << "3. Check balance." << endl;
                cout << "4. Exit." << endl;
                cout << endl;
                cin >> option2;
                
                switch(option2){
                    case 1:
                        cout << "Enter the amount to deposit: $";
                        cin >> dmoney;
                        account.deposit(dmoney);
                        cout << "Deposit successful" << endl;
                        cout << "New balance: $" << account.getBalance();
                        cout << endl;
                        break;
                    case 2:
                        cout << "Enter money to withdraw: $";
                        cin >> wmoney;
                        if(wmoney > account.getBalance()){
                            cout <<"Infsufficient funds!" << endl;
                            cout << endl;
                        }
                        else if(wmoney <= 0){
                            cout << "Please use a valid expression!";
                            cout << endl;
                        }
                        else{
                            account.withdraw(wmoney);
                            cout << "Money withdrawn successfully!" << endl;
                            cout << endl;
                        }
                        break;
                    case 3:
                        cout << "Current balance : $";
                        cout << account.getBalance();
                        cout << endl;
                        break;
                    case 4:
                        cout << "Thank you for banking with us" << endl;
                        break;
                        return 0;
                    default:
                        cout << "Invalid input. Please select one of the following options." << endl;
                 }
            }
         }
    }


