n = int(raw_input())
a = list(map(int, raw_input().split()))
s = sum(a)
res = []
for i in range(0, len(a)):
	if (s - a[i]) == a[i] * (len(a) - 1):
		res.append(i + 1)
print(len(res))
for i in res:
	print(i)