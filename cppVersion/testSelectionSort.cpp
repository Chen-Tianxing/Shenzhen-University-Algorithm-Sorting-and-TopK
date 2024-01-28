#include<iostream>
#include<vector>
using namespace std;
double selectionSort(std::vector<int>& a) {
    int len = a.size(), *arr = new int[len];
    for(int i=0; i<len; i++) arr[i] = a[i];
    clock_t st = clock();
    for(int i=0; i<len; i++) {
        int minIndex = i, minValue = arr[i];
        for(int j=i+1; j<len; j++) {
            if(arr[j]<minValue) minValue = arr[j], minIndex = j;
        }
        std::swap(arr[i], arr[minIndex]);
    }
    clock_t ed = clock();
    for(int i=0; i<len; i++) a[i] = arr[i];
    // if(checkSorted(arr)) puts("selectionSort Success");
    // else puts("selectionSort Fail");
    delete[] arr;
    return (double)(ed-st)/CLOCKS_PER_SEC;
}
double newSelectionSort(std::vector<int>& a) {
    int len = a.size(), *arr = new int[len];
    for(int i=0; i<len; i++) arr[i] = a[i];
    clock_t st = clock();
    for(int i=0; i<len; i++) {
        int minIndex = i, minValue = arr[i];
        for(int j=i+1; j<len; j++) {
            if(arr[j]<minValue) minValue = arr[j], minIndex = j;
        }
        if(i!=minIndex) std::swap(arr[i], arr[minIndex]);
    }
    clock_t ed = clock();
    for(int i=0; i<len; i++) a[i] = arr[i];
    // if(checkSorted(arr)) puts("selectionSort Success");
    // else puts("selectionSort Fail");
    delete[] arr;
    return (double)(ed-st)/CLOCKS_PER_SEC;
}
double solve(const int& siz, double func(std::vector<int>&)) {
    double time = 0;
    string check = "Fail";
    cin >> check;
    cout << siz << " " << check << endl;
    for(int cntTime=1, len; cntTime<=20; cntTime++) {
        cin >> len;
        vector<int> arr;
        for(int i=0, temp; i<len; i++) {
            scanf("%d", &temp);
            arr.push_back(temp);
        }
        // -------------
        time += func(arr);
        // -------------
        printf("%.3lfs ", time/cntTime);   
        if(cntTime==10) puts("");
    }
    puts("");
    return time/20;
}
int main() {
    freopen("../Input/ProblemThree5e5.txt","r",stdin);
    double res = solve(5e5, selectionSort);
    freopen("../Input/ProblemThree5e5.txt","r",stdin);
    double res1 = solve(5e5, newSelectionSort);
    cout << "old Average Time: " << res << "s" << endl;
    cout << "new Average Time: " << res1 << "s" << endl << endl;
}