def read_set():
	n = int(input()) - 1
	a = [list(map(int, input().split(' '))) for i in range(4)]
	return set(a[n])

t = int(input())
for q in range(t):
	res = read_set() & read_set()
	print("Case #", q + 1, end = ": ", sep = "")
	if len(res) == 0:
		print("Volunteer cheated!")
	elif len(res) == 1:
		print(list(res)[0])
	else:
		print("Bad magician!")