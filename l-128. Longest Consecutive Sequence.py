class Solution:
    def longestConsecutive(self, nums: List[int]) -> int:
        res = 0
        s = set(nums)

        n = len(nums)
        for i in range(n):
            num = nums[i]
            if num - 1 not in s:
                r = 1;
                while num+r in s:
                    r+=1
                res = max(res, r)
        return res
# initially, only sort come to my mind
# the solution suggests to use hash table (set(in python) or unordered_set) to check the consecutive numbers
# Wrong: I set up a visited array to see if a number has been visited
# Fixed Way I: use a dict with all key init to False instead of set to save which is visited
# Fixed Way II: only start the search from the smallest number

#     def longestConsecutive(self, nums: List[int]) -> int:
#         res = 0
#         s = set(nums)

#         n = len(nums)
#         vi = [False]*n
#         for i in range(n):
#             num = nums[i]
#             if not vi[num]:
#                 vi[num] = True
#                 l = 1; r = 1;
#                 while num-l in s:
#                     vi[num-l] = True
#                     l+=1
#                 while num+r in s:
#                     vi[num+r] = True
#                     r+=1
#                 res = max(res, l+r-1)
#         return res

    def longestConsecutive(self, nums: List[int]) -> int:
        res = 0
        s = {}.fromkeys(nums, False)
        # The fromkeys() method returns a dictionary with the specified keys and the specified value.

        n = len(nums)
        for i in range(n):
            num = nums[i]
            if not s[num]:
                s[num] = True
                l = 1; r = 1;
                while num-l in s:
                    s[num-l] = True
                    l+=1
                while num+r in s:
                    s[num+r] = True
                    r+=1
                res = max(res, l+r-1)
        return res


