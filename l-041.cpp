// class Solution {
// public:
//     // bin sort
//     int firstMissingPositive(vector<int>& nums) {
//         // swap nums[i] to its location
//         // then sweep
//         int n = nums.size();
//         for(int i=0; i<n; ++i) {
//             // ignore out of range [1,n]
//             // if i is not in place => swap it
//             // when swap if the destination already has the desired value
//             // => set current as zero (replicate)
//             while(nums[i]>0 && nums[i]<=n && nums[i]!=i+1) {
//                 if(nums[nums[i]-1] == nums[i]) {
//                     nums[i]=0;
//                 } else {
//                     swap(nums[nums[i]-1], nums[i]); //when handle [1,1] => TLE
//                 }
//             }
//         }
//         for(int i=0; i<n; ++i)
//             if(nums[i]!=i+1)
//                 return i+1;
//         return n+1;
//     }
// };
#include <iostream>
#include <vector>
#include <algorithm>
#include <cctype>
#include <random>

using namespace std;

class Solution {
public:
    // quick sort
    int firstMissingPositive(vector<int>& nums) {
        // collect all out of range [1,n] values at the end
        int n = nums.size();
        int i = 0, p = n-1;
        while(true) {
            while(i<=p && nums[i]>0 && nums[i]<=n) ++i;
            while(i<=p && !(nums[p]>0 && nums[p]<=n)) --p;
            if(i<p) {
                swap(nums[i], nums[p]); ++i; --p;
            }
            else
                break;
        }
        for(auto &v:nums) cout<<v<<" "; cout<<endl;
        cout<<n<<" "<<p<<endl;

        // process [0, p] array
        return process(nums, 0, p, 1);
    }
    int process(vector<int>& nums, int a, int b, int n0) { // n0 is a+1
        printf("process(%d, %d)\n", a,b);
        if(a>b) return n0;
        if(a==b) return nums[a]==n0?n0+1:n0;

        std::default_random_engine rng;
        std::uniform_int_distribution<int> distribution(a,b);
        // produces random integers in a range [a,b]
        int pivotIndex = distribution(rng);
        printf("with pivot nums[%d] = %d\n", pivotIndex, nums[pivotIndex]);

        int mid = partition(nums, a, b, pivotIndex);

        int m1, m2;
        check_min_max(nums, a, mid, m1, m2);
        if(m1!=n0)
            return n0;
        if(m2!=n0+(mid-a))
            return process(nums, a, mid, a+1);
        else
            return process(nums, mid+1, b, mid+2);
    }
    void check_min_max(vector<int>& nums, int a, int b, int &m1, int &m2) {
        m1 = m2 = nums[a];
        for(int i=a+1; i<=b; ++i) {
            m1 = min(m1, nums[i]);
            m2 = max(m2, nums[i]);
        }
    }

    // 3, 4, (5), 5, 5, 5, 7
    int partition(vector<int>& a, int left, int right, int pivotIndex) {
        int pivotValue = a[pivotIndex];
        swap(a[pivotIndex], a[right]); // 把pivot移到結尾
        int storeIndex = left;
        for(int i = left; i<right; ++i) {
            if (a[i] < pivotValue) {
                swap(a[storeIndex], a[i]);
                storeIndex = storeIndex + 1;
            }
        }
        swap(a[right], a[storeIndex]); // 把pivot移到它最後的地方
        return storeIndex;
    }
};



int main() {
    Solution a;
// {
//     vector<int> nums = {1,-1,3,2,8,10};
//     int res = a.firstMissingPositive(nums);
//     cout<<"> "<<res<<endl;
//     for(auto &v:nums) cout<<v<<" "; cout<<endl;
// }
{
    vector<int> nums = {10,2,3,1,6,5,9};
    int res = a.firstMissingPositive(nums);
    cout<<"> "<<res<<endl;
    for(auto &v:nums) cout<<v<<" "; cout<<endl;
}

cout<<endl<<endl;
{
    int n = 10;
    vector<int> nums;
    for(int i=1;i<=n;++i) nums.push_back(i);
    std::default_random_engine rng(10);
    std::uniform_int_distribution<int> dis1(1,n);
    std::uniform_int_distribution<int> dis2(n+1,10*n);
    // nums.erase(nums.begin()+dis1(rng));
    for(int i=1;i<=n;++i) nums.push_back(dis2(rng));
    shuffle(nums.begin(), nums.end(), rng);

    for(auto &v:nums) cout<<v<<" "; cout<<endl;
    int res = a.firstMissingPositive(nums);
    cout<<"> "<<res<<endl;
    for(auto &v:nums) cout<<v<<" "; cout<<endl;
}

    return 0;
}





 // function partition(a, left, right, pivotIndex)
 // {
 //     pivotValue = a[pivotIndex]
 //     swap(a[pivotIndex], a[right]) // 把pivot移到結尾
 //     storeIndex = left
 //     for i from left to right-1
 //     {
 //         if a[i] < pivotValue
 //          {
 //             swap(a[storeIndex], a[i])
 //             storeIndex = storeIndex + 1
 //          }
 //     }
 //     swap(a[right], a[storeIndex]) // 把pivot移到它最後的地方
 //     return storeIndex
 // }
