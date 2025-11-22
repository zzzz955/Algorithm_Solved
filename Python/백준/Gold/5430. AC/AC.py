def q5430():
    # 백준 5430번 파이썬 AC
    import collections

    t = int(input())
    for _ in range(t):
        p = input()
        n = int(input())
        s = input()[1:-1]
        deq = collections.deque(s.split(','))
        chk = True
        rev = False
        for char in p:
            if char == 'R':
                if rev:
                    rev = False
                else:
                    rev = True
            else:
                if len(deq) >= 1 and not (len(deq) == 1 and deq[0] == ''):
                    if rev:
                        deq.pop()
                    else:
                        deq.popleft()
                else:
                    chk = False
                    break
        if rev:
            deq.reverse()
        print('[' + ','.join(deq) + ']' if chk else 'error')
q5430()