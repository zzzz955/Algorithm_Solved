a = []
b = []
for i in range(4): a.append(int(input()))
for i in range(2): b.append(int(input()))
a.sort()
b.sort()
c = 0
for i in range(3, 0, -1):
    c += a[i]
print(c + b[1])