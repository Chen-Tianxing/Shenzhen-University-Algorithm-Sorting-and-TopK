#include <iostream>
#include <vector>
bool checkSorted(const std::vector<int>&);
void Swap(int& a, int& b) {
    int temp = a;
    a = b, b = temp;
}
double bubbleSort(std::vector<int>& a) {
    int len = a.size(), cnt = 0, *arr = new int[len];
    for(int i=0; i<len; i++) arr[i] = a[i];
    clock_t st = clock();
    while(true) {
        ++cnt;
        bool flag = false; 
        for(int i=0; i<len-cnt; i++) {
            if(arr[i]>arr[i+1]) {
                flag = true, Swap(arr[i], arr[i+1]);
            }
        }
        if(!flag) break;
    }
    clock_t ed = clock();
    for(int i=0; i<len; i++) a[i] = arr[i];
    // if(checkSorted(arr)) puts("bubbleSort Success");
    // else puts("bubbleSort Fail");
    delete[] arr;
    return (double)(ed-st)/CLOCKS_PER_SEC;
}

double insertionSort(std::vector<int>& a) {
    int len = a.size(), *arr = new int[len];
    for(int i=0; i<len; i++) arr[i] = a[i];
    clock_t st = clock();
    for(int i=1; i<len; i++) {
        int temp = arr[i], j;
        for(j=i; j>0; j--) {
            if(arr[j-1]>temp) arr[j] = arr[j-1];
            else break;
        }
        arr[j] = temp;
    }
    clock_t ed = clock();
    for(int i=0; i<len; i++) a[i] = arr[i];
    // if(checkSorted(arr)) puts("insertionSort Success");
    // else puts("insertionSort Fail");
    delete[] arr;
    return (double)(ed-st)/CLOCKS_PER_SEC;
}

void f1(int* arr, const int& l, const int& r) { // mergeSortFunction
    if(r-l<1) return;
    int mid = (r+l)/2, p = l, q = mid+1, resP = 0;
    f1(arr, l, mid), f1(arr, mid+1, r);
    int *temp = new int[r-l+1];
    while(p<=mid&&q<=r) {
        if(arr[p]<arr[q]) temp[resP++] = arr[p++];
        else temp[resP++] = arr[q++];
    }
    if(p<=mid) {
        while(p<=mid) temp[resP++] = arr[p++];
    } else {
        while(q<=r) temp[resP++] = arr[q++];
    }
    for(int i=0; i<r-l+1; i++) arr[l+i] = temp[i];
    delete[] temp;
    return;
}
double mergeSort(std::vector<int>& a) {
    int len = a.size(), *arr = new int[len];
    for(int i=0; i<len; i++) arr[i] = a[i];
    clock_t st = clock();
    f1(arr, 0, len-1);
    clock_t ed = clock();
    for(int i=0; i<len; i++) a[i] = arr[i];
    // if(checkSorted(arr)) puts("mergeSort Success");
    // else puts("mergeSort Fail");
    delete[] arr;
    return (double)(ed-st)/CLOCKS_PER_SEC;
}

void f2(int* arr, const int& low, const int& high) { // quickSortFunction
    int i = low, j = high, key = arr[(low+high)>>1];
    do {
        while(arr[i]<key) ++i;
        while(arr[j]>key) --j;
        if(i<=j) Swap(arr[i++], arr[j--]);
    } while(i<=j);
    if(low < j) f2(arr, low, j);
    if(i < high) f2(arr, i, high);
}
double quickSort(std::vector<int>& a) {
    int len = a.size(), *arr = new int[len];
    for(int i=0; i<len; i++) arr[i] = a[i];
    clock_t st = clock();
    f2(arr, 0, len-1);
    clock_t ed = clock();
    for(int i=0; i<len; i++) a[i] = arr[i];
    // if(checkSorted(arr)) puts("quickSort Success");
    // else puts("quickSort Fail");
    delete[] arr;
    return (double)(ed-st)/CLOCKS_PER_SEC;
}

double selectionSort(std::vector<int>& a) {
    int len = a.size(), *arr = new int[len];
    for(int i=0; i<len; i++) arr[i] = a[i];
    clock_t st = clock();
    for(int i=0; i<len; i++) {
        int minIndex = i, minValue = arr[i];
        for(int j=i+1; j<len; j++) {
            if(arr[j]<minValue) minValue = arr[j], minIndex = j;
        }
        // Swap(arr[i], arr[minIndex]);
        std::swap(arr[i], arr[minIndex]);
    }
    clock_t ed = clock();
    for(int i=0; i<len; i++) a[i] = arr[i];
    // if(checkSorted(arr)) puts("selectionSort Success");
    // else puts("selectionSort Fail");
    delete[] arr;
    return (double)(ed-st)/CLOCKS_PER_SEC;
}

bool checkSorted(const std::vector<int>& arr) {
    int len = arr.size();
    for(int i=1; i<len; i++) 
        if(arr[i]<arr[i-1]) return false;
    return true;
}