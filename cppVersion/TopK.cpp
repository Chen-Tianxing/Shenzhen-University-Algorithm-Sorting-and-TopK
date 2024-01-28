#include<iostream>
#include<limits.h>
#include<queue>
#include<stack>
#include"SortingAlgorithm.h"
using namespace std;
const int K = 10, testCase = 20;
// quickSortSolution
void AdjustMinheap(int *array, int loc, int n) {
    int left = 2 * loc + 1;  // 左孩子
    int right = 2 * loc + 2; // 右孩子
    if (left < n) {
        if (right < n) {
            if (array[left] > array[right]) {
                if (array[right] < array[loc]) {
                    Swap(array[right], array[loc]);
                    AdjustMinheap(array, right, n);
                }
            }
            else {
                if (array[left] < array[loc]) {
                    Swap(array[left], array[loc]);
                    AdjustMinheap(array, left, n);
                }
            }
        } else {
            if (array[left] < array[loc]) {
                Swap(array[left], array[loc]);
                AdjustMinheap(array, left, n);
            }
        }
    }
}
int* TopK_Heap(int* array, int n, int k) {
    int *result = new int[k];
    // 取前k个数
    for (int i = 0; i < k; i++) result[i] = array[i];
    // 根据前k个数建小顶堆
    for (int i = k / 2 - 1; i >= 0; i--) AdjustMinheap(result, i, k);
    // 剩下全部与堆顶比较
    for (int i = k; i < n; i++) {
        if (array[i] > result[0]) {
            result[0] = array[i];
            AdjustMinheap(result, 0, k);
        }
    }
    return result;
}

double priorityQueueSolution(const vector<int>& a) {
    int len = a.size(), *arr = new int[len];
    for(int i=0; i<len; i++) arr[i] = a[i];
    priority_queue<int> Q;
    clock_t st = clock();
    for(int i=0; i<len; i++) Q.push(arr[i]);
    printf("PriorityQueueSolution: ");
    for(int i=0; i<K; i++) cout << Q.top() << " ", Q.pop();
    clock_t ed = clock();
    puts("");
    delete[] arr;
    return (double)(ed-st)/CLOCKS_PER_SEC;
}
double selectionSortSolution(const vector<int>& a) {
    int len = a.size(), *arr = new int[len];
    for(int i=0; i<len; i++) arr[i] = a[i];
    clock_t st = clock();
    for(int cnt=0; cnt<K; cnt++) {
        int maxIndex = -1, maxVal = INT_MIN;
        for(int j=cnt; j<len; j++) {
            if(arr[j]>maxVal) maxVal = arr[j], maxIndex = j;
        }
        swap(arr[maxIndex], arr[cnt]);
    }
    printf("selectionSortSolution: ");
    for(int i=0; i<K; i++) cout << arr[i] << " ";
    puts("");
    clock_t ed = clock();
    delete[] arr;
    return (double)(ed-st)/CLOCKS_PER_SEC;
}
double bubbleSortSolution(const vector<int>& a) {
    int len = a.size(), *arr = new int[len];
    for(int i=0; i<len; i++) arr[i] = a[i];
    clock_t st = clock();
    for(int cnt=0; cnt<K; cnt++) {
        for(int i=0; i<len-cnt-1; i++) {
            if(arr[i]>arr[i+1]) swap(arr[i], arr[i+1]);
        }
    }
    printf("bubbleSortSolution:    ");
    for(int i=len-1; i>=len-K; i--) cout << arr[i] << " ";
    puts("");
    clock_t ed = clock();
    delete[] arr;
    return (double)(ed-st)/CLOCKS_PER_SEC;
}
double heapSolution(const vector<int>& a) {
    int len = a.size(), *arr;
    for(int i=0; i<len; i++) arr[i] = a[i];
    clock_t st = clock();
    arr = TopK_Heap(arr, len, K);
    clock_t ed = clock();
    printf("heapSolution:          ");
    sort(arr, arr+K);
    for(int i=K-1; i>=0; i--) cout << arr[i] << " ";
    puts("");
    return (double)(ed-st)/CLOCKS_PER_SEC;
}
double work() {
    int n;
    double res = 0;
    string s = "Fail";
    cin >> s;
    cout << s << endl;
    cin >> n;
    cout << n << " ———— ";
    for(int T=0; T<testCase; T++) {
        vector<int> K;
        for(int i=0, x; i<n; i++) scanf("%d", &x), K.push_back(x);
        res += priorityQueueSolution(K);
    }
    return res / testCase;
}
void solve() {
    cout << "-----------\n";
    double res = 0;
    freopen("../Input/ProblemThree1e5.txt","r",stdin);
    res = work();
    cout << "Average Time: " << res << "s" << endl << endl;
    
    freopen("../Input/ProblemThree2e5.txt","r",stdin);
    res = work();
    cout << "Average Time: " << res << "s" << endl <<endl;

    freopen("../Input/ProblemThree3e5.txt","r",stdin);
    res = work();
    cout << "Average Time: " << res << "s" << endl << endl;

    freopen("../Input/ProblemThree4e5.txt","r",stdin);
    res = work();
    cout << "Average Time: " << res << "s" << endl << endl;

    freopen("../Input/ProblemThree5e5.txt","r",stdin);
    res = work();
    cout << "Average Time: " << res << "s" << endl << endl;

    cout << endl;
}
int main() {
    solve();
    return 0;
    freopen("../Input/ProblemFiveInput.txt", "r", stdin);
    string check = "Fail";
    cin >> check;
    cout << check << endl;
    double a=0, b=0, c=0, d=0, e=0;
    for(int T=0; T<testCase; T++) {
        printf("Test Case #%d:\n", T+1);
        vector<int> arr;
        int n;
        cin >> n;
        cout << n << endl;
        for(int i=0, x; i<n; i++) scanf("%d", &x), arr.push_back(x);
        cout << arr[0] << endl;
        a += priorityQueueSolution(arr);
        b += selectionSortSolution(arr);
        c += bubbleSortSolution(arr);
        d += quickSort(arr);
        e += heapSolution(arr);
        puts("");
    }
    a /= testCase, b /= testCase, c /= testCase, d /= testCase, e /= testCase;
    printf("Averge Time:\n");
    printf("priorityQueueSolution: %.5lf\n", a);
    printf("selectionSortSolution: %.5lf\n", b);
    printf("bubbleSortSolution   : %.5lf\n", a);
    printf("quickSortSolution    : %.5lf\n", d);
    printf("heapSolution         : %.5lf\n", e);
    puts("");
    return 0;
}