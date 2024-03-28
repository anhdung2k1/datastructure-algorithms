#include "SortStrategy.h"

class MergeSort : public SortStrategy {
    private:
        void merge(vector<int>& arr, int left, int mid, int right) {
            int subArrayOne = mid - left + 1;
            int subArrayTwo = right - mid;

            int* leftArray = new int[subArrayOne];
            int* rightArray = new int[subArrayTwo];

            //Copy array to temp
            for (int i = 0; i < subArrayOne; i++) {
                leftArray[i] = arr[left + i];
            }

            for (int j = 0; j < subArrayTwo; j++) {
                rightArray[j] = arr[mid + 1 + j];
            }

            int indexSubArrayOne = 0, indexSubArrayTwo = 0;
            int indexArray = left;

            while(indexSubArrayOne < subArrayOne && indexSubArrayTwo < subArrayTwo) { 
                if (isDesc) {
                    if (leftArray[indexSubArrayOne] >= rightArray[indexSubArrayTwo]) {
                        arr[indexArray] = leftArray[indexSubArrayOne];
                        indexSubArrayOne++;
                    } else {
                        arr[indexArray] = rightArray[indexSubArrayTwo];
                        indexSubArrayTwo++;
                    }
                } else {
                    if (leftArray[indexSubArrayOne] <= rightArray[indexSubArrayTwo]) {
                        arr[indexArray] = leftArray[indexSubArrayOne];
                        indexSubArrayOne++;
                    } else {
                        arr[indexArray] = rightArray[indexSubArrayTwo];
                        indexSubArrayTwo++;
                    }
                }
                indexArray++;
            }

            for (int i = indexSubArrayOne; i < subArrayOne; i++) {
                arr[indexArray] = leftArray[i];
                indexArray++;
            }

            for (int i = indexSubArrayTwo; i < subArrayTwo; i++) {
                arr[indexArray] = rightArray[i];
                indexArray++;
            }
        }

        void mergeSort(vector<int>& arr, int begin, int end) {
            if (begin < end) {
                int mid = (begin + end) / 2;
                mergeSort(arr, begin, mid);
                mergeSort(arr, mid + 1, end);
                merge(arr, begin, mid, end);
            }
        }
    public:
        void sort(vector<int>& arr) override {
            start = clock();
            mergeSort(arr, 0, arr.size() - 1);
            end = clock();
            setCpuTimeUsed(((double) (end - start)) / CLOCKS_PER_SEC);
        }
        void printSort(vector<int>& arr) override {
            cout << "Merge Sort" << endl;
            for (int val : arr) {
                cout << val << " ";
            }
            cout << endl;
        }
};