#include <iostream>
using namespace std;

class Solution {
public:
    int rob(vector<int>& nums) {
        if(nums.empty()) return 0;
        int len = nums.size();
        if(len == 1) return nums[0];
        if(len == 2) return max(nums[0], nums[1]);
        if(len == 3) return max( max(nums[0], nums[1]), nums[2] );
        // int s0=0, s1=0;
        // for(int door = 0; door < len; ++ door)
        //     if(door%2 == 0) s0+=nums[door];
        //     else s1+=nums[door];
        // return max(s0, s1);

        int f0, f1;
        //without 0, start from 1 to len-1
        f0=0; f1=nums[1];
        for(int i = 2; i<len; ++i) {
            int f0_tmp = f0;
            f0 = max(f0, f1);
            f1 = f0_tmp + nums[i];
        }
        int ans1 = max(f0, f1);

        //with 0, start from 2 to len-2
        f0=nums[0]; f1 = nums[0] + nums[2];
        for(int i = 3; i<len-1; ++i) {
            int f0_tmp = f0;
            f0 = max(f0, f1);
            f1 = f0_tmp + nums[i];
        }
        int ans2 = max(f0, f1);

        return max(ans1, ans2);
    }
};
int main() {
    Solution x;

    return 0;
}

