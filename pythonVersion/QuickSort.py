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
    quickSort(arr, l, low-1), quickSort(arr, low+1, r)


TestData = [1, 10, 7, 8, 5, 6, 2, 4, 3, 9]

if __name__ == '__main__':
    arr = TestData
    print(arr)
    quickSort(arr, 0, len(arr)-1)
    print(arr)