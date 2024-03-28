#include "SortStrategy.h"

class SelectionSort : public SortStrategy {
    private:
        void swap(int &a, int &b) {
            int temp = a;
            a = b;
            b = temp;
        }
    public:
        void sort(vector<int>& arr) override {
            start = clock();
            int min_idx;
            for(int i = 0; i < arr.size()-1; i++) {
                min_idx = i;
                for(int j = i + 1; j < arr.size(); j++) {
                    if (isDesc) {
                        if(arr[j] > arr[min_idx]) {
                            min_idx = j;
                        }
                    } else {
                        if(arr[j] < arr[min_idx]) {
                            min_idx = j;
                        }
                    }
                }
                if(min_idx != i) {
                    swap(arr[min_idx], arr[i]);
                }
            }
            end = clock();
            setCpuTimeUsed(((double) (end - start)) / CLOCKS_PER_SEC);
        }
        void printSort(vector<int>&arr) override{
            cout << "Selection Sort" << endl;
            for (int val : arr) {
                cout << val << " ";
            }
            cout << endl;
        }
};