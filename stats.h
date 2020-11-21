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

float highest3average(vector<float> v)
{
    sort(v.begin(), v.end());
    float sum = 0;
    for (int i = 0; i < 3; i++)
    {
        sum += v[i];
    }

    return (float)(sum / 3);
}
#endif