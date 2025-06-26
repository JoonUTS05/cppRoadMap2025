#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#include <iomanip>
/* Functional Requirements
1. Input Number of Subjects
- The program must prompt the user to enter how many subjects they want to input marks for.

2. Input Marks for Each Subject
- The user will enter marks (integer or decimal) for each subject one by one.

3. Calculate total marks
- The program will calculate the total marks by summing up all the marks entered for each subject.

4. Calculate average, median and total GPA
- The program will calculate the average, median and GPA

5. Assign a letter grade based on average
- 85 and above: Grade High Distinction
- 75-84: Grade Distinction
- 65-74: Grade Credit
- 50-64: Grade Pass
- 0-49: Grade Fail
- Grade Withheld

6. Display results
- The program will display the total marks, average, median, GPA

Non-functional Requirements
- The program should handle invalid inputs gracefully 
- Use clear prompts and outputs for easy user interaction.
- Written in C++ using standard input/output streams.
*/
int getNumberOfSubject(){
    int numOfSubjects;
    do {
        std::cout << "Please enter a valid number of subjects (greater than 0): ";
        std::cin >> numOfSubjects;
         if (std::cin.fail() || numOfSubjects <= 0) {
            std::cin.clear();
            std::cin.ignore(1000, '\n');
            std::cout << "Invalid input. Number of subjects must be greater than 0." << std::endl;
            numOfSubjects = 0;
        }
    } while (numOfSubjects <= 0);
    std::cin.ignore();
    return numOfSubjects;
}

std::vector<std::pair<std::string, double>> getSubjectDetails(int numOfSubjects) {
    std::string subjectName;
    double marks;
    std::vector<std::pair<std::string, double>> subjects;
        for (int i = 1; i <= numOfSubjects; ++i) {
        std::cout << "Please enter the name of subject " << i << ": ";
        std::getline(std::cin, subjectName);
        do {
            std::cout << "Please enter the mark received for " << subjectName << ": ";
            std::cin >> marks;
            if (std::cin.fail() || marks < 0 || marks > 100) {
                std::cin.clear();
                std::cin.ignore(1000, '\n');
                std::cout << "Invalid input. Marks must be between 0 and 100." << std::endl;
                marks = -1;
            } else {
                std::cin.ignore();
            }
            } while (marks < 0 || marks > 100); 
            subjects.push_back({subjectName, marks});
        }
    return subjects;
}

double addMarks(std::vector<std::pair<std::string, double>>& subjects) {
    int sum = 0;
    for (const auto& subject : subjects) {
        sum += subject.second;
    }
    return sum;
}

double getMean(int sum, int numOfSubjects){
    double mean = 0.0;
    if (sum == 0) {
        return mean;
    }
    mean = static_cast<double>(sum) / numOfSubjects;
    return mean;
}

double getMedian(std::vector<std::pair<std::string, double>>& subjects, int numOfSubjects){
    double median = 0.0;
    std::vector<double> sortedMarks;
    for (const auto& subject : subjects) {
        sortedMarks.push_back(subject.second);
    }
    std::sort(sortedMarks.begin(), sortedMarks.end());
    if (numOfSubjects % 2 == 1) {
        median = sortedMarks[numOfSubjects / 2];
    } else {
        median = (sortedMarks[(numOfSubjects / 2) - 1] + sortedMarks[numOfSubjects / 2]) / 2;
    }
    return median;
}

double getGPA(std::vector<std::pair<std::string, double>>& subjects, int numofSubjects){
    int gradePointValue = 0; 
    int totalCredit = numofSubjects * 6;
    double gpa = 0.0;
    for (const auto& subject : subjects){
        if (subject.second >= 85 && subject.second <= 100) {
            gradePointValue += 42;
        }else if (subject.second >= 75 && subject.second <= 84){
            gradePointValue += 36;
        }else if (subject.second >= 65 && subject.second <= 74){
            gradePointValue += 30;
        }else if (subject.second >= 50 && subject.second <= 64){
            gradePointValue += 24;
        }else {
            gradePointValue += 0;
        }
    }
    gpa = gradePointValue / totalCredit;
    return gpa;
}

std::string getAverageGrade(double mean) {
    if (mean >= 85) return "High Distinction";
    else if (mean >= 75) return "Distinction";
    else if (mean >= 65) return "Credit";
    else if (mean >= 50) return "Pass";
    else return "Fail";
}

int main() {
    std::cout << "Welcome to the Grade Calculator\n";
    int numOfSubjects = getNumberOfSubject();
    auto subjects = getSubjectDetails(numOfSubjects);
    double total = addMarks(subjects);
    double mean = getMean(total, numOfSubjects);
    double median = getMedian(subjects, numOfSubjects);
    double gpa = getGPA(subjects, numOfSubjects);
    std::string grade = getAverageGrade(mean);
    std::cout << "\n===== Results Summary =====\n";
    std::cout << std::fixed << std::setprecision(2);
    for (const auto& subject : subjects) {
        std::cout << subject.first << ": " << subject.second << "\n";
    }
    std::cout << "Total Marks: " << total << "\n";
    std::cout << "Average: " << mean << "\n";
    std::cout << "Median: " << median << "\n";
    std::cout << "GPA: " << gpa << "\n";
    std::cout << "Letter Grade: " << grade << "\n";
    
    return 0;
}