import bisect as bi

# a1 = [1, 2, 4, 9]
# a2 = [2, 5, 8, 9, 12, 29, 100]

a1 = []
a2 = [1, 1, 1, 1, 1, 1, 1]

def reduce(r1, r2, k):
    n = r1[1] - r1[0]
    m = r2[1] - r2[0]
    while True:
        flag = True
        if n > k:
            n = k;
            r1[1] = r1[0] + k if r1[1] > r1[0] else r1[0] - k
            flag = False
        if m > k:
            m = k;
            r2[1] = r2[0] + k if r2[1] > r2[0] else r2[0] - k
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

def find_1(r1, r2, k):
    n = r1[1] - r1[0]
    m = r2[1] - r2[0]
    if n == 0: return a2[r2[0] + k-1]
    if m == 0: return a1[r1[0] + k-1]
    print "Call", r1, r2, k
    r1, r2, k = reduce(r1, r2, k)
    print "Real", r1, r2, k

    mid = (r1[0] + r1[1])/2
    key = a1[ mid ]
    b1_l = bi.bisect_left(a1, key, hi = mid+1)
    b1_r = bi.bisect_right(a1, key, lo = mid)
    b2_l = bi.bisect_left(a2, key)
    b2_r = bi.bisect_right(a2, key)

    b = [[b1_l, b1_r], [b2_l, b2_r]];
    if b1_l + b2_l >= k + r1[0] + r2[0]:
        return find_1([ r1[0], b1_l ], [ r2[0], b2_l ], k)
    if b1_r + b2_r >= k + r1[0] + r2[0]:
        return key

    k = k-(b1_r - r1[0] + b2_r - r2[0])
    return find_1([ b1_r, r1[1] ], [ b2_r, r2[1]], k)

if ( len(a1)+len(a2) )%2 == 1:
    print find_1( [0, len(a1)], [0, len(a2)], (len(a1)+len(a2)+1)/2 )
    a = a1+a2
    a.sort()
    print a, a[( len(a) )/2]
else:
    if len(a1) + len(a2) == 0: print None
    if len(a1) == 0:
        print float(sum(a2[ len(a2)/2-1:len(a2)/2 ]))/2
    if len(a2) == 0:
        print float(sum(a1[ len(a1)/2-1:len(a1)/2 ]))/2
    if len(a1) + len(a2) == 2:
        print float(sum(a1) + sum(a2)) / 2

    if a1[0]<a2[0]:
        mid_l = find_1( [1, len(a1)], [0, len(a2)], (len(a1)+len(a2)-1)/2 )
    else
        mid_l = find_1( [0, len(a1)], [1, len(a2)], (len(a1)+len(a2)-1)/2 )

    if a1[-1]>a2[-1]:
        mid_r = find_1( [0, len(a1)-1], [0, len(a2)], (len(a1)+len(a2)-1)/2 )
    else
        mid_r = find_1( [0, len(a1)], [0, len(a2)-1], (len(a1)+len(a2)-1)/2 )
    print float(mid_l + mid_r)/2
