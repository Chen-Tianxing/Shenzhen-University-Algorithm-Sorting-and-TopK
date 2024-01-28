import numpy as np

# 随机生成20组数据，每组数据有1e5个，数字的值域为[1, 1e9]
upperBound, dataSize = 1e9, int(1e5)

file = open("../Input/ProblemOneInput.txt", "w", encoding="utf-8")
for i in range(20):
    file.write(str(dataSize)+'\n')
    arr = np.random.randint(1, upperBound, dataSize)
    for j in range(len(arr)):
        file.write(str(arr[j])+'\n')
file.close()
