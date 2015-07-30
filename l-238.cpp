class Solution {
public:
    //result[i] = acc(the product of all left items) * result[i] (all right items)
    vector<int> productExceptSelf(vector<int>& nums) {
        int n = nums.size();
        vector<int> result(n);  //!!! remember the vector doesn't check boundary when execute!

        if(nums.empty()) return result;

        int acc = 1;
        for(int i = n-1; i >=0; --i) {
            result[i]=acc;
            acc*=nums[i];  //maybe stop at zero, prevent from the case that all items' product overflow
        }

        acc = 1;
        for(int i = 0; i < n; ++i) {
            result[i]*=acc;
            acc*=nums[i];
        }

        return result;
    }
};
