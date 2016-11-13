import fractions
from decimal import *

l = int(Decimal(input()) * 1000000000)
a = int(Decimal(input()) * 1000000000)
b = int(Decimal(input()) * 1000000000)
lcd = a * b // fractions.gcd(a, b)
print(l // lcd - (1 if l % lcd == 0 else 0))