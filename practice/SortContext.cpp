#include "MergeSort.cpp"
#include "InsertionSort.cpp"
#include "SelectionSort.cpp"

class SortContext {
    private:
        shared_ptr<SortStrategy> strategy;
    public:
        double getCpuTimeUsed() {
            return strategy->getCpuTimeUsed();
        }

        bool isDescending() {
            return strategy->isDesc;
        }

        void setIsDescending(bool isDesc) {
            strategy->isDesc = isDesc;
        }
    
        void setStrategy(shared_ptr<SortStrategy> strategy) {
            this->strategy = strategy;
        }
        
        void executeSort(vector<int>&arr) {
            strategy->sort(arr);
        }
        
        void executePrint(vector<int>&arr) {
            strategy->printSort(arr);
        }
};