#include "student.h"
#include "stats.h"
#include <string>
#include <vector>

using namespace std;

const float exam_weight = 0.7;
const float pass_mark = 40;

student::student(const string n, float e)
{
    name = n;
    examMark = e;
}

void student::addcwMark(float mark)
{
    cwMarks.push_back(mark);
}

float student::calcTotalMark() const
{

    return exam_weight * examMark + (1 - exam_weight) * getCwMark();
}

float student::getCwMark() const
{

    if (cwMarks.size() == 0)
    {
        return 0;
    }
    else if (cwMarks.size() < 3)
    {
        return average(cwMarks);
    }
    else
    {
        return highest3average(cwMarks);
    }
}

bool hasPassed(const student s)
{
    return s.calcTotalMark() >= pass_mark;
}

bool compare_names(const student x, const student y)
{
    return x.getName() < y.getName();
}

bool compare_marks(const student x, const student y)
{
    return x.calcTotalMark() > y.calcTotalMark();
}
