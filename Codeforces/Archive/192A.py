from math import sqrt
n = int(input())
ans = "NO"
for i in range(1, n):
	m = n - i * (i + 1) // 2
	if m <= 0:
		break
	x = int(sqrt(1 + 8 * m))
	if x * x == 1 + 8 * m and x - 1 > 0:
		ans = "YES"
		break
print(ans)
