n = int(input())
for i in range(0, n):
	x, y = map(int, input().split())
	print("Yes" if (x <= 2 and y <= 1) or (x <= 1 and y <= 2) else "No")
