n, d = map(int, input().split())
res = set()
data = [[]] * n
for i in range(0, n):
	data[i] = input().split()
	data[i][2] = int(data[i][2])
for i in range(0, n):
	for j in range(i + 1, n):
		if (data[i][0] == data[j][1] and data[i][1] == data[j][0]
		and 0 < data[j][2] - data[i][2] <= d
		and data[i][1] + " " + data[i][0] not in res):
			res |= { data[i][0] + " " + data[i][1] }
print(len(res))
for l in res:
	print(l)

	
	