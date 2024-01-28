#include<iostream>
#include<ctime>
#include<fstream>
#include"SortingAlgorithm.h"
using namespace std;
int main() {
    freopen("../Input/testMergeSort.txt","r",stdin);
    double time = 0;
    string check = "Fail";
    cin >> check;
    cout << check << endl;
    for(int cntTime=1; cntTime<=20; cntTime++) {
        int len = 0;
        vector<int> arr;
        cin >> len;
        cout << cntTime << " " << len << " ";
        for(int i=0, temp; i<len; i++) {
            scanf("%d", &temp);
            arr.push_back(temp);
        }
        clock_t startTime, endTime;
        startTime = clock();
        mergeSort(arr);
        endTime = clock();
        time += (endTime-startTime)/CLOCKS_PER_SEC;
        cout << time/cntTime << endl;
    }
    cout << "Average: " << time/20 << "s";
    return 0;
}