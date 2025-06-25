#include <iostream>

int main() {
    int *ptr = nullptr;
    ptr = new int;
    *ptr = 10;
    std::cout << "Address is at: " << ptr << '\n';
    std::cout << "Value is: " << *ptr << '\n';

    char *cptr = nullptr;
    int size;
    std::cout<< "How many grades to mark? ";
    std::cin >> size; 
    cptr = new char[size];
    for (int i = 0; i < size; i ++){
        std::cout << "Enter grade number: " << i + 1;
        std::cin >> cptr[i];
        std::cout << cptr[i];
    }

}