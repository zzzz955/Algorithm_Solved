def q10158():
    # 백준 10158번 개미 파이썬
    c, r = map(int, input().split())
    p, q = map(int, input().split())
    t = int(input())

    x = (p + t) % (2 * c)
    y = (q + t) % (2 * r)

    if x > c:
        x = 2 * c - x
    if y > r:
        y = 2 * r - y

    print(x, y)
q10158()