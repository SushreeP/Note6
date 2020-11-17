#include "student.h"
#include <algorithm>
#include <iomanip>
#include <iostream>
#include <string>
#include <vector>
using namespace std;

// Split a string containing comma-separated values
vector<string> split_csv(const string &s)
{

    vector<string> v;
    auto comma = find(s.cbegin(), s.cend(), ',');
    v.push_back(string(s.cbegin(), comma));
    while (comma != s.cend())
    {
        auto start = ++comma;
        comma = find(start, s.cend(), ',');
        v.push_back(string(start, comma));
    }
    return v;
}

void loadStudentData(vector<student> &students)
{
    string line;
    vector<string> v;
    while (cin >> line)
    {
        v = split_csv(line);
    }

    // 1st str in v is the name, 2nd str is exam mark
    student st(v[0], stof(v[1])); // stof() converts a string value to float

    // rest all are coursework marks
    for (int i = 2; i < v.size(); i++)
    {
        st.addcwMark(stof(v[i]));
    }
}

void printStudent(student &s)
{
    cout << s.getName() << "\t" << s.calcTotalMark() << "\n";
};

int main()
{

    vector<student> students;

    // read and store the data
    loadStudentData(students);

    // arrange the student records in alphaetical order
    sort(students.cbegin(), students.cend(), compare_names);

    // print the names and total marks
    cout << "Name\tTotal Marks\n";
    for (student s : students)
    {
        printStudent(s);
    }

    // print total no of students that passed
    cout << count_if(students.cbegin(), students.cend(), hasPassed) << " students passed out of " << students.size() << " students.\n";
    return 0;
}
