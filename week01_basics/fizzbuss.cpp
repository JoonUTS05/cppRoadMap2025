#include <iostream>

//"Write a program that prints the numbers from 1 to 100. 
//But for multiples of three print “Fizz” instead of the number and for the multiples of five print “Buzz”. 
//For numbers which are multiples of both three and five print “FizzBuzz”."

int main (){
    for (int i = 1; i <= 100; i++){
        if (i % 3 == 0 && i % 5 == 0){
            std::cout << "FizzBuzz\n";
        } else if (i % 3 == 0){
            std::cout << "Fizz\n";
        } else if ( i % 5 == 0){
            std::cout << "Buzz\n";
        } else {
            std::cout << "Number: " << i << '\n';
        }
    }
}    