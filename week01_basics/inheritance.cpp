#include <iostream>

class Animal{
    public:
        bool alive = true;
        void eat(){
            std::cout <<"This animal is eating\n";
        }
};
class Dog : public Animal{
    public:
        void bark(){
            std::cout << "Woof! \n";
        }
};

class Cat : public Animal{
    public: 
        void meow(){
            std::cout << "Meow! \n";
        }
};










int main(){
    Dog dog1;
    std::cout<< dog1.alive << '\n';
    dog1.eat();
    dog1.bark();

    Cat cat;
    cat.meow();
    cat.eat();
}