#include "SortStrategy.h"

class InsertionSort : public SortStrategy {
    public:
        void sort(vector<int>&arr) {
            int key;
            for (int i = 1; i < arr.size(); i++) {
                key = arr[i];
                int j = i - 1;
                if(isDesc) {
                    while (j >= 0 && arr[j] < key) {
                        arr[j + 1] = arr[j];
                        j = j - 1;
                    }
                } else {
                    while (j >= 0 && arr[j] > key) {
                        arr[j + 1] = arr[j];
                        j = j - 1;
                    }
                }
                
                arr[j + 1] = key;
            }
        }
        
        void printSort(vector<int>&arr) override {
            cout << "Insertion Sort" << endl;
            for(int val : arr) {
                cout << val << " ";
            }
            cout << endl;
        }
};