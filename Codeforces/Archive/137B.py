n = int(raw_input())
a = [0] * n
for x in list(map(int, raw_input().split())):
	if x <= n:
		a[x - 1] += 1
res = 0
for i in range(0, n):
	if a[i] == 0:
		res += 1
print(res)