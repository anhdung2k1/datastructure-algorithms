#include <iostream>
#include <vector>
using namespace std;

struct MaHang{
    unsigned int ID;
    unsigned int soluong;
    unsigned int dongia;

    MaHang() {
        ID = 0;
        soluong = 0;
        dongia = 0;
    }

    MaHang(unsigned int id, unsigned int sl, unsigned int dg) {
        ID = id;
        soluong = sl;
        dongia = dg;
    }
}; 

void printMaHang(MaHang mh) {
    printf("ID: %u, Số lượng: %u, Đơn giá: %u\n", mh.ID, mh.soluong, mh.dongia);
}

void printMaHangArr(vector<MaHang>&arr) {
    for (int i = 0; i < arr.size(); i++) {
        printMaHang(arr[i]);
    }
}

void swap(MaHang& a, MaHang& b) {
    MaHang temp = a;
    a = b;
    b = temp;
}

// Hàm partition với pivot là phần tử đầu
int partitionHead(vector<MaHang>&arr, int low, int high) {
    MaHang pivot = arr[low];
    int i = low;
    for (int j = low + 1; j <= high; j++) {
        if (arr[j].dongia <= pivot.dongia) {
            i++;
            swap(arr[i], arr[j]);
        }
    }
    swap(arr[low], arr[i]);
    return i;
}

// Quick Sort với phần tử gốc là phần tử đầu tiên
void quickSortHead(vector<MaHang>&arr, int low, int high) {
    if (low < high) {
        int pivotIndex = partitionHead(arr, low, high);

        quickSortHead(arr, low, pivotIndex - 1);
        quickSortHead(arr, pivotIndex + 1, high);
    }
}

int partitionMid(vector<MaHang>&arr, int low, int high) {
    int mid = low + (high - low) / 2;
    MaHang pivot = arr[mid];
    swap(arr[mid], arr[high]);
    int i = low - 1;
    for (int j = low; j < high; j++) {
        if (arr[j].dongia <= pivot.dongia) {
            i++;
            swap(arr[i], arr[j]);
        }
    }
    swap(arr[i + 1], arr[high]);
    return i + 1;
}

// phan tu goc ơ giữa
void quickSortMid(vector<MaHang>&arr, int low, int high) {
    if(low >= high) {
        return;
    }

    int pivot = partitionMid(arr, low, high);
    quickSortMid(arr, low, pivot - 1);
    quickSortMid(arr, pivot + 1, high);
}

// Radix Sort
MaHang getMax(vector<MaHang>& arr) {
    MaHang mx = arr[0];
    for(int i = 1;i < arr.size();i++) {
        if (mx.ID < arr[i].ID) {
            mx = arr[i];
        }
    }
    return mx;
}

void countSort(vector<MaHang>& arr, int exp) {
    vector<MaHang>result(arr.size());
    int count[10] = {0};

    for(int i = 0;i < arr.size();i++) {
        count[(arr[i].ID / exp) % 10]++;
    }
    for(int i = 1;i < 10;i++) {
        count[i] += count[i - 1];
    }
    for(int i = arr.size() - 1; i >= 0; i--) {
        result[count[(arr[i].ID / exp) % 10] - 1] = arr[i];
        count[(arr[i].ID / exp) % 10]--;
    }
    for(int i = 0; i < arr.size();i++) {
        arr[i] = result[i];
    }
}

void radixSort(vector<MaHang>& arr) {
    MaHang mx = getMax(arr);
    for(int exp = 1; mx.ID / exp > 0; exp *= 10) {
        countSort(arr, exp);
    }
}


int main() {
    vector<MaHang>mh;
    mh.push_back(MaHang(7, 1000, 100000));
    mh.push_back(MaHang(1, 2000, 200000));
    mh.push_back(MaHang(2, 30000, 3200000));
    mh.push_back(MaHang(9, 1320, 3600000));
    mh.push_back(MaHang(3, 2001, 563000));

    // Sắp xếp với quickSortHead theo đơn giá
    cout << "Quick Sort Head \n";
    quickSortHead(mh, 0, mh.size() - 1);
    printMaHangArr(mh);

    // Sắp xếp với quickSortMid theo đơn giá
    cout << "Quick Sort Mid\n";
    quickSortMid(mh, 0, mh.size() - 1);
    printMaHangArr(mh);

    // Radix Sort tăng dần theo ID
    cout << "Radix Sort ascending according to ID\n";
    radixSort(mh);
    printMaHangArr(mh);
    return 0;
}