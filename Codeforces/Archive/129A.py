n = int(raw_input())
a = list(map(int, raw_input().split()))
sum = sum(a)
res = 0
for x in a:
	if (sum - x)%2 == 0:
		res += 1
print(res)