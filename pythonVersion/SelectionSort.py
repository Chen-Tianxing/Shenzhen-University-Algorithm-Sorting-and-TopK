def selectionSort(arr):
    for i in range(len(arr)):
        minIndex, minValue = i, arr[i]
        for j in range(i+1, len(arr)):
            if arr[j] < minValue:
                minIndex, minValue = j, arr[j]
        arr[i], arr[minIndex] = arr[minValue], arr[i]


TestData = [1, 10, 7, 8, 5, 6, 2, 4, 3, 9]

if __name__ == '__main__':
    arr = TestData
    print(arr)
    selectionSort(arr)
    print(arr)
