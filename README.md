### So sánh các thuật toán sắp xếp

| Thuật toán               | Độ phức tạp tốt nhất | Độ phức tạp tệ nhất | Độ phức tạp trung bình | Độ phức tạp không gian | Ổn định | Nội tại |
|--------------------------|----------------------|---------------------|------------------------|------------------------|---------|---------|
| Selection Sort           | O(n^2)               | O(n^2)              | O(n^2)                 | O(1)                   | Không   | Có      |
| Insertion Sort           | O(n)                 | O(n^2)              | O(n^2)                 | O(1)                   | Có      | Có      |
| Interchange Sort         | O(n^2)               | O(n^2)              | O(n^2)                 | O(1)                   | Không   | Có      |
| Bubble Sort              | O(n)                 | O(n^2)              | O(n^2)                 | O(1)                   | Có      | Có      |
| Shaker Sort              | O(n)                 | O(n^2)              | O(n^2)                 | O(1)                   | Có      | Có      |
| Binary Insertion Sort    | O(n)                 | O(n^2)              | O(n^2)                 | O(1)                   | Có      | Có      |
| Shell Sort               | O(n log n)           | O(n^(3/2))          | O(n log n)             | O(1)                   | Không   | Có      |
| Heap Sort                | O(n log n)           | O(n log n)          | O(n log n)             | O(1)                   | Không   | Có      |
| Quick Sort               | O(n log n)           | O(n^2)              | O(n log n)             | O(log n)               | Không   | Có      |
| Merge Sort               | O(n log n)           | O(n log n)          | O(n log n)             | O(n)                   | Có      | Không   |
| Radix Sort               | O(nk)                | O(nk)               | O(nk)                  | O(n + k)               | Có      | Có      |

### So sánh ưu điểm và khuyết điểm của các thuật toán

#### Selection Sort
- **Ưu điểm:** Dễ cài đặt và hiểu.
- **Khuyết điểm:** Không hiệu quả với danh sách lớn, độ phức tạp thời gian luôn là O(n^2).

```
void SelectionSort(int a[],int n )
{
	int min; // chỉ số phần tử nhỏ nhất trong dãy hiện hành
	for (int  i=0; i<n-1 ; i++)
	{  
		min = i; 
		for(int j = i+1; j < n ; j++)
	   	  if (a[j] < a[min])
		   min = j; // ghi nhận vị trí phần tử nhỏ nhất
		if (min != i)
	   	   swap(a[min], a[i]);
	}
}
```
<img src="screenshots/selection_sort.png" width="550"/>

#### Insertion Sort
- **Ưu điểm:** Hiệu quả với danh sách nhỏ hoặc gần như đã sắp xếp, ổn định.
- **Khuyết điểm:** Độ phức tạp thời gian tệ nhất là O(n^2).

```
void InsertionSort(int a[], int n )
{	
    int pos, x;
	for(int i=1 ; i<n ; i++) //đoạn a[0] đã sắp
	{	x = a[i];pos=	i-1;
		while(pos>=0 && a[pos]>x)
		{	a[pos+1] = a[pos];
			pos--;
		}
		a[pos+1]=x;
	}
}
```
<img src="screenshots/insertion_sort.png" width="550"/>


#### Interchange Sort
- **Ưu điểm:** Dễ hiểu và cài đặt.
- **Khuyết điểm:** Không hiệu quả với danh sách lớn, không ổn định, độ phức tạp thời gian là O(n^2).

```
void InterchangeSort(int a[], int n)
{	
	int  i, j;
	for (i = 0 ; i<n-1 ; i++)
		for (j =i+1; j < n ; j++)
		   if(a[j]< a[i]) //nếu có nghịch thế thì đổi chỗ
			swap(a[i],a[j]);
}
```
<img src="screenshots/interchange_sort.png" width="550"/>

#### Bubble Sort
- **Ưu điểm:** Dễ hiểu và cài đặt, ổn định.
- **Khuyết điểm:** Không hiệu quả với danh sách lớn, độ phức tạp thời gian là O(n^2).

