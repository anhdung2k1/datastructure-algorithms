#include "MergeSort.cpp"
#include "NaturalMergeSort.cpp"
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

    int naturalMergeTimeExecution, mergeTimeExecution, quickTimeExecution;

    shared_ptr<SortContext>context = make_shared<SortContext>();
    shared_ptr<MergeSort>mergeSort = make_shared<MergeSort>();
    shared_ptr<NaturalMergeSort>naturalMergeSort = make_shared<NaturalMergeSort>();
    shared_ptr<QuickSort>quickSort = make_shared<QuickSort>();

    context->setStrategy(naturalMergeSort);
    context->executeSort(arr, naturalMergeTimeExecution);
    context->executePrint(arr);

    context->setStrategy(mergeSort);
    context->executeSort(arr, mergeTimeExecution);
    context->executePrint(arr);

    context->setStrategy(quickSort);
    context->executeSort(arr, quickTimeExecution);
    context->executePrint(arr);

    cout << "Natural Merge Sort Time: " << naturalMergeTimeExecution << " microseconds" << endl;
    cout << "Merge Sort Time: " << mergeTimeExecution << " microseconds" << endl;
    cout << "Quick Sort Time: " << quickTimeExecution << " microseconds" << endl;

    return 0;
}