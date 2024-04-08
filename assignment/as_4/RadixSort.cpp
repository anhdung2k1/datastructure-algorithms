#include "SortStrategy.h"

class RadixSort : public SortStrategy {
    private:
        int getMax(vector<int>& arr) {
            int mx = arr[0];
            for(int i = 1;i < arr.size();i++) {
                mx = max(arr[i], mx);
            }
            return mx;
        }
        void countSort(vector<int>& arr, int exp) {
            int result[arr.size()];
            int count[10] = {0};

            for(int i = 0;i < arr.size();i++) {
                count[(arr[i] / exp) % 10]++;
            }
            for(int i = 1;i < 10;i++) {
                count[i] += count[i - 1];
            }
            for(int i = arr.size() - 1; i >= 0; i--) {
                result[count[(arr[i] / exp) % 10] - 1] = arr[i];
                count[(arr[i] / exp) % 10]--;
            }
            for(int i = 0; i < arr.size();i++) {
                arr[i] = result[i];
            }
        }
    public:
        void sort(vector<int>&arr, int& timeExecution) override {
            auto start = high_resolution_clock::now();
            int mx = getMax(arr);
            for(int exp = 1; mx / exp > 0; exp *= 10) {
                countSort(arr, exp);
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