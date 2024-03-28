#include <iostream>
#include <vector>
using namespace std;

void swap(int& a, int& b) {
    int temp = a;
    a = b;
    b = temp;
}

void heapify(vector<int>&arr, int n, int i) {
    // Init Smallest as root
    int smallest = i;
    int left = 2 * i + 1; // left = 2*i + 1
    int right = 2 * i + 2; // right = 2*i + 2

    // if left child is smaller than root
    if (left < n && arr[left] < arr[smallest]) {
        smallest = left;
    }

    // if right child is smaller than smallest
    if (right < n && arr[right] < arr[smallest]) {
        smallest = right;
    }

    // if smallest is not root
    if (smallest != i) {
        swap(arr[i], arr[smallest]);
        // Recursive heapify the affected sub-tree
        heapify(arr, n, smallest);
    }
}

void heapSort(vector<int>&arr, int n) {
    // Build heap (rearrange array)
    for (int i = n / 2 - 1; i >= 0; i--) {
        heapify(arr, n, i);
    }

    // One by one extract an element from heap
    for (int i = n - 1; i >= 0; i--) {
        // Move current root to end
        swap(arr[0], arr[i]);
        // call max heapify on the reduced heap
        heapify(arr, i, 0);
    }
}

void printArray(vector<int>&arr, int n) {
    for (int i = 0; i < n; i++) {
        cout << arr[i] << " ";
    }
    cout << endl;
}
int main() {
    vector<int>arr = {9, 7, 6, 9, 8, 6, 7};
    cout << "Array before Sort" << endl;
    printArray(arr, arr.size());
    // Call Heap sort
    heapSort(arr, arr.size());
    cout << "Array after Sort" << endl;
    printArray(arr, arr.size());
    return 0;
}