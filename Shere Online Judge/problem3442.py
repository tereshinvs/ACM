def getLastDigit(t, pwr):
	alr = [-1] * 10
	t %= 10
	while (pwr >= 0):
		if not alr[t]:
			return 
	return alr[9]

print(getLastDigit(5))