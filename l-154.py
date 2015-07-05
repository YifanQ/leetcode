# 0 1 2 4 5 6 7 might become 4 5 6 7 0 1 2
# Follow up for "Find Minimum in Rotated Sorted Array":
# What if duplicates are allowed?

# Would this affect the run-time complexity? How and why?

import math

class Solution:
    # @param {integer[]} nums
    # @return {integer}
    def findMin(self, nums):
        # assert nums is not empty
        offset = 0
        for i in xrange(1, len(nums)):
            if nums[i] == nums[i-1-offset]:
                offset+=1
            else:
                nums[i-offset] = nums[i]
        if len(nums)-offset>1 and nums[0] == nums[-1]: # Note #1: first
            offset+=1
        nums = nums[0:len(nums)-offset]
        print nums

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
l2 = [0, 2, 2, 4, 5, 5, -20, -1, 0]
print l2
print x.findMin(l2)

# [1,2,3,4,5]
# Output:
# 5
# Expected:
# 1

# Note #1: (line 20)
# Runtime Error Message:
# Line 20: ValueError: min() arg is an empty sequence
# Last executed input:
# [1]
# Stdout:
# []

# Runtime Error Message:
# Line 20: ValueError: min() arg is an empty sequence
# Last executed input:
# [1,1]
# Stdout:
# []
