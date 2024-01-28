import time


def insertionSort(arr):
    for i in range(len(arr)):
        temp, j = arr[i], 0
        for j in range(i, 0, -1):
            if arr[j - 1] > temp:
                arr[j] = arr[j - 1]
            else:
                break
        arr[j] = temp


def mergeSort(arr):
    if len(arr) <= 1:
        return arr
    # print(len(arr), arr)
    # print(len(arr)//2+1, len(arr))
    # print(arr[len(arr)//2+1:len(arr)])
    a, b = mergeSort(arr[0:len(arr) // 2]), mergeSort(arr[len(arr) // 2:len(arr)])
    p, q, res = 0, 0, []
    while p < len(a) and q < len(b):
        if a[p] < b[q]:
            res.append(a[p])
            p += 1
        else:
            res.append(b[q])
            q += 1
    if p < len(a):
        while p < len(a):
            res.append(a[p])
            p += 1
    else:
        while q < len(b):
            res.append(b[q])
            q += 1
    return res


def bubbleSort(arr):
    while True:
        flag = False  # Represent if arr is already sorted
        for i in range(len(arr) - 1):
            if arr[i] > arr[i + 1]:
                flag, arr[i], arr[i + 1] = True, arr[i + 1], arr[i]
        if not flag:
            break


def quickSort(arr, low, high):
    if low >= high:
        return
    l, r, key = low, high, arr[low]
    while low < high:
        while low < high and arr[high] >= key:
            high -= 1
        arr[low] = arr[high]
        while low < high and arr[low] <= key:
            low += 1
        arr[high] = arr[low]
    arr[low] = key
    quickSort(arr, l, low - 1), quickSort(arr, low + 1, r)


def selectionSort(arr):
    for i in range(len(arr)):
        minIndex, minValue = i, arr[i]
        for j in range(i + 1, len(arr)):
            if arr[j] < minValue:
                minIndex, minValue = j, arr[j]
        arr[i], arr[minIndex] = arr[minValue], arr[i]


def checkSorted(arr):
    for i in range(1, len(arr)):
        if arr[i] < arr[i - 1]:
            return False
    return True


if __name__ == '__main__':
    cntTime, res = 0, []

    for cnt in range(20):
        file = open("Input/ProblemOneInput.txt", "r", encoding="utf-8")
        dataSize, arr = int(file.readline()), []
        for i in range(dataSize):
            arr.append(int(file.readline()))
        startTime, endTime = time.time(), 0
        bubbleSort(arr)
        endTime = time.time()
        cntTime += endTime - startTime
        print(cnt, endTime - startTime)
        res.append([endTime - startTime, checkSorted(arr)])

    file.close()
    cntTime /= 20
    print(str(cntTime) + 'S', res)
