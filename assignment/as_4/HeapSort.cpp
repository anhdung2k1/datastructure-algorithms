#include "SortStrategy.h"

class HeapSort : public SortStrategy {
    private:
        void heapify(vector<int>&arr, int i) {
            int largest = i;
            int l = 2 * i + 1;
            int r = 2 * i + 2;
            if (l < arr.size() && arr[l] > arr[largest])
                largest = l;
            if (r < arr.size() && arr[r] > arr[largest])
                largest = r;
            if (largest != i) {
                swap(arr[i], arr[largest]);
                heapify(arr, largest);
            }
        }
    public:
        void sort(vector<int>&arr, int& timeExecution) {
            auto start = high_resolution_clock::now();
            for(int i = arr.size() / 2 - 1; i >= 0; i--)
                heapify(arr, i);
            for(int i = arr.size() - 1; i > 0; i--) {
                swap(arr[0], arr[i]);
                heapify(arr, 0);
            }
            auto stop = high_resolution_clock::now();
            auto duration = duration_cast<microseconds>(stop - start);
            timeExecution = duration.count();
        }
        void printSort(vector<int>&arr) override {
            cout << "Heap Sort" << endl;
            for(int val : arr) {
                cout << val << " ";
            }
            cout << endl;
        }
};