n = int(raw_input())
a = list(map(int, raw_input().split()))
a.sort()
a[n - 1] = 1 if a[n - 1] > 1 else 2
a.sort()
for i in a:
	print(str(i) + " ")