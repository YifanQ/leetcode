#include <iostream>
#include <algorithm>
#include <vector>
#include <climits>
#include <cmath>
using namespace std;

class Solution {
public:
    int maximumGap(vector<int>& nums) {
        const int n = nums.size();
        if(n<=1) return 0;
        int maxE = *max_element(nums.begin(), nums.end());
        int minE = *min_element(nums.begin(), nums.end());

        if(maxE - minE<=1) return maxE-minE;
        double len = (double)(maxE - minE);

        int num = n-1;
        vector<int> maxA(num, INT_MIN);
        vector<int> minA(num, INT_MAX);

        // maximal gap must be greater than or equal to len/num
        for(int i=0; i<n; ++i) {
            int index = (double)(nums[i] - minE)/len*num;
            if(index == num)
                --index;
            maxA[index] = max(maxA[index], nums[i]);
            minA[index] = min(minA[index], nums[i]);
        }
        // for(int i = 0; i<num; ++i) {
        //     cout<<( minA[i]==INT_MAX ? -1 : minA[i] )<<" ";
        //     cout<<( maxA[i]==INT_MIN ? -1 : maxA[i] )<<endl;
        // }

        int gap = 0/*(int)ceil(len/num)*/, prev = maxA[0]; /*I am sure it cannot be INT_MIN, since there is minE*/
        for(int i=1; i<num; ++i) {
            if(minA[i] == INT_MAX) continue;
            if(minA[i]-prev/*maxA[i-1]*/>gap) {
                gap = minA[i]-prev;
            }
            prev = maxA[i];
        }
        cout<<gap<<endl;
        return gap;
    }
};

int main() {
    Solution x;
    // int nums_[] = {3478, 3768, 3895, 4388, 6644, 6739, 7817, 7926, 10588, 12439, 15252, 15632, 15728, 16521, 16604, 16764, 16790, 17223, 20124, 20404, 20757, 20880, 21540, 21799, 22101, 22602, 23646, 23688, 23740, 25463, 26155, 26679, 27078, 27963, 30042, 30630, 31799, 32406, 32683};
    // vector<int> nums(nums_, nums_+39);
    int nums_[] = {0, 3, 6, 10};
    vector<int> nums(nums_ , nums_+4);
    x.maximumGap(nums);
    for(int i = 1; i<100; ++i) {
        cout << ((double)(i)/i - 1.0) <<endl;
        cout << ((double)(i)/(double)(i) - 1.0 ) <<endl;
    }
    return 0;
}

c.f.
https://leetcode.com/discuss/36502/my-concise-and-short-c-code-with-comment-explanation
        // note the divide and multiply order and the double cast
        // it's used to avoid the overflow and underflow during calculation
        int index = (double)( nums[i] - minE )  / len * ( n - 1 );

int maximumGap(vector<int>& nums) {
    int n = nums.size();
    if( n < 2 ) return 0;
    int maxE = *max_element(nums.begin(),nums.end());
    int minE = *min_element(nums.begin(),nums.end());

    int len = maxE - minE;
    if( len <= 1 ) return len;
    vector<int> buck_max(n, INT_MIN);
    vector<int> buck_min(n, INT_MAX);

    for(int i = 0; i < n; i++) {
        // note the divide and multiply order and the double cast
        // it's used to avoid the overflow and underflow during calculation
        int index = (double)( nums[i] - minE )  / len * ( n - 1 );
        buck_max[index] = max(buck_max[index], nums[i]);
        buck_min[index] = min(buck_min[index], nums[i]);
    }

    int gap = 0, pre = buck_max[0];
    for(int i = 1; i < n; i++) {
        if( buck_max[i] == INT_MIN ) continue;
        gap = max(gap, buck_min[i] - pre);
        pre = buck_max[i];
    }
    return gap;
}
