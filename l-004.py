import bisect as bi
class Solution:
    # @param {integer[]} nums1
    # @param {integer[]} nums2
    # @return {float}
    @staticmethod
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
    @staticmethod
    def find_1(a1, a2, r1, r2, k):
        n = r1[1] - r1[0]
        m = r2[1] - r2[0]
        if n == 0: return a2[r2[0] + k-1]
        if m == 0: return a1[r1[0] + k-1]
        # print "Call", r1, r2, k
        r1, r2, k = Solution.reduce(r1, r2, k)
        # print "Real", r1, r2, k

        mid = (r1[0] + r1[1])/2
        key = a1[ mid ]
        b1_l = bi.bisect_left(a1, key, hi = mid+1)
        b1_r = bi.bisect_right(a1, key, lo = mid)
        b2_l = bi.bisect_left(a2, key)
        b2_r = bi.bisect_right(a2, key)

        b = [[b1_l, b1_r], [b2_l, b2_r]];
        # print a1[r1[0]:r1[1]], a2[r2[0]:r2[1]]
        # print b
        if b1_l + b2_l >= k + r1[0] + r2[0]:
            return Solution.find_1(a1, a2, [ r1[0], b1_l ], [ r2[0], b2_l ], k)
        if b1_r + b2_r >= k + r1[0] + r2[0]:
            return key

        k = k-(b1_r - r1[0] + b2_r - r2[0])
        return Solution.find_1(a1, a2, [ b1_r, r1[1] ], [ b2_r, r2[1]], k)

    def findMedianSortedArrays(self, a1, a2):
        if ( len(a1)+len(a2) )%2 == 1:
            return float( Solution.find_1(a1, a2, [0, len(a1)], [0, len(a2)], (len(a1)+len(a2)+1)/2 ) )
            # a = a1+a2
            # a.sort()
            # print a, a[( len(a) )/2]
        else:
            if len(a1) + len(a2) == 0: return None
            if len(a1) == 0:
                return float(sum(a2[ len(a2)/2-1:len(a2)/2+1 ]))/2
            if len(a2) == 0:
                return float(sum(a1[ len(a1)/2-1:len(a1)/2+1 ]))/2
            if len(a1) + len(a2) == 2:
                return float(sum(a1) + sum(a2)) / 2

            if a1[0]<a2[0]:
                mid_r = Solution.find_1(a1, a2, [1, len(a1)], [0, len(a2)], (len(a1)+len(a2))/2 )
            else:
                mid_r = Solution.find_1(a1, a2, [0, len(a1)], [1, len(a2)], (len(a1)+len(a2))/2 )

            if a1[-1]>a2[-1]:
                mid_l = Solution.find_1(a1, a2, [0, len(a1)-1], [0, len(a2)], (len(a1)+len(a2))/2 )
            else:
                mid_l = Solution.find_1(a1, a2, [0, len(a1)], [0, len(a2)-1], (len(a1)+len(a2))/2 )
            # print mid_l, mid_r
            return float(mid_l + mid_r)/2


x=Solution();

a1 = [1, 3, 4 ,5 ,5, 9]
a2 = [1, 1, 1, 1, 1, 10, 10, 10]
a = a1 + a2; a.sort(); print a, float(a[len(a)/2] + a[len(a)/2 - 1])/2 if len(a)%2 == 0 else float(a[len(a)/2])
ans = x.findMedianSortedArrays(a1, a2)
print ans


