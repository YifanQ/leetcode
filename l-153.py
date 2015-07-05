# 0 1 2 4 5 6 7 might become 4 5 6 7 0 1 2
import math

class Solution:
    # @param {integer[]} nums
    # @return {integer}
    def findMin(self, nums):
        if len(nums) < 4:
            return min(nums)
        d0 = nums[1] - nums[0]
        d1 = nums[-1] - nums[-2]
        d = nums[0] - nums[-1]
        sign = lambda x: math.copysign(1, x)
        if sign(d0)*sign(d1) > 0:
            if sign(d0)*sign(-d) > 0:
                return nums[0 if sign(d0)==1 else -1]
            # normal cases
            i = 0
            j = len(nums)-1
            if d0 > 0:
                while True:
                    mid = (i+j)/2
                    if nums[mid] > nums[0]:
                        i = mid
                    elif nums[mid] < nums[-1]:
                        j = mid
                    else:
                        print "no way"
                    if i+1 == j:
                        break
                # get [0, i] [i+1, -1]
                return nums[i+1]
            elif d0 < 0:
                while True:
                    mid = (i+j)/2
                    if nums[mid] < nums[0]:
                        i = mid
                    elif nums[mid] > nums[-1]:
                        j = mid
                    else:
                        print "no way"
                    if i+1 == j:
                        break
                # get [0, i] [i+1, -1]
                return nums[i]
            # end normal cases
        else:
            if sign(d)*sign(d0) < 0:
                # nums[0] is single
                # i.e. nums[0] < 1 and -1 or
                #      nums[0] > 1 and -1
                if d1 > 0:
                    return nums[1]
                else:
                    return nums[0]
            elif sign(d)*sign(d1) < 0:
                if d0>0:
                    return nums[-1]
                else:
                    return nums[-2]

x = Solution()
l = [4, 5, 6, 7, 0, 1, 2]
l1 = (l[4:7])[::-1] + (l[0:4])[::-1]
l2 = [1, 2, 3, 4, 5]
print l2[::-1]
print x.findMin(l2[::-1])

# [1,2,3,4,5]
# Output:
# 5
# Expected:
# 1


