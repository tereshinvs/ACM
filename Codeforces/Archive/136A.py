#raw_input for python 2.6+ O_o
n = int(raw_input())
a = list(map(int, raw_input().split()))
res = [0] * n
for i in range(0, n):
    res[a[i] - 1] = i + 1
for i in res:
    print(str(i) + " ")