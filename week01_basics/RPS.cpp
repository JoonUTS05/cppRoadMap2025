#include <iostream>
#include <algorithm>
#include <bits/stdc++.h>
std::string getRandom(){
    srand(time(0));
    int num = rand() % 3 + 1;
    switch(num){
        case 1:
            return "r";
        case 2:
            return "p";
        case 3: 
            return "s";
    }
    return 0;
}

void showChoice(const std::string& choice) {
    if (choice == "r") {
        std::cout << "Rock\n";
    } else if (choice == "p") {
        std::cout << "Paper\n";
    } else if (choice == "s") {
        std::cout << "Scissors\n";
    } else if (choice == "rock"){
        std::cout << "Rock\n";
    }else if (choice == "paper") {
        std::cout << "Paper\n";
    } else if (choice == "scissors") {
        std::cout << "Scissors\n";
    }
}
void winner(std::string input, std::string computer){
    if(input == computer){
        std::cout << "Draw as both have chosen " << computer << '\n';
    } else if (input == "r" && computer == "s") {
        std::cout << "Rock beats Scissors, you win\n";
    } else if (input == "r" && computer == "p"){
        std::cout << "Paper beats Rocks, you lose\n";
    } else if (input == "p" && computer == "r"){
        std::cout << "Paper beats Rocks, you win\n";
    } else if (input == "p" && computer == "s"){
        std::cout << "Scissors beats Paper, you lose\n";
    } else if (input == "s" && computer == "r"){
        std::cout << "Pock beats Scissors, you lose\n";
    } else if (input == "s" && computer == "p"){
        std::cout << "Scissors beats Paper, you win\n";
    }
}
int main() {
    std::string input;
    std::string computer;
    std::cout << "------------Welcome to ROCK-PAPER-SCISSORS-----------\n";
    do {
        std::cout << "Please enter either Rock, Paper or Scissors\n";
        std::getline(std::cin, input);
        std::transform(input.begin(), input.end(),input.begin(), [](char c){
            return std::tolower(c);
        });
        if (input == "rock"){
            input = "r";
        } else if (input == "paper"){
            input = "p";
        } else if (input == "scissors"){
            input = "s";
        }
    } while(input !="r" && input != "p" && input != "s" && input != "rock" && input != "paper" && input != "scissors");
        std::cout << "You have chosen: ";
        showChoice(input);
        computer = getRandom();
        std::cout << "Computer has chosen: ";
        showChoice(computer);
        winner(input, computer);
        return 0;
}