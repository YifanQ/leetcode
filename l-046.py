class Solution:
    # @param {integer[]} nums
    # @return {integer[][]}
    def permute(self, nums):
        if len(nums) <= 1:
            return [nums]
        self.result = []
        self.getPermutations(nums, 0)

        print self.result
        return self.result

    def getPermutations(self, nums, i):
        if(i == len(nums)-1):
            self.result.append(nums[:-1] + [nums[-1]])
            return
        else:
            for k in xrange(i, len(nums)):
                nums[i], nums[k] = nums[k], nums[i]

                self.getPermutations(nums, i+1)
                nums[i], nums[k] = nums[k], nums[i]

x = Solution()
x.permute([0, 1])
