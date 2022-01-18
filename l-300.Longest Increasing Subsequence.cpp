// return the length of the longest strictly increasing subsequence.
class Solution {
public:
    int lengthOfLIS(vector<int>& nums) {
        int max_l = 0;
        map<int, int> f;
        for(int i=0;i<nums.size();++i) {
            auto lb = f.lower_bound(nums[i]);
            int max_f = 0;
            for(auto it=f.begin(); it!=lb; ++it) { // make it O(n^2)
                max_f = max(max_f, it->second);
            }
            // only insert will cause error for the case listed below
            // f.insert(make_pair(nums[i], max_f+1));
            if(f.find(nums[i]) == f.end())
                f.insert(make_pair(nums[i], max_f+1));
            else
                f[nums[i]] = max(f[nums[i]], max_f+1);
            max_l = max(max_l, max_f+1);
        }
        return max_l;
    }
};

// [10,9,2,5,3,7,101,18] => 4
// [3,5,6,2,5,4,19,5,6,7,12] => 5, should be 6


// Follow up: Can you come up with an algorithm that runs in O(n log(n)) time complexity?

https://leetcode.com/problems/longest-increasing-subsequence/discuss/1326308/C%2B%2BPython-DP-Binary-Search-BIT-Solutions-Picture-explain-O(NlogN)
https://zh.wikipedia.org/wiki/%E6%9C%80%E9%95%BF%E9%80%92%E5%A2%9E%E5%AD%90%E5%BA%8F%E5%88%97

class Solution { // 8 ms, faster than 91.61%
public:
    int lengthOfLIS(vector<int>& nums) {
        vector<int> sub;
        for (int x : nums) {
            if (sub.empty() || sub[sub.size() - 1] < x) {
                sub.push_back(x);
            } else {
                auto it = lower_bound(sub.begin(), sub.end(), x); // Find the index of the smallest number >= x
                *it = x; // Replace that number with x
            }
        }
        return sub.size();
    }
};

class Solution:  # 68 ms, faster than 93.92%
    def lengthOfLIS(self, nums: List[int]) -> int:
        sub = []
        for x in nums:
            if len(sub) == 0 or sub[-1] < x:
                sub.append(x)
            else:
                idx = bisect_left(sub, x)  # Find the index of the smallest number >= x
                sub[idx] = x  # Replace that number with x
        return len(sub)

