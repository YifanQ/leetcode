from random import randint

n = 20
m = 42

r1 = [1, n]
r2 = [1, m]

k = randint(1, n + m)

def reduce(r1, r2, k):
    n = r1[1] - r1[0]
    m = r2[1] - r2[0]
    while True:
        flag = True
        print n, m, k
        if n > k:
            n = k;
            r1[1] = r1[0] + (k-1) if r1[1] > r1[0] else r1[0] - (k-1)
            flag = False
        if m > k:
            m = k;
            r2[1] = r2[0] + (k-1) if r2[1] > r2[0] else r2[0] - (k-1)
            flag = False
        if n + m + 1 - k < k:
            k = n + m + 1 - k
            r1 = r1[::-1]
            r2 = r2[::-1]
            flag = False
        if flag : break
    if r1[0] > r1[1]:
        k = n + m + 1 - k
        r1 = r1[::-1]
        r2 = r2[::-1]
    return r1, r2, k
