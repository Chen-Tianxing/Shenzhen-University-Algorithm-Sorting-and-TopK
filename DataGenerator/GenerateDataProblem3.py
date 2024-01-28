import numpy as np

# 随机生成20组数据，每组数据有1e5个，数字的值域为[1, 1e9]
upperBound, dataSize = 1e9, int(1e5)

file = open("../Input/ProblemThree1e5.txt", "w", encoding="utf-8")
file.write("OK\n")
for i in range(20):
    file.write(str(dataSize)+'\n')
    arr = np.random.randint(1, upperBound, dataSize)
    for j in range(len(arr)):
        file.write(str(arr[j])+'\n')
file.close()

# 随机生成20组数据，每组数据有2e5个，数字的值域为[1, 1e9]
upperBound, dataSize = 1e9, int(2e5)

file = open("../Input/ProblemThree2e5.txt", "w", encoding="utf-8")
file.write("OK\n")
for i in range(20):
    file.write(str(dataSize)+'\n')
    arr = np.random.randint(1, upperBound, dataSize)
    for j in range(len(arr)):
        file.write(str(arr[j])+'\n')
file.close()

# 随机生成20组数据，每组数据有3e5个，数字的值域为[1, 1e9]
upperBound, dataSize = 1e9, int(3e5)

file = open("../Input/ProblemThree3e5.txt", "w", encoding="utf-8")
file.write("OK\n")
for i in range(20):
    file.write(str(dataSize)+'\n')
    arr = np.random.randint(1, upperBound, dataSize)
    for j in range(len(arr)):
        file.write(str(arr[j])+'\n')
file.close()

# 随机生成20组数据，每组数据有4e5个，数字的值域为[1, 1e9]
upperBound, dataSize = 1e9, int(4e5)

file = open("../Input/ProblemThree4e5.txt", "w", encoding="utf-8")
file.write("OK\n")
for i in range(20):
    file.write(str(dataSize)+'\n')
    arr = np.random.randint(1, upperBound, dataSize)
    for j in range(len(arr)):
        file.write(str(arr[j])+'\n')
file.close()

# 随机生成20组数据，每组数据有5e5个，数字的值域为[1, 1e9]
upperBound, dataSize = 1e9, int(5e5)

file = open("../Input/ProblemThree5e5.txt", "w", encoding="utf-8")
file.write("OK\n")
for i in range(20):
    file.write(str(dataSize)+'\n')
    arr = np.random.randint(1, upperBound, dataSize)
    for j in range(len(arr)):
        file.write(str(arr[j])+'\n')
file.close()
