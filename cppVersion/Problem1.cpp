#include<iostream>
#include<ctime>
#include<fstream>
#include"SortingAlgorithm.h"
using namespace std;
int main() {
    freopen("../Input/ProblemOneInput.txt","r",stdin);
    double time = 0;
    string check = "Fail";
    cin >> check;
    cout << check << endl;
    for(int cntTime=1; cntTime<=20; cntTime++) {
        int len = 0;
        vector<int> arr;
        cin >> len;
        for(int i=0, temp; i<len; i++) {
            scanf("%d", &temp);
            arr.push_back(temp);
        }
        clock_t startTime, endTime;
        startTime = clock();
        // -------------
        bubbleSort(arr);
        // insertionSort(arr);
        // selectionSort(arr);
        // quickSort(arr);
        // mergeSort(arr);
        // -------------
        endTime = clock();
        time += (endTime-startTime)/1000000.0;
        cout << time/cntTime << endl;
    }
    cout << "Average: " << time/20 << "s";
    return 0;
}