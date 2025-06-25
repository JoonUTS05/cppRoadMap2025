#include <iostream>

struct student{
    std::string name;
    double gpa;
    bool enrolled;
};



int main() {
    student student1;
    student1.name = "SpongeBob";
    student1.gpa = 4.0;
    student1.enrolled = true;
    std::cout << student1.name << '\n';
    std::cout << student1.gpa << '\n';
    std::cout << student1.enrolled << '\n';
    student student2;
    student2.name = "Louis";
    student2.gpa = 4.0;
    student2.enrolled = true;
    std::cout << student2.name << '\n';
    std::cout << student2.gpa << '\n';
    std::cout << student2.enrolled << '\n';
}
