import psyco
psyco.jit()
q = int(input())
while q > 0:
	n = int(input())
	res = n//5
	i = res
	while i > 0:
		res += i//5
		i //= 5
	print(res)
	q -= 1