#ifndef STATS_H
#define STATS_H
#include <string>
#include <vector>
#include <algorithm>

using namespace std;

float median(vector<float> v)
{
    sort(v.begin(), v.end());
    if (v.size() % 2 == 0)
    {
        return v[v.size() / 2];
    }
    return (v[v.size() / 2 - 1] + v[v.size() / 2]) / 2;
}

float average(vector<float> v)
{
    float sum = 0;
    for (float x : v)
    {
        sum += x;
    }

    return (float)(sum / v.size());
}

#endif