#ifndef SORTSTRATEGY_H
#define SORTSTRATEGY_H

#include <bits/stdc++.h>
using namespace std;
using namespace std::chrono;

class SortStrategy {
    public:
        virtual void sort(vector<int>& arr, int& timeExecution) = 0;
        virtual void printSort(vector<int>& arr) = 0;
};

#endif