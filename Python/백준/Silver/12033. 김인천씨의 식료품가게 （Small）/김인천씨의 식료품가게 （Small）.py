def q12033():
    # 백준 12033번 파이썬 김인천씨의 식료품가게 (Small)
    t = int(input())
    case = 0
    for _ in range(t):
        case += 1
        n = int(input())
        lst = list(map(int, input().split()))
        result = []
        for i in lst:
            if int(i * (4 / 3)) in lst:
                lst.remove(int(i * (4 / 3)))
                result.append(str(i))
        print(f'Case #{case}: {" ".join(result)}')
q12033()