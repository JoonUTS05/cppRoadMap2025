#include <iostream>

int getDigit(const int number){
    return number % 10 + (number /10 % 10);
}
int sumOddDigits(const std::string cardNumber){
    int sum = 0;
    for (int i = cardNumber.length() - 1; i >= 0; i -= 2){
        sum += cardNumber[i] - '0';
    }
    return sum;
}

int sumEvenDigits(const std::string cardNumber){
    int sum = 0;
    for (int i = cardNumber.length() - 2; i >= 0; i -=2 ){
        sum += getDigit((cardNumber[i] - '0') * 2);
    }
    return sum;
}

int main(){
   std::string cardNumber;
   int result = 0;

   std::cout << "Please enter a credit card number: ";
   std::getline(std::cin, cardNumber);
   result = sumEvenDigits(cardNumber) + sumOddDigits(cardNumber);
   if (result % 10 ==0){
    std::cout << result << '\n';
   } else {
    std::cout << "Not valid \n";
   }

}