#include "SortStrategy.h"

class NaturalMergeSort : public SortStrategy {
    private:
        void merge(vector<int>& arr, int start, int mid, int end) {
            int leftSize = mid - start + 1;
            int rightSize = end - mid;

            vector<int> left(leftSize);
            vector<int> right(rightSize);

            for (int i = 0; i < leftSize; ++i)
                left[i] = arr[start + i];
            for (int j = 0; j < rightSize; ++j)
                right[j] = arr[mid + 1 + j];

            int i = 0, j = 0, k = start;
            while (i < leftSize && j < rightSize) {
                if (left[i] <= right[j]) {
                    arr[k] = left[i];
                    ++i;
                } else {
                    arr[k] = right[j];
                    ++j;
                }
                ++k;
            }

            while (i < leftSize) {
                arr[k] = left[i];
                ++i;
                ++k;
            }

            while (j < rightSize) {
                arr[k] = right[j];
                ++j;
                ++k;
            }
        }

        void naturalMergeSort(vector<int>& arr, int start, int end) {
            if (start < end) {
                int mid = start + (end - start) / 2;

                naturalMergeSort(arr, start, mid);
                naturalMergeSort(arr, mid + 1, end);
                merge(arr, start, mid, end);
            }
        }
    public:
        void sort(vector<int>& arr, int& timeExecution) override {
            auto start = high_resolution_clock::now();
            naturalMergeSort(arr, 0, arr.size() - 1);
            auto stop = high_resolution_clock::now();
            auto duration = duration_cast<microseconds>(stop - start);
            timeExecution = duration.count();
        }
        void printSort(vector<int>&arr) override {
            cout << "Natural Merge Sort" << endl;
            for (int val : arr) {
                cout << val << " ";
            }
            cout << endl;
        }
};