```
void BubbleSort(int a[], int n)
{	
	int i, j;
	for (i = 0 ; i<n-1 ; i++) {
		for (j =n-1; j>i ; j --) {
		    if(a[j]< a[j-1])	{
                swap(a[j], a[j-1]);
            }
        }
    }
}
```
<img src="screenshots/bubble_sort.png" width="550"/>

#### Shaker Sort
- **Ưu điểm:** Cải thiện so với Bubble Sort khi có thể phát hiện sắp xếp trong mỗi lần lặp từ hai phía.
- **Khuyết điểm:** Độ phức tạp thời gian là O(n^2).
```
void ShakerSort(int a[], int n) {
    int left = 0;
    int right = n - 1;
    int k = 0;
    while (left < right) {
        for (int i = left; i < right; i++) {
            if (a[i] > a[i + 1]) {
                swap(a[i], a[i + 1]);
                k = i;
            }
        }
        right = k;
        for (int i = right; i > left; i--) {
            if (a[i] < a[i - 1]) {
                swap(a[i], a[i - 1]);
                k = i;
            }
        }
        left = k;
    }
}
```
<img src="screenshots/shaker_sort.png" width="550"/>

#### Binary Insertion Sort
- **Ưu điểm:** Tìm kiếm nhị phân để chèn làm giảm số lần so sánh.
- **Khuyết điểm:** Không giảm số lần di chuyển phần tử, độ phức tạp thời gian là O(n^2).

```
void BinaryInsertionSort(int a[], int n) {
    for (int i = 1; i < n; i++) {
        int x = a[i];
        int left = 0;
        int right = i - 1;
        while (left <= right) {
            int mid = (left + right) / 2;
            if (x < a[mid]) {
                right = mid - 1;
            } else {
                left = mid + 1;
            }
        }
        for (int j = i - 1; j >= left; j--) {
            a[j + 1] = a[j];
        }
        a[left] = x;
    }
}
```
<img src="screenshots/binary_insertion_sort.png" width="550"/>

#### Shell Sort
- **Ưu điểm:** Hiệu quả với danh sách lớn hơn so với Insertion Sort, cải thiện độ phức tạp thời gian.
- **Khuyết điểm:** Không ổn định, phức tạp trong việc lựa chọn khoảng cách nhảy.

```
void ShellSort(int a[], int n) {
    for (int gap = n / 2; gap > 0; gap /= 2) {
        for (int i = gap; i < n; i++) {
            int temp = a[i];
            int j;
            for (j = i; j >= gap && a[j - gap] > temp; j -= gap) {
                a[j] = a[j - gap];
            }
            a[j] = temp;
        }
    }
}
```

<img src="screenshots/shell_sort.png" width="550"/>

#### Heap Sort
- **Ưu điểm:** Độ phức tạp thời gian là O(nlogn), không bị ảnh hưởng bởi dữ liệu đầu vào.
- **Khuyết điểm:** Không ổn định, phức tạp hơn so với các thuật toán sắp xếp khác.

```
void Heapify(int a[], int n, int i) {
    int largest = i;
    int left = 2 * i + 1;
    int right = 2 * i + 2;

    if (left < n && a[left] > a[largest]) {
        largest = left;
    }

    if (right < n && a[right] > a[largest]) {
        largest = right;
    }

    if (largest != i) {
        swap(a[i], a[largest]);
        Heapify(a, n, largest);
    }
}

void HeapSort(int a[], int n) {
    for (int i = n / 2 - 1; i >= 0; i--) {
        Heapify(a, n, i);
    }

    for (int i = n - 1; i > 0; i--) {
        swap(a[0], a[i]);
        Heapify(a, i, 0);
    }
}
```

<img src="screenshots/heap_sort.png" width="550"/>

#### Quick Sort
- **Ưu điểm:** Rất nhanh với độ phức tạp trung bình là O(nlogn), phổ biến.
- **Khuyết điểm:** Không ổn định, độ phức tạp tệ nhất là O(n^2).

