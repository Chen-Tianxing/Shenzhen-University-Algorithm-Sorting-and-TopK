def mergeSort(arr):
    if len(arr) <= 1:
        return arr
    # print(len(arr), arr)
    # print(len(arr)//2+1, len(arr))
    # print(arr[len(arr)//2+1:len(arr)])
    a, b = mergeSort(arr[0:len(arr)//2]), mergeSort(arr[len(arr)//2:len(arr)])
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


TestData = [1, 10, 7, 8, 5, 6, 2, 4, 3, 9]

if __name__ == '__main__':
    arr = TestData
    print(TestData)
    arr = mergeSort(arr)
    print(arr)
