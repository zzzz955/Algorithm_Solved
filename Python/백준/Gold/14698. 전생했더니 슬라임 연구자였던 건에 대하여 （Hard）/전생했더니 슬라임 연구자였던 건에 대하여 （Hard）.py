import heapq
import sys

t = int(sys.stdin.readline())
for _ in range(t):
    n = int(sys.stdin.readline())
    lst = list(map(int, sys.stdin.readline().split()))
    heapq.heapify(lst)
    arr = []

    while 1:
        one = heapq.heappop(lst)
        if not lst: break
        two = heapq.heappop(lst)
        arr.append(one * two)
        heapq.heappush(lst, one * two)

    ans = 1
    for i in arr:
        ans *= i
    print(ans % 1000000007)
