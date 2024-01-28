#include<iostream>
#include<ctime>
#include<fstream>
#include"SortingAlgorithm.h"
#define MAXN 10000001
using namespace std;
int nowType = 0, len;
string optionAlgorithm[5] = {"quickSort", "mergeSort", "selectionSort", "insertionSort", "bubbleSort"};
double (*(func)[5])(vector<int>&) = {quickSort, mergeSort, selectionSort, insertionSort, bubbleSort};
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
    return time;
}
int main() {
    nowType = 1;
    freopen("../Input/ProblemFiveInput.txt","r",stdin);
    double a = solve(1e6);
    cout << "Average Time: " << a << "s" << endl << endl;
    return 0;
    double res;
    cout << "\n\nChen Tianxing 2023 Shenzhen University!!\n\n";
    // ------------
    for(nowType = 0; nowType < 5; nowType++) {
        cout << "-----------\n";
        cout << optionAlgorithm[nowType] << endl << endl;
        freopen("../Input/ProblemThree1e5.txt","r",stdin);
        res = solve(1e5);
        cout << "Average Time: " << res << "s" << endl << endl;
        
        freopen("../Input/ProblemThree2e5.txt","r",stdin);
        res = solve(2e5);
        cout << "Average Time: " << res << "s" << endl <<endl;

        freopen("../Input/ProblemThree3e5.txt","r",stdin);
        res = solve(3e5);
        cout << "Average Time: " << res << "s" << endl << endl;

        freopen("../Input/ProblemThree4e5.txt","r",stdin);
        res = solve(4e5);
        cout << "Average Time: " << res << "s" << endl << endl;

        freopen("../Input/ProblemThree5e5.txt","r",stdin);
        res = solve(5e5);
        cout << "Average Time: " << res << "s" << endl << endl;

        cout << endl;
    }
    return 0;
}