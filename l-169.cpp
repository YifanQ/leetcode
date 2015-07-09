#include <iostream>
#include <vector>
#include <algorithm>
#include <cstdlib>
#include <ctime>

using namespace std;

class Solution {
public:
    int majorityElement(vector<int>& nums) {
        srand (time(NULL));
        int n = nums.size();
        // if (n>RAND_MAX)
        // rand() yeild a number [0, 32767]
        while(true) {
            int idx = (double) rand() / RAND_MAX * n; /*not a good rand*/
            // cout<<idx<<endl;
            if( std::count(nums.begin(), nums.end(), nums[idx]) > (n/2) ) {
                // cout<<nums[idx]<<endl;
                return nums[idx];
            }
        }
    }
};

int main() {
    Solution x;
    int nums_[] = {1, 3, 3, 3, 4};
    vector<int> nums(nums_, nums_+5);
    x.majorityElement(nums);
    return 0;
}

/*
From the solution: https://leetcode.com/problems/majority-element/solution/

Runtime: O(n) — Moore voting algorithm:
We maintain a current candidate and a counter initialized to 0.
As we iterate the array, we look at the current element x:
    If the counter is 0, we set the current candidate to x and the counter to 1.
    If the counter is not 0, we increment or decrement the counter based on whether x is the current candidate.
After one pass, the current candidate is the majority element. Runtime complexity = O(n).
*/
