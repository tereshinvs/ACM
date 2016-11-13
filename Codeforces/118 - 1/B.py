s = int(raw_input())
pw = list(map(int, raw_input().split()))
abc = sum(pw)
if abc == 0:
	abc += 1
for i in pw:
	print("%.15f" % (i * s / (abc + 0.0)))
