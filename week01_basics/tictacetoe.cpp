#include <iostream>
void drawBoard(char *spaces){
    std::cout << "     |     |     " << '\n';
    std::cout << "  " << spaces[0] << "  |  " << spaces[1] << "  |  " << spaces[2] << "   " << '\n';
    std::cout << "_____|_____|_____" << '\n';
    std::cout << "     |     |     " << '\n';
    std::cout << "  " << spaces[3] << "  |  " << spaces[4] << "  |  " << spaces[5] << "   " << '\n';
    std::cout << "_____|_____|_____" << '\n';
    std::cout << "     |     |     " << '\n';
    std::cout << "  " << spaces[6] << "  |  " << spaces[7] << "  |  " << spaces[8] << "   " << '\n';
    std::cout << "     |     |     " << '\n';

}
void playerMove(char *spaces, char player){
    int number;
    do {
        std::cout << "Enter a spot to place a marker from 1-9: ";
        std::cin >> number;
        number--;
        if (spaces[number] == ' '){
            spaces[number] = player;
            break;
        }
    } while (number < 0 || number > 8 || spaces[number] != ' '); 


}
void computerMove(char *spaces, char computer){
    int number;
    srand(time(0));
    while (true){
        number = rand() % 9;
        if (spaces[number] == ' '){
            spaces[number] = computer;
            break;
        }
    }
}
bool checkWinner(char *spaces, char player){
    for (int i = 0; i < 9; i += 3){
        if (spaces[i] != ' ' && spaces[i] == spaces[i+1] && spaces[i] == spaces[i+2]){
            if (spaces[i] == player){
                std::cout << "You Win!\n";
                return true;
            } else {
                std::cout << "You Lose!\n";
                return true;
            }
        }
    }
    for (int i = 0; i < 3; i++){
        if (spaces[i] != ' ' && spaces[i] == spaces[i+3] && spaces[i] == spaces[i+6]){
            if (spaces[i] == player){
                std::cout << "You Win!\n";
                return true;
            } else {
                std::cout << "You Lose!\n";
                return true;
            }
        }
    }
    if (spaces[4] != ' ' && spaces[4] == spaces[0] && spaces[4] == spaces[8]){
        if (spaces[4] == player){
                std::cout << "You Win!\n";
                return true;
            } else {
                std::cout << "You Lose!\n";
                return true;
            }
    }
    if (spaces[4] != ' ' && spaces[4] == spaces[2] && spaces[4] == spaces[6]){
        if (spaces[4] == player){
                std::cout << "You Win!\n";
                return true;
            } else {
                std::cout << "You Lose!\n";
                return true;
            }
    }
    return false;;
}
bool checkTie(char *spaces){
    for (int i = 0; i < 9; i++){
        if (spaces[i] == ' '){
            return false;
        }
    } 
    std::cout << "The game is Drawn! \n";
    return true;
}
int main() {
    char spaces[9] = {' ',' ',' ',' ',' ',' ',' ',' ',' '};
    char player = 'X';
    char computer = 'O';
    bool running = true;

    drawBoard(spaces);

    while (running) {
        playerMove(spaces, player);
        drawBoard(spaces);

        if (checkWinner(spaces, player)) {
            running = false;
            break;
        }
        if (checkTie(spaces)) {
            running = false;
            break;
        }
        std::cout << '\n';
        computerMove(spaces, computer);
        drawBoard(spaces);

        if (checkWinner(spaces, player)) {
            running = false;
            break;
        }
        if (checkTie(spaces)) {
            running = false;
            break;
        }
    }

    std::cout << "Thank you for Playing! \n";
    return 0;
}
