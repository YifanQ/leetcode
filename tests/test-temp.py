import bisect as bi
a1 = [1, 2, 4, 4, 4, 4, 9]
a2 = [-2, -1, 2, 2, 9, 10, 12, 13, 19, 20, 20, 20, 20, 79, 80]

r1 = [0, len(a1)]
r2 = [0, len(a2)]
mid = (r1[0] + r1[1])/2
key = a1[ mid ]
b1_l = bi.bisect_left(a1, key, hi = mid+1)
b1_r = bi.bisect_right(a1, key, lo = mid)
b2_l = bi.bisect_left(a2, key)
b2_r = bi.bisect_right(a2, key)

b = [[b1_l, b1_r], [b2_l, b2_r]];
if b1_l + b2_l >= k:
    return find([ r1[0], b1_l ], [ r2[0], b2_l ], k)
if b1_r + b2_r >= k:
    return key

return find([ b1_r, r1[1] ], [ b2_r, r2[1]], k-(b1_r + b2_r) )
