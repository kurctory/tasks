#include <iostream>
#include <vector>
#include <algorithm>
#include <functional>

using namespace std;


/**
 * compare two points
 * @param p1 first point
 * @param p2 second point
 * @return true if p1 less then p2
 */
bool compare_points(pair<int, int> p1, pair<int, int> p2)
{
    int r1 = p1.first * p1.first + p1.second * p1.second;
    int r2 = p2.first * p2.first + p2.second * p2.second;
    return r1 - r2 < 0;
}


/**
 * sort array of points
 * @param points array of unsorted points
 */
void sort_points(vector<pair<int, int>> & points)
{
    vector<pair<int, int>>::iterator iA = points.begin();
    vector<pair<int, int>>::iterator iAend = points.end();
    sort(iA, iAend, compare_points);
}
