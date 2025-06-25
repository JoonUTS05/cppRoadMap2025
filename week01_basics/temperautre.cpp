#include <iostream>
#include <cmath>
int main(){
  double temp;
  char unit;
  std::cout << "***** Temperature Conversion ******\n";
  do {
      std::cout << "Please Select a unit of temperature: \n" << "F for fahrenheit \n" << "C for celsius \n" << "What unit would you like to convert to F OR C: ";
      std::cin >> unit;
      if (unit != 'F' && unit != 'C' && unit != 'f' && unit != 'c'){
        std::cout << "You have Entered an invalid unit of temperature. \n";
      }
      if (unit == 'F' || unit == 'f'){
        std::cout << "Enter the temperature in Celsius: ";
        std::cin >> temp;
        temp = (1.8 * temp) + 32.0;
        std::cout << "Temperature in Fahrenheit is: " << temp << " degrees F \n";
      } else if (unit == 'C' || unit == 'c'){
        std::cout << "Enter the temperature in Fahrenheit: ";
        std::cin >> temp;
        temp = (temp - 32) /1.8;
        std::cout << "Temperature in Celsius is : " << temp << "degrees C \n";
        
      }

  } while (unit != 'F' && unit != 'C');
  return 0;
}