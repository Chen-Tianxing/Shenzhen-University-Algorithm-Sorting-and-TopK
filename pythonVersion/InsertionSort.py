import time


def insertionSort(arr):
    for i in range(len(arr)):
        temp, j = arr[i], 0
        for j in range(i, 0, -1):
            if arr[j-1] > temp:
                arr[j] = arr[j-1]
            else:
                break
        arr[j] = temp


TestData = [1, 10, 7, 8, 5, 6, 2, 4, 3, 9]

if __name__ == '__main__':
    arr = TestData
    print(arr)
    insertionSort(arr)
    print(arr)
