def q12865():
    n, k = map(int, input().split())
    dp = [[0] * (k + 1) for _ in range(n + 1)]
    weights = []
    values = []
    for _ in range(n):
        w, v = map(int, input().split())
        weights.append(w)
        values.append(v)
    for i in range(1, n + 1):
        for w in range(1, k + 1):
            if weights[i - 1] <= w:
                dp[i][w] = max(dp[i - 1][w], dp[i - 1][w - weights[i - 1]] + values[i - 1])
            else:
                dp[i][w] = dp[i - 1][w]
    print(dp[n][k])
q12865()

