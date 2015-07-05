# 0 1 2 4 5 6 7 might become 4 5 6 7 0 1 2
import math
import bisect as bi

class Solution:
    # @param {integer[]} nums
    # @param {integer} target
    # @return {integer}
    def search(self, nums, target):
        if len(nums) < 4:
            if target in nums:
                return nums.index(target)
            else:
                return -1
        d0 = nums[1] - nums[0]
        d1 = nums[-1] - nums[-2]
        d = nums[0] - nums[-1]
        sign = lambda x: math.copysign(1, x)
        if sign(d0)*sign(d1) > 0:
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
                idx = bi.bisect_left(nums, target,0, i+1)
                if idx != i+1 and nums[idx] == target:
                    return idx
                idx = bi.bisect_left(nums, target,i+1, len(nums))
                if idx != len(nums) and nums[idx] == target:
                    return idx
                return -1
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
                idx = Solution.bisect_left_descending(nums, target,0, i+1)
                if idx != i+1 and nums[idx] == target:
                    return idx
                idx = Solution.bisect_left_descending(nums, target,i+1, len(nums))
                if idx != len(nums) and nums[idx] == target:
                    return idx
                return -1
            # end normal cases
        else:
            if sign(d)*sign(d0) < 0:
                # nums[0] is single
                # i.e. nums[0] < 1 and -1 or
                #      nums[0] > 1 and -1
                if nums[0] == target:
                    return 0
                if d1 > 0:
                    #ascend
                    idx = bi.bisect_left(nums, target, 1, len(nums))
                    if idx != len(nums) and nums[idx] == target:
                        return idx
                    return -1
                else:
                    #descend
                    idx = Solution.bisect_left_descending(nums, target, 1, len(nums))
                    if idx != len(nums) and nums[idx] == target:
                        return idx
                    return -1
            elif sign(d)*sign(d1) < 0:
                if nums[-1] == target:
                    return len(nums)-1
                if d0>0:
                    #ascend
                    idx = bi.bisect_left(nums, target, 0, len(nums)-1)
                    if idx != len(nums)-1 and nums[idx] == target:
                        return idx
                    return -1
                else:
                    #descend
                    idx = Solution.bisect_left_descending(nums, target, 0, len(nums)-1)
                    if idx != len(nums)-1 and nums[idx] == target:
                        return idx
                    return -1
        print "reach here~"

    @staticmethod  #http://stackoverflow.com/questions/136097/what-is-the-difference-between-staticmethod-and-classmethod-in-python
    def bisect_left_descending(a, x, lo=0, hi=None):
        """Return the index where to insert item x in list a, assuming a is sorted.

        The return value i is such that all e in a[:i] have e < x, and all e in
        a[i:] have e >= x.  So if x already appears in the list, a.insert(x) will
        insert just before the leftmost x already there.

        Optional args lo (default 0) and hi (default len(a)) bound the
        slice of a to be searched.
        """
        if lo < 0:
            raise ValueError('lo must be non-negative')
        if hi is None:
            hi = len(a)
        while lo < hi:
            mid = (lo+hi)//2  # learn a lesson here
            if a[mid] > x: lo = mid+1
            else: hi = mid
        return lo

    # def bi.bisect_left(a, x, lo=0, hi=None):
    # """
    # In the process, [lo, hi) always includes some numbers >= x
    # ...
    # The return value i is such that all e in a[:i] have e < x, and all e in
    # a[i:] have e >= x.
    # """

    # if lo < 0:
    #     raise ValueError('lo must be non-negative')
    # if hi is None:
    #     hi = len(a)
    # while lo < hi:
    #     mid = (lo+hi)//2
    #     if a[mid] < x: lo = mid+1
    #     else: hi = mid
    # return lo

x = Solution()
l = [4, 5, 6, 7, 0, 1, 2]
l1 = (l[4:7])[::-1] + (l[0:4])[::-1]
print l1
print x.search(l1, 7)




