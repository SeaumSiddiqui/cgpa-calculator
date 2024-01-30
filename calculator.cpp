#include<iostream>
#include<cctype>
#include<unordered_map>
#include<iomanip>

using namespace std;

float gradePoints(string grade);
void calculateGPA(float& credits, float& weightedSum);
void calculateCGPA(float credits, float weightedSum);

struct Course {
    string name;
    string grade;
    float credit;
};

int main() {
    int input = 1;

    while (input == 1) {
        float credits = 0;
        float weightedSum = 0;

        system("cls"); // clear the console

        int numOfSemesters;
        cout<< "Enter number of semester: ";
        cin>> numOfSemesters;

        for (int i=0; i<numOfSemesters; i++) {
            cout<< endl << "SEMESTER-" << i+1;

            calculateGPA(credits, weightedSum);
            calculateCGPA(credits, weightedSum);
        }
        cout<< endl << "\t\e[38;5;105m 0.Exit Program" << endl << "\t 1.Calculate Again" << endl;
        cout<< endl << "Enter Your Choice: \e[0m";
        cin>> input;
        cout<< endl;
    }
}


//*****************Calculate GPA******************

void calculateGPA(float& credits, float& weightedSum) {
    float semesterCredit;
    float semesterGPA;
    float weightGPA;

    int numOfCourses;
    cout<< " Enter number of courses: ";
    cin>> numOfCourses;

    for (int i=0; i<numOfCourses; i++) {
        Course c;
        cout<< "COURSE: " << i+1 << endl;

        cout<< "\t" << "Name: ";
        cin>> c.name;

        cout<< "\t" << "Grade: ";
        cin>> c.grade;

        for (char& ch: c.grade) {
            ch = toupper(ch);
        }

        cout<< "\t" << "Credit: ";
        cin>> c.credit;
        cout<< endl;

        weightGPA += gradePoints(c.grade) * c.credit;
        semesterCredit += c.credit;
    }
    // update GPA for each semester
    semesterGPA = weightGPA/semesterCredit;

    cout << ">Credit Complete: ";
    // check if semester credit is int
    if (semesterCredit == static_cast<int>(semesterCredit)) {
        cout<< static_cast<int>(semesterCredit);
    } else {
        cout<< fixed << setprecision(1) << semesterCredit;
    }
    cout<< " | Semester GPA " << fixed << setprecision(2) << semesterGPA;


    // sum credits for each semester, to calculate CGPA
    credits += semesterCredit;
    // SemesterGPA * SemesterCredits, to calculate CGPA
    weightedSum += semesterGPA * semesterCredit;
}


//*****************Calculate CGPA*****************

void calculateCGPA(float credits, float weightedSum) {
    float CGPA = weightedSum/credits;

    cout<< " | Total Credit: ";
    // check if credit is an int
    if (credits == static_cast<int>(credits)) {
        cout<< static_cast<int>(credits);
    } else {
        cout<< fixed << setprecision(1) << credits;
    }
    cout<< " | CGPA " << fixed << setprecision(2) << CGPA << endl;
}


float gradePoints(const string grade) {
    unordered_map<string, float> point;

    point["A+"] = 4.00;
    point["A"] = 3.75;
    point["A-"] = 3.50;
    point["B+"] = 3.25;
    point["B"] = 3.00;
    point["B-"] = 2.75;
    point["C+"] = 2.50;
    point["C"] = 2.25;
    point["D"] = 2.00;
    point["F"] = 0.00;

    return point[grade];
}
