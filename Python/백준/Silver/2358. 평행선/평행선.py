def q2358():
    # 평행선
    import sys

    n = int(sys.stdin.readline())
    dic_x = {}
    dic_y = {}
    for _ in range(n):
        x, y = map(int, sys.stdin.readline().split())
        if x in dic_x:
            dic_x[x] = True
        else:
            dic_x[x] = False
        if y in dic_y:
            dic_y[y] = True
        else:
            dic_y[y] = False
    result = 0
    for val in dic_x.values():
        if val:
            result += 1
    for val in dic_y.values():
        if val:
            result += 1
    print(result)
q2358()