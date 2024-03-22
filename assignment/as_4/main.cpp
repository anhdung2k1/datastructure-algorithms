#include "MergeSort.cpp"
#include "RadixSort.cpp"
#include "QuickSort.cpp"

#define SIZE_MAX_INPUT 1000000
using namespace std;

class SortContext {
    private:
        shared_ptr<SortStrategy> strategy;
    public:
        void setStrategy(shared_ptr<SortStrategy> strategy) {
            this->strategy = strategy;
        }
        void executeSort(vector<int>& arr, int& timeExecution) {
            strategy->sort(arr, timeExecution);
        }
        void executePrint(vector<int>& arr) {
            strategy->printSort(arr);          
        }
};

void generateInput(vector<int>& arr) {
    srand(time(NULL));
    for (int i = 0; i < SIZE_MAX_INPUT; i++) {
        arr.push_back(rand() % SIZE_MAX_INPUT); //Generate random number from 0 to 1000000
    }
}

int main() {
    vector<int> arr;
    generateInput(arr);

    int radixTimeExecution, mergeTimeExecution, quickTimeExecution;

    shared_ptr<SortContext>context = make_shared<SortContext>();
    shared_ptr<MergeSort>mergeSort = make_shared<MergeSort>();
    shared_ptr<RadixSort>radixSort = make_shared<RadixSort>();
    shared_ptr<QuickSort>quickSort = make_shared<QuickSort>();

    context->setStrategy(radixSort);
    context->executeSort(arr, radixTimeExecution);
    context->executePrint(arr);

    context->setStrategy(mergeSort);
    context->executeSort(arr, mergeTimeExecution);
    context->executePrint(arr);

    context->setStrategy(quickSort);
    context->executeSort(arr, quickTimeExecution);
    context->executePrint(arr);

    cout << "Radix Sort Time: " << radixTimeExecution << " microseconds" << endl;
    cout << "Merge Sort Time: " << mergeTimeExecution << " microseconds" << endl;
    cout << "Quick Sort Time: " << quickTimeExecution << " microseconds" << endl;

    return 0;
}