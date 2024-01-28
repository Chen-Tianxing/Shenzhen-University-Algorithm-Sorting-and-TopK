def bubbleSort(arr):
    while True:
        flag = False # Represent if arr is already sorted
        for i in range(len(arr)-1):
            if arr[i] > arr[i+1]:
                flag, arr[i], arr[i+1] = True, arr[i+1], arr[i]
        if not flag:
            break


TestData = [1, 10, 7, 8, 5, 6, 2, 4, 3, 9]

if __name__ == '__main__':
    arr = TestData
    print(arr)
    bubbleSort(arr)
    print(arr)