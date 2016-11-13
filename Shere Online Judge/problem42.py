reverse = lambda s: s[len(s) - 1] + reverse(s[0 : len(s) - 1]) if len(s) > 1 else s
for i in range(int(input())):
	num = list(map(int, input().split()))
	s = reverse(str(int(reverse(str(num[0]))) + int(reverse(str(num[1])))))
	while s[0] == "0":
		s = s[1:]
	print(s)