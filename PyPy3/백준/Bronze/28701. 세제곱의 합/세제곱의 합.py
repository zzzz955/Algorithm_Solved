n = int(input())
f = 0
t = 0
for i in range(1, n + 1):
    f += i
    t += pow(i, 3)
print(f)
print(pow(f, 2))
print(t)