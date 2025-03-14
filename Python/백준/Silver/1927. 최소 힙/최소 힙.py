def q1927():
    # 최소 힙
    import sys
    import heapq

    n = int(sys.stdin.readline())
    lst = []
    for _ in range(n):
        x = int(int(sys.stdin.readline()))
        if x > 0:
            heapq.heappush(lst, x)
        else:
            if lst:
                print(heapq.heappop(lst))
            else:
                print(0)
q1927()