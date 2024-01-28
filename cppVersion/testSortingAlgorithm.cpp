#include<iostream>
#include"SortingAlgorithm.h"
using namespace std;
int main() {
    freopen("../Input/ProblemOneInput.txt", "r", stdin);
    string check = "Fail";
    cin >> check;
    cout << check << endl;
    int len = 0;
    vector<int> arr;
    cin >> len;
    for(int i=0, x; i<len; i++) {
        cin >> x;
        arr.push_back(x);
    }
    mergeSort(arr);
    bubbleSort(arr);
    insertionSort(arr);
    selectionSort(arr);
    quickSort(arr);
    return 0;
}