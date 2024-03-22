#include "SortStrategy.h"

class QuickSort : public SortStrategy {
    private:
        void swap(int& a, int& b) {
            int temp = a;
            a = b;
            b = temp;
        }
        int partition(vector<int>&arr, int low, int high) {
            long pivot = arr[high];
            int i = low - 1;
            for(int j = low + 1; j <= high; j++) {
                if(arr[j] <= pivot) {
                    i++;
                    swap(arr[i], arr[j]);
                }
            }
            swap(arr[i+1], arr[high]);
            return i + 1;
        }
    public:
        void quickSort(vector<int>&arr, int low, int high) {
            if(low >= high) {
                return;
            }

            int pivot = partition(arr, low, high);
            quickSort(arr, low, pivot - 1);
            quickSort(arr, pivot + 1, high);
        }
        void sort(vector<int>&arr, int& timeExecution) override {
            auto start = high_resolution_clock::now();
            quickSort(arr, 0, arr.size()-1);
            auto stop = high_resolution_clock::now();
            auto duration = duration_cast<microseconds>(stop - start);
            timeExecution = duration.count();
        }

        void printSort(vector<int>&arr) override {
            cout << "Quick Sort" << endl;
            for (int val : arr) {
                cout << val << " ";
            }
            cout << endl;
        }
};