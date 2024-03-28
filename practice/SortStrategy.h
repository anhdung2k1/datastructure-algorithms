#ifndef SORTSTRATEGY_H
#define SORTSTRATEGY_H

#include<iostream>
#include<fstream>
#include<vector>
#include<sstream>
#include<time.h>
#include "string.h"
#include<memory>

using namespace std;

class SortStrategy {
    protected:
        clock_t start, end;
        double cpu_time_used;
    public:
        bool isDesc = false;
        double getCpuTimeUsed() {
            return cpu_time_used;
        }

        void setCpuTimeUsed(double cpu_time_used) {
            this->cpu_time_used = cpu_time_used;
        }
        virtual void sort(vector<int>& arr) = 0;
        virtual void printSort(vector<int>& arr) = 0;
};

#endif