s1 = raw_input()
s2 = raw_input()
s = s1 + s2
n1 = len(s1)
n2 = len(s2)
n = len(s)
z = [0] * n
l, r = 0, 0
for i in range(1, n):
	if i <= r:
		z[i] = min(r - i + 1, z[i - l])
	while i + z[i] < n and s[z[i]] == s[i + z[i]]:
		z[i] += 1
	if i + z[i] - 1 > r:
		l, r = i, i + z[i] - 1
print(len([i for i in range(1, n) if n1 % i == 0 and n2 % i == 0 and i + z[i] == n]))
