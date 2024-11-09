#include <iostream>
#include <iomanip>
#include <string>
#include <vector>
#include <limits>

using namespace std;

struct StudentType {
    string studentFName;
    string studentLName;
    int testScore;
    char grade;
};

void readStudentsData(StudentType students[], int count) {
    for (int i = 0; i < count; i++) {
        cout << "Enter first name of student " << (i + 1) << ": ";
        cin >> students[i].studentFName;
        cout << "Enter last name of student " << (i + 1) << ": ";
        cin >> students[i].studentLName;
        cout << "Enter test score (0-100) " << students[i].studentFName << " " << students[i].studentLName << ": ";
        cin >> students[i].testScore;

        
        while (cin.fail() || students[i].testScore < 0 || students[i].testScore > 100) {
            cin.clear(); 
            cin.ignore(numeric_limits<streamsize>::max(), '\n'); 
            
            cout << "The test score is invalid. Please enter a score between 0 and 100: ";
            cin >> students[i].testScore;
        }
    }
}

void assignGrades(StudentType students[], int count) {
    for (int i = 0; i < count; i++) {
        if (students[i].testScore >= 90) {
            students[i].grade = 'A';
        } else if (students[i].testScore >= 80) {
            students[i].grade = 'B';
        } else if (students[i].testScore >= 70) {
            students[i].grade = 'C';
        } else if (students[i].testScore >= 60) {
            students[i].grade = 'D';
        } else {
            students[i].grade = 'F';
        }
    }
}

int findHighestScore(const StudentType students[], int count) {
    int highestScore = students[0].testScore;
    for (int i = 1; i < count; i++) {
        if (students[i].testScore > highestScore) {
            highestScore = students[i].testScore;
        }
    }
    return highestScore;
}

void printStudentData(const StudentType students[], int count) {
    cout << left << setw(25) << "Student Name" << setw(10) << "Nilai" << "Grade" << endl;
    cout << string(45, '-') << endl;

    for (int i = 0; i < count; i++) {
        cout << left << setw(25) << (students[i].studentLName + ", " + students[i].studentFName)
             << setw(10) << students[i].testScore << students[i].grade << endl;
    }
}

void printStudentsWithHighestScore(const StudentType students[], int count, int highestScore) {
    cout << "\nStudent with the highest score (" << highestScore << "):" << endl;

    for (int i = 0; i < count; i++) {
        if (students[i].testScore == highestScore) {
            cout << students[i].studentLName << ", " << students[i].studentFName << endl;
        }
    }
}

int main() {
    const int MAX_STUDENTS = 20;
    StudentType students[MAX_STUDENTS];
    readStudentsData(students, MAX_STUDENTS);
    assignGrades(students, MAX_STUDENTS);
    int highestScore = findHighestScore(students, MAX_STUDENTS);
    printStudentData(students, MAX_STUDENTS);
    printStudentsWithHighestScore(students, MAX_STUDENTS, highestScore);
    return 0;
}

