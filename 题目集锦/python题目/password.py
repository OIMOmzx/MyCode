num = int(input())
for i in range(0, 10, 1):
    for j in range(0, 10, 1):
        for k in range(0, 10, 1):
            for p in range(0, 10, 1):
                if i * 1000 + j * 100 + k * 10 + p == num :
                    print(i, j, k, p)
