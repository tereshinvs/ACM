import math
import operator

primes = [2]
for i in xrange(3, 32000, 2):
	flag = True
	for j in primes:
		if i%j == 0:
			flag = False
			break
	if flag:
		primes.append(i)

n = int(input())
while n:
	bnds = list(map(int, input().split()))
	for i in xrange(max(2, bnds[0]), bnds[1] + 1):
		flag = True
		sqrt_i = math.sqrt(i)
		for j in primes:
			if j > sqrt_i:
				break
			if i%j == 0:
				flag = False
				break
		if flag:
			print(i)
	print()
	n -= 1