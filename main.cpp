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
    auto comma = find(s.begin(), s.end(), ',');
    v.push_back(string(s.begin(), comma));
    while (comma != s.end())
    {
        auto start = ++comma;
        comma = find(start, s.end(), ',');
        v.push_back(string(start, comma));
    }
    return v;
}

void printStudent(student &s)
{
    cout << s.getName() << "\t" << s.calcTotalMark() << "\n";
};

int main()
{

    vector<student> students;
    string line;
    while (cin >> line)
    {
        if (line == ".")
        {
            break;
        }
        vector<string> v = split_csv(line);
        student st(v[0], stof(v[1]));

        for (int i = 2; i < v.size(); i++)
        {
            st.addcwMark(stof(v[i]));
        }
        students.push_back(st);
    }

    // arrange the student records in descending order of marks
    sort(students.begin(), students.end(), compare_marks);

    // print the names and total marks
    cout << "Name\tTotal Marks\n";
    cout << "------- -----------\n";
    for (student st : students)
    {
        printStudent(st);
    }

    // print total no of students that passed
    cout << count_if(students.begin(), students.end(), hasPassed) << " students passed out of " << students.size() << " students.\n";

    return 0;
}
