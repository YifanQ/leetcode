class Solution:
    # @param {integer[]} nums
    # @return {integer}
    def radixSort(self, A):
        for k in xrange(10):
            s=[[] for i in xrange(10)]
            for i in A:
                s[i/(10**k)%10].append(i)
            A=[a for b in s for a in b]
        return A

    def maximumGap(self, nums):
        A = self.radixSort(nums)
        ans = 0
        if len(A) == 0: return 0
        prev = A[0]
        for i in A:
            if i - prev > ans: ans = i - prev
            prev = i
        return ans
