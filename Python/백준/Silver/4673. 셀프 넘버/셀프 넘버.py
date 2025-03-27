def q4673():
    # 백준 4673번 셀프 넘버 파이썬
    dp = [False] * 10001
    for i in range(1, 10001):
        temp = i
        while i > 0:
            temp += i % 10
            i //= 10
        if temp < 10000:
            dp[temp] = True
    for i in range(1, 10000):
        if not dp[i]:
            print(i)
q4673()