```
void QuickSort(int a[], int left, int right)
{ 	
	int i, j, x;
	if (left < right)	return;
  	x = a[(left+right)/2]; // chọn phần tử giữa làm giá trị mốc
  	i = left; j = right;
  	do{
     	 while(a[i] < x) i++;
     	 while(a[j] > x) j--;
     	 if(i <= j) { 
		  Swap(a[i], a[j]);
       	  i++ ; j--;
	 	 }
	       } while(i < j) ;
	   if(left<j) QuickSort(a, left, j);
	   if(i<right) QuickSort(a, i, right);
}
```
<img src="screenshots/quick_sort.png" width="550"/>

#### Merge Sort
- **Ưu điểm:** Ổn định, độ phức tạp thời gian là O(n log n), hiệu quả với dữ liệu lớn.
- **Khuyết điểm:** Không nội tại, cần không gian thêm O(n).

```
void MergeSort(int a[], int n) {
   int b[MAX];
   int c[MAX];
   int p, pb, pc; //các chỉ số trên các mảng a, b, c
   int i, k = 1;  //độ dài của dãy con khi phân hoạch
   do {
     Distribute(a, n, pb, pc, k, b, c);
     Merge(a, pb, pc, k, b, c);
     k *= 2;
   } while (k < n);
}

void Distribute(int a[], int n, int &pb, int &pc, 
                int k, int b[], int c[]) {
  int i, p;
  // tách a thành b và c
  p = pb = pc = 0;
  while (p < n) {
    for (i = 0; (p < n) && (i < k); i++)
       b[pb++] = a[p++];
    for (i = 0; (p < n) && (i < k); i++)
       c[pc++] = a[p++];
  }
}

void Merge(int a[], int nb, int nc, int k, int b[], int c[]) {
  int p, pb, pc, ib, ic, kb, kc;
  p = pb = pc = 0;
  ib = ic = 0;
  while ((0 < nb) && (0 < nc)) {
     kb = min(k, nb); kc = min(k, nc);
     if (b[pb + ib] <= c[pc + ic]) {
        a[p++] = b[pb + ib];
        ib++;
        if (ib == kb) {
           for (; ic < kc; ic++)
               a[p++] = c[pc + ic];
           pb += kb; pc += kc;
           ib = ic = 0;
           nb -= kb; nc -= kc;
        }
     }
    else {
        a[p++] = c[pc + ic];
        ic++;
        if (ic == kc) {
           for (; ib < kb; ib++)
              a[p++] = b[pb + ib];
           pb += kb; pc += kc;
           ib = ic = 0;
           nb -= kb; nc -= kc;
        }
    }
  }
}
```

<img src="screenshots/merge_sort.png" width="550"/>

#### Radix Sort
- **Ưu điểm:** Rất nhanh với độ phức tạp thời gian O(nk), ổn định.
- **Khuyết điểm:** Chỉ áp dụng cho các số nguyên, cần không gian thêm O(n + k).

```
// Hàm lấy giá trị lớn nhất trong mảng
int getMax(int a[], int n) {
    int max = a[0];
    for (int i = 1; i < n; i++)
        if (a[i] > max)
            max = a[i];
    return max;
}

// Hàm đếm số lượng chữ số và phân loại các phần tử
void countSort(int a[], int n, int exp) {
    int output[n];
    int i, count[10] = {0};

    // Đếm số lần xuất hiện của mỗi chữ số
    for (i = 0; i < n; i++)
        count[(a[i] / exp) % 10]++;

    // Thay đổi count[i] sao cho count[i] chứa vị trí của chữ số trong output[]
    for (i = 1; i < 10; i++)
        count[i] += count[i - 1];

    // Xây dựng output[]
    for (i = n - 1; i >= 0; i--) {
        output[count[(a[i] / exp) % 10] - 1] = a[i];
        count[(a[i] / exp) % 10]--;
    }

    // Sao chép output[] vào a[], để a[] chứa các số đã sắp xếp theo chữ số hiện tại
    for (i = 0; i < n; i++)
        a[i] = output[i];
}

// Hàm chính của Radix Sort
void RadixSort(int a[], int n) {
    int m = getMax(a, n);

    // Thực hiện đếm và phân loại cho mỗi chữ số
    for (int exp = 1; m / exp > 0; exp *= 10)
        countSort(a, n, exp);
}
```

<img src="screenshots/radix_sort.png" width="550"/>