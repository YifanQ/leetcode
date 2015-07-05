#include <iostream>
#include <vector>
#include <algorithm>
#include <cstdio>

using namespace std;

class Solution {
public:
    double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
        vector<int> rec(2, 0);
        int count = nums1.size() + nums2.size();
        if(count%2 == 1) rec = findOdd(nums1,nums2, 0,nums1.size(), 0,nums2.size(), (count+1)/2 );
        //else findEven(nums1,nums2, 0,nums1.size(), 0,nums2.size(), (count)/2 );
        if(rec[0]<nums1.size()) return nums1[rec[0]];
        if(rec[1]<nums2.size()) return nums2[rec[1]];
    }
    static vector<int> findOdd(vector<int>& nums1, vector<int>& nums2,
                               int l1, int r1, int l2, int r2, int rank) {
        printf("%d %d %d %d\n", l1, r1, l2, r2);
        printf("%d\n", rank);
        if(l1+rank < r1) r1 = l1+rank;
        if(l2+rank < r2) r2 = l2+rank;
        if(l1 == r1) {
            vector<int> rec(2,0);
            rec[0] = nums1.size() + r1;
            rec[1] = l2 + rank -1;
            return rec;
        }
        if(l2 == r2) {
            vector<int> rec(2,0);
            rec[0] = l1 + rank - 1;
            rec[1] = nums2.size() + r2;
            return rec;
        }

        if(r1 - l1 > r2- l2) {
            int mid1 = (l1 + r1 - 1)/2;
            int mid2 = std::upper_bound(& nums2[l2], &nums2[r2], nums1[mid1]) - (&nums2[l2]);
            int p = mid1 + 1 - l1 + mid2 - l2;
            if (p<rank) {
                return findOdd(nums1,nums2, mid1 + 1,r1, mid2,r2, rank-p);
            }
            if (p>rank) {
                return findOdd(nums1,nums2, l1, mid1 + 1, l2,mid2, rank);
            }
            if (p == rank) {
                vector<int> rec(2,0);
                rec[0] = mid1;
                rec[1] = nums2.size() + mid2 - 1;
                return rec;
            }
        } else {
            int mid2 = (l2 + r2 - 1)/2;
            int mid1 = std::upper_bound(&nums1[l1], &nums1[r1], nums2[mid2]) - (&nums1[l1]);
            int p = mid2 + 1 - l2 + mid1 - l1;
            if (p<rank) {
                return findOdd(nums1,nums2, mid1,r1, mid2 + 1,r2, rank-p);
            }
            if (p>rank) {
                return findOdd(nums1,nums2, l1, mid1, l2,mid2 + 1, rank);
            }
            if (p == rank) {
                vector<int> rec(2,0);
                rec[0] = nums1.size() + mid1 - 1;
                rec[1] = mid2;
                return rec;
            }
        }

    }

};

int main() {
    Solution a;
    int a1[] = {1, 80, 90};
    int a2[] = {2, 7};
    vector<int> aa1(a1, a1+3), aa2(a2, a2+2);

    cout<<a.findMedianSortedArrays(aa1, aa2)<<endl;
    return 0;
}
