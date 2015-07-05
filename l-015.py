# class Solution:
#     # @param {integer[]} nums
#     # @return {integer[][]}
#     def threeSum(self, nums):
#         res = []
#         nums.sort();
#         for i in xrange(len(nums)-2):
#             if nums[i] == nums[i+1] == nums[i+2]:
#                 if nums[i] == 0:
#                     res.append([0, 0, 0])
#                 ...

import bisect as bi
# @param {integer[]} nums
# @return {integer[][]}
def threeSum(nums):
    res = []
    nums.sort();
    for i in xrange(len(nums)-2):
        for j in xrange(i+1, len(nums)-1):
            n3 = 0-nums[i]-nums[j]
            k = bi.bisect_left(nums, n3, lo=j+1)
            if k != len(nums) and nums[k] == n3:
                res.append([nums[i], nums[j], n3])
    res.sort()
    f = [0]
    for i in xrange(1,len(res)):
        if(res[i] != res[i-1]):
            f.append(i)
    res = [res[i] for i in f]
    return res

print threeSum([-1, 0, 1, 2, -1, -4])


