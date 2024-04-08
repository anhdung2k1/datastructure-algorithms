#include "MergeSort.cpp"
#include "NaturalMergeSort.cpp"
#include "QuickSort.cpp"
#include "HeapSort.cpp"
#include "InsertionSort.cpp"
#include "SelectionSort.cpp"
#include "ShellSort.cpp"
#include "RadixSort.cpp"

#define SIZE_MAX_INPUT 1000
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

    int naturalMergeTimeExecution, mergeTimeExecution, quickTimeExecution, heapTimeExecution, insertionTimeExecution, selectionTimeExecution, shellTimeExecution, radixSortTimeExecution;

    shared_ptr<SortContext>context = make_shared<SortContext>();
    shared_ptr<MergeSort>mergeSort = make_shared<MergeSort>();
    shared_ptr<NaturalMergeSort>naturalMergeSort = make_shared<NaturalMergeSort>();
    shared_ptr<QuickSort>quickSort = make_shared<QuickSort>();
    shared_ptr<HeapSort>heapSort = make_shared<HeapSort>();
    shared_ptr<InsertionSort>insertionSort = make_shared<InsertionSort>();
    shared_ptr<SelectionSort>selectionSort = make_shared<SelectionSort>();
    shared_ptr<ShellSort>shellSort = make_shared<ShellSort>();
    shared_ptr<RadixSort>radixSort = make_shared<RadixSort>();

    // Natural Sort
    cout << "Natural Sort" << endl;
    context->setStrategy(naturalMergeSort);
    context->executeSort(arr, naturalMergeTimeExecution);
    context->executePrint(arr);

    // Merge Sort
    cout << "Merge Sort" << endl;
    context->setStrategy(mergeSort);
    context->executeSort(arr, mergeTimeExecution);
    context->executePrint(arr);

    // Quick Sort
    cout << "Quick Sort" << endl;
    context->setStrategy(quickSort);
    context->executeSort(arr, quickTimeExecution);
    context->executePrint(arr);

    // Heap Sort
    cout << "Heap Sort" << endl;
    context->setStrategy(heapSort);
    context->executeSort(arr, heapTimeExecution);
    context->executePrint(arr);

    // Insertion Sort
    cout << "Insertion Sort" << endl;
    context->setStrategy(insertionSort);
    context->executeSort(arr, insertionTimeExecution);
    context->executePrint(arr);

    // Selection Sort
    cout << "Selection Sort" << endl;
    context->setStrategy(selectionSort);
    context->executeSort(arr, selectionTimeExecution);
    context->executePrint(arr);

    // Shell Sort
    cout << "Shell Sort" << endl;
    context->setStrategy(shellSort);
    context->executeSort(arr, shellTimeExecution);
    context->executePrint(arr);

    // Radix Sort
    cout << "Radix Sort" << endl;
    context->setStrategy(radixSort);
    context->executeSort(arr, shellTimeExecution);
    context->executePrint(arr);

    cout << "Natural Merge Sort Time: " << naturalMergeTimeExecution << " microseconds" << endl;
    cout << "Merge Sort Time: " << mergeTimeExecution << " microseconds" << endl;
    cout << "Quick Sort Time: " << quickTimeExecution << " microseconds" << endl;
    cout << "Heap Sort Time: " << heapTimeExecution << " microseconds" << endl;
    cout << "Insertion Sort Time: " << insertionTimeExecution << " microseconds" << endl;
    cout << "Selection Sort Time: " << selectionTimeExecution << " microseconds" << endl;
    cout << "Shell Sort Time: " << shellTimeExecution << " microseconds" << endl;
    cout << "Radix Sort Time: " << radixSortTimeExecution << " microseconds" << endl;

    return 0;
}