n = int(raw_input())
for i in range(0, n):
	s = raw_input()
	print(s if len(s) <= 10 else s[:1] + str(len(s) - 2) + s[-1:])
