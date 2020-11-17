#ifndef STUDENT_H
#define STUDENT_H
#include <string>
#include <vector>

using namespace std;

/*********************************************
 * Class : student, consists of -
 * name(string), exam mark(double),
 * coursework marks(double vector)
 * initializer, getName(), addcwMark(),
 * calcTotalMark(), getMedianCwMark()
 * ********************************************/

class student
{
    std::string name;
    float examMark;
    std::vector<float> cwMarks;

public:
    student(const string, float);
    const string getName() const { return name; }
    void addcwMark(float);
    float calcTotalMark() const;

private:
    float getMedianCwMark() const;
};

bool hasPassed(const student);

// String comparison for alphabetical ordering:

bool compare_names(const student, const student);

#endif
