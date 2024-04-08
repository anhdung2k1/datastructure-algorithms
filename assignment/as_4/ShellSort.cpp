#include "SortStrategy.h"

class ShellSort : public SortStrategy {
    public:
        void sort(vector<int>&arr, int& timeExecution) override {
            for (int gap = arr.size(); gap > 0; gap/=2) {
                for (int i = gap; i < arr.size(); i++) {
                    int temp = arr[i];
                    int j;
                    for(j = i; j >= gap && arr[j-gap] > temp; j-=gap) {
                        arr[j] = arr[j-gap];
                    }
                    arr[j] = temp;
                }
            }
        }
        void printSort(vector<int>&arr) override{
            cout << "Shell Sort" << endl;
            for (int val : arr) {
                cout << val << " ";
            }
            cout << endl;
        }
};