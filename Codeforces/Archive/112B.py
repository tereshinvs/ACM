s = list(map(int, raw_input().split()))
n = s[0] // 2
x = s[1]
y = s[2]
print("NO" if (x == n or x == n + 1) and abs(y == n or y == n + 1) else "YES")