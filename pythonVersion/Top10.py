from queue import PriorityQueue
from QuickSort import quickSort


def solutionUsingBubbleSort(arr):
    global k
    for countTime in range(k):
        maxNumber, maxNumberIndex = arr[countTime], countTime
        for i in range(countTime+1, len(arr)):
            if arr[i] > maxNumber:
                maxNumber, maxNumberIndex = arr[i], i
        arr[countTime], arr[maxNumberIndex] = arr[maxNumberIndex], arr[countTime]
    print(arr[0:10])


def solutionUsingPriorityQueue(arr):
    global k
    q, res = PriorityQueue(), []
    for x in arr:
        q.put((-x, x))
    for cnt in range(k):
        res.append(q.get().second)
    res.sort()
    print(res)


def solutionUsingQuickSort(arr):
    global k
    quickSort(arr, 0, len(arr)-1)
    print(arr[len(arr)-k:len(arr)])


global dataSize, k
dataSize, k = 1000000000, 10

if __name__ == '__main__':
    arr = []

