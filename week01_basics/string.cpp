#include <iostream>
#include <cmath>
#include <cctype>
void showBalance (double balance){
    std::cout << "\n" << "Your balance is: $" << balance << '\n';
}
double desposit(){
    double amount = 0;
    std::cout << "\n" << "Enter the amount to be deposited: ";
    std::cin >> amount;
    if (amount < 0){
        std::cout << "Insufficient Amount";
        return 0;
    }
    return amount;
}
double withdraw(double balance){
    double amount = 0;
    do {
        std::cout << "\n" << "You currently have: $" << balance << " dollars available \n";
        std::cout << "Please enter an amount to be withdrawn: ";
        std::cin >> amount;

        if (balance < amount || amount < 0){
            std::cout << "Insufficient funds! \n";
        }
    } while (balance < amount || amount < 0);
    return amount;
}

int main(){
    double balance  = 1000;
    char choice;
    do {
        std::cout << "\n" << "Please Enter a char to select your choice: \n" << "1. Show Balance {s} \n" << "2. Deposit Money {d} \n" << "3. Withdraw Money {w} \n" << "4. Exit {e}\n\n";
        std::cout << "Enter your response here: ";
        std::cin >> choice; 
        choice = tolower(choice);
        if (choice != 's' && choice != 'd' && choice != 'w' && choice != 'S' && choice != 'D' && choice != 'W' && choice != 'e' && choice != 'E') {
            std::cout << "\n\n" << "You have entered an invalid selection, please input a valid choice: {s / d / w / e} \n";
        } 
        switch (choice) {
            case 's': 
                showBalance(balance);
                break;
            case 'd':
                balance += desposit();
                showBalance(balance);
                break;
            case 'w':
                balance -= withdraw(balance);
                showBalance(balance);
                break;
            case 'e':
                std::cout << "You have successfully exited the program \n";
                break;
            default:
                std::cout << "\n" << "Invalid choice \n";
                break;
        }
    } while (choice != 'e' && choice != 'E');
}
