#include "SortContext.cpp"

class Main {
    private:
        bool isDesc = true;
        int timeExecution;
        shared_ptr<SortContext> context = make_shared<SortContext>();
        shared_ptr<MergeSort> mergeSort = make_shared<MergeSort>();
        shared_ptr<InsertionSort> insertionSort = make_shared<InsertionSort>();
        shared_ptr<SelectionSort> selectionSort = make_shared<SelectionSort>();

        vector<int> findValue(vector<int>&arr, int k) {
            vector<int>indexArr;
            for(int i = 0; i < arr.size(); i++) {
                if(arr[i] == k) {
                    indexArr.push_back(i);
                }
            }
            if(indexArr.size() == 0) {
                cout << "Not found any value matched\n";
            }
            return indexArr;
        }

        vector<string> splitString(string input) {
            istringstream iss(input);
            vector<string> result;
            string token;
            
            while (getline(iss, token, ' ')) {
                result.push_back(token);
            }
            
            return result;
        }

        vector<int> convertStringTextToIntArr(string fileName) {
            ifstream file(fileName);
            string output;
            vector<string> stringArr;
            vector<int> arr;
            while(getline(file, output)) {
                stringArr = splitString(output);
            }
            for(auto val : stringArr) {
                arr.push_back(stoi(val));
            }
            return arr;
        }
        
        vector<int> binarySearch(vector<int>&arr, int target) {
            int left = 0;
            int right = arr.size() - 1;
            vector<int> findIdxArr;
            while(left <= right) {
                int mid = left + (right - left) / 2;
                if(arr[mid] == target) {
                    findIdxArr.push_back(mid);
                    int leftIndex = mid - 1;
                    while(leftIndex >= 0 && arr[leftIndex] == target) {
                        findIdxArr.push_back(leftIndex);
                        leftIndex--;
                    }
                    int rightIndex = mid + 1;
                    while(rightIndex < arr.size() && arr[rightIndex] == target) {
                        findIdxArr.push_back(rightIndex);
                        rightIndex++;
                    }
                    break;
                }
                if(arr[mid] > target) {
                    right = mid - 1;
                }
                else {
                    left = mid + 1;
                }
            }
            if (findIdxArr.size() == 0) {
                cout << "Not found any value matched\n";
            }
            return findIdxArr;
        }

        vector<int> splittedArr(vector<int>&arr) {
            vector<int> leftArr;
            vector<int> rightArr;
            for(int val : arr) {
                if(val % 2 == 0) {
                    leftArr.push_back(val); // Push the event val to left Arr
                } else {
                    rightArr.push_back(val); // Push the odd val to right Arr
                }
            }
            context->setStrategy(insertionSort);
            context->setIsDescending(!isDesc);
            // Sort left even array to ascending
            context->executeSort(leftArr);
            // Sort right odd array to descending
            context->setIsDescending(isDesc);
            context->executeSort(rightArr);
            arr.clear();
            for(int leftVal : leftArr) {
                arr.push_back(leftVal);
            }
            for(int rightVal : rightArr) {
                arr.push_back(rightVal);
            }
            return arr;
        }
    public:
        // Exec 1
        void solvProb1(int n, string fileName) {
            ofstream file(fileName);
            while(1) {
                if (n >= 2 && n <= 1000) {
                    file << n << endl;;
                    for (int i = 0; i < n; i++) {
                        file << rand() % n << " ";
                    }
                    file.close();
                    break;
                }
            }
        }

        // Exec 2
        void solvProb2(int n, string fileName) {
            vector<int> arr = convertStringTextToIntArr(fileName);
            int k;
            cout << "Enter value need to find: ";
            cin >> k;
            vector<int>findedVal = findValue(arr, k);
            if(findedVal.size() > 0) {
                cout << "Found all the value index in array\n";
                cout << "Index: ";
                for(int finded : findedVal) {
                    cout << finded << " ";
                }
                cout << endl;
            }
        }
        // Exec 3
        void solvProb3(string fileName) {
            vector<int> arr = convertStringTextToIntArr(fileName);
            // Sort all array

            context->setStrategy(insertionSort);
            // Sort Ascending
            context->setIsDescending(!isDesc);
            context->executeSort(arr);
            context->executePrint(arr);
            cout << endl;
            int k;
            cout << "Enter value need to find: ";
            cin >> k;
            vector<int> findedVal = binarySearch(arr, k);
            if(findedVal.size() > 0) {
                cout << "Found all the value index in array\n";
                cout << "Index: ";
                for(int finded : findedVal) {
                    cout << finded << " ";
                }
                cout << endl;
            }
        }
        // Exec 4, 5
        void solvProb4_5(string fileName) {
            vector<int> arr = convertStringTextToIntArr(fileName);
            vector<int> splitted = splittedArr(arr);
            double mergeSortTimeExecution, selectionSortTimeExecution;
    
            cout << "Splitted array to even left ascending and odd right descending\n";
            for(auto x : splitted) {
                cout << x << " ";
            }
            cout << endl;
            cout << "Sort ascending by merge Sort\n";
            context->setStrategy(mergeSort);
            context->setIsDescending(!isDesc);
            context->executeSort(splitted);
            context->executePrint(splitted);
            mergeSortTimeExecution = context->getCpuTimeUsed();

            cout << "Sort Descending by Selection Sort\n";
            context->setStrategy(selectionSort);
            context->setIsDescending(isDesc);
            context->executeSort(splitted);
            context->executePrint(splitted);
            selectionSortTimeExecution = context->getCpuTimeUsed();

            cout << "Merge Sort Time Execution: " << mergeSortTimeExecution << endl;
            cout << "Selection Sort Time Execution: " << selectionSortTimeExecution << endl;
            cout << "Time Execution Bias: " << abs(mergeSortTimeExecution - selectionSortTimeExecution) << endl;
        }
};

int main() {
    int n;
    cout << "Enter size of arr: ";
    cin >> n;
    Main* main = new Main();
    string fileName = "songuyen.txt";
    // Ex 1
    main->solvProb1(n, fileName);
    // Ex 2
    main->solvProb2(n, fileName);
    // Ex 3
    main->solvProb3(fileName);
    // Ex 4
    main->solvProb4_5(fileName);
    return 0;
}