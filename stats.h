#ifndef STATS_H
#define STATS_H
#include <string>
#include <vector>
#include <algorithm>

using namespace std;

float median(const vector<float> v)
{
    sort(v.begin(), v.end());
    if (v.size() % 2 == 0)
    {
        return v[v.size() / 2];
    }
    return (v[v.size() / 2 - 1] + v[v.size() / 2]) / 2;
}

#endif