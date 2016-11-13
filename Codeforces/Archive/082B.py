a = []
n = int(input())
for i in range(0, n * (n - 1) // 2):
	a.append((list(map(int, input().split()))[1:]).sort())
def list_compare(temp):
	res = ""
	temp = list(temp)
	for x in temp:
		res = res + str(chr(x))
	return str(res)
a.sort(key = list_compare)
res = ""
if n == 2:
	res = str(a[0][0])
	for x in a[0][1:]:
		res = res + str(x)
	print(res)
	exit
for i in range(0, len(a) - 1):
	if a[i][0] != a[i + 1][0]:
		res = ""
		for x in [x for x in a[i] if a[i - 1].count(x) > 0]:
			res = res + str(x)
		print(res)