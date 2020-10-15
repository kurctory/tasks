#include "lab1.h"
#include "doctest.h"
//
// Created by vikokoks on 08.05.2020.
//


TEST_CASE("compare two points")
{
    pair<int, int> p2 = {6, 4};
    pair<int, int> p1 = {5, 5};
    CHECK(compare_points(p1, p2));
}

TEST_CASE("sort vector of points")
{
    vector<pair<int, int>> sample = {
            {1, 1},
            {3, 3},
            {2, 2}
    };
    sort_points(sample);
    CHECK(sample[0].first == 1);
    CHECK(sample[1].first == 2);
    CHECK(sample[2].first == 3);
}