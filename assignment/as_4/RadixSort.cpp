#include "SortStrategy.h"

class RadixSort : public SortStrategy {
    private:
        int getMax(vector<int>&arr) {
            int maxVal = arr[0];
            for (int val : arr)
                maxVal = max(maxVal, val);
            return maxVal;
        }

        void countSort(vector<int>&arr, int expo) {
            vector<int>output(arr.size());
            int count[10] = { 0 };

            for (int i = 0; i < arr.size(); i++) {
                count[(arr[i] / expo) % 10]++;
            }

            for (int i = 1; i < 10; i++) {
                count[i] += count[i - 1];
            }

            for (int i = arr.size() - 1; i >= 0; i--) {
                output[count[(arr[i] / expo) % 10]] = arr[i];
                count[(arr[i] / expo) % 10]--;
            }

            for (int i = 0;i < arr.size(); i++) {
                arr[i] = output[i];
            }
        } 
    public:
        void sort(vector<int>& arr, int& timeExecution) override {
            auto start = high_resolution_clock::now();
            int max = getMax(arr);
            int expo = 1;
            while (max / expo > 0) {
                countSort(arr, expo);
                expo *= 10;
            }
            auto stop = high_resolution_clock::now();
            auto duration = duration_cast<microseconds>(stop - start);
            timeExecution = duration.count();
        }
        void printSort(vector<int>&arr) override {
            cout << "Radix Sort" << endl;
            for (int val : arr) {
                cout << val << " ";
            }
            cout << endl;
        }
};