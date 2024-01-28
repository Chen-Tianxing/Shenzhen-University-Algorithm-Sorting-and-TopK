#include<iostream>
#include<ctime>
#include<fstream>
#include"SortingAlgorithm.h"
using namespace std;
int nowType = 0, len;
string optionAlgorithm[5] = {"mergeSort", "quickSort", "selectionSort", "insertionSort", "bubbleSort"};
double (*(func)[5])(vector<int>&) = {mergeSort, quickSort, selectionSort, insertionSort, bubbleSort};
double solve(const int& siz) {
    double time = 0;
    string check = "Fail";
    cin >> check;
    cout << siz << " " << check << endl;
    for(int cntTime=1; cntTime<=20; cntTime++) {
        cin >> len;
        vector<int> arr;
        for(int i=0, temp; i<len; i++) {
            scanf("%d", &temp);
            arr.push_back(temp);
        }
        // -------------
        time += func[nowType](arr);
        // -------------
        bool check = checkSorted(arr);
        printf("%.3lfs %s  ", time/cntTime, check?"OK":"Fail");   
        if(cntTime==10) puts("");
    }
    puts("");
    return time/20;
}
int main() {
    double res;
    cout << "\n\nChen Tianxing 2023 Shenzhen University!!\n\n";
    // ------------
    for(nowType = 0; nowType < 5; nowType++) {
        cout << "-----------\n";
        cout << optionAlgorithm[nowType] << endl << endl;
        freopen("../Input/PreTest.txt","r",stdin);
        res = solve(1e5);
        printf("Average Time: %.10lfs\n\n", res);
    }
    return 0;
}