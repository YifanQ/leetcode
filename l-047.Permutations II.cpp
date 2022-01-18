class Solution {
public:
    vector<int> used;
    vector<int> p;

    // 1 <= nums.length <= 8
    // -10 <= nums[i] <= 10

    vector<vector<int>> permuteUnique(vector<int>& nums) {
        used.resize(21, 0);
        int n = nums.size();
        vector<vector<int>> res;

        for(auto &v:nums)
            ++used[v+10];

        permute(0, n, res);

        return res;
    }
    void permute(int i, int n, vector<vector<int>> &res) {
        if(i == n) {
            res.push_back(p);
            return ;
        }
        for(int num=-10;num<=+10;++num) { // fixed for loop length || use map to dynamically control the loop size
            if(used[num+10]==0) continue;

            p.push_back(num); --used[num+10];
            permute(i+1, n, res);
            p.pop_back(); ++used[num+10];
        }

    }

};
