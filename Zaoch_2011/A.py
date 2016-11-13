inp = list(map(int, input().split()))
a = inp[0]
b = inp[1]
c = inp[2]
res = set([])
for i in range(0, c + 1):
	res = res | set([a * i + b * (c - i)])
print(len(res))