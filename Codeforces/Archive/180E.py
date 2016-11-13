n, m, k = [int(x) for x in raw_input().split()]
cl = {}
alr = [0] * m
lst = [int(x) - 1 for x in raw_input().split()]
for i in range(0, len(lst)):
	x = lst[i]
	if x not in cl:
		cl[x] = []
	cl[x] += [i - alr[x]]
	alr[x] += 1
def gen_pairs(lst):
	l = 0
	for x in lst:
		while x - lst[l] > k:
			l += 1
		yield l
res = max([max(for clr in cl.values()])
for clr in cl.values():
	l = 0
	for j in range(0, len(clr)):
		while clr[j] - clr[l] > k:
			l += 1
		res = max(res, j - l + 1)
print(res)