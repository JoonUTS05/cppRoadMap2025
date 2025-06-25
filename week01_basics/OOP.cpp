#include <iostream>
class Student{
    private:
        std::string name;
        int age;
        double gpa;

    public:
        int getAge(){
            return age;
        }
        std::string getName(){
            return name;
        }
        void setAge(int age){
            this->age = age;
        }
    Student(std::string name, int age, double gpa){
        this->name = name;
        this-> age = age;
        this-> gpa = gpa;
    }
};
int main (){
    Student student1("Rick", 3, 4.0);

}