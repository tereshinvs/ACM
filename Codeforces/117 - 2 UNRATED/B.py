d = int(raw_input())
n = int(raw_input())
res = 0
for x in list(map(int, raw_input().split()))[:-1]:
	res += d - x
print(res)