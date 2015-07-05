#include <iostream>
using namespace std;

class Solution {
public:
    int rob(vector<int>& nums) {
        if(nums.empty()) return 0;
        int len = nums.size();
        if(len == 1) return nums[0];
        // int s0=0, s1=0;
        // for(int door = 0; door < len; ++ door)
        //     if(door%2 == 0) s0+=nums[door];
        //     else s1+=nums[door];
        // return max(s0, s1);

        int f0=0, f1=nums[0];
        for(int i = 1; i<len; ++i) {
            int f0_tmp = f0;
            f0 = max(f0, f1);
            f1 = f0_tmp + nums[i];
        }
        return max(f0, f1);
    }
};
int main() {
    Solution x;

    return 0;
}

