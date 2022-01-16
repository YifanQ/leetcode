/*
Weekly Contest 161
*/
class Solution {
public:
    bool isGoodArray(vector<int>& nums) {
        // 29*a+6*b=1 in WolframAlpha, integer solution
        // a = 6n+5; b=-29n-24
        // if exist any two numbers that their gcd = 1 (Coprime integers)
        // In number theory, two integers a and b are said to be relatively prime, mutually prime,[1] or coprime (also written co-prime) if the only positive integer (factor) that divides both of them is 1

        int len = nums.size();
        if(len == 1)
            return nums[0] == 1;

        // len >= 2
        int gcd0 = gcd(nums[0], nums[1]);
        for(int i = 2; i<len; ++i)
            gcd0 = gcd(gcd0, nums[i]);

        return gcd0 == 1;
    }

    /* https://en.wikipedia.org/wiki/Euclidean_algorithm
    function gcd(a, b)
    while b ≠ 0
       t := b;
       b := a mod b;
       a := t;
    return a;
    */
    int gcd(int a, int b) {
        while(b!=0) {
            int t = b;
            b = a%b;
            a = t;
        }
        return a;
    }
};


/*
1250. Check If It Is a Good Array
User Accepted:563
User Tried:847
Total Accepted:582
Total Submissions:1840
Difficulty:Hard
Given an array nums of positive integers. Your task is to select some subset of nums, multiply each element by an integer and add all these numbers. The array is said to be good if you can obtain a sum of 1 from the array by any possible subset and multiplicand.

Return True if the array is good otherwise return False.



Example 1:

Input: nums = [12,5,7,23]
Output: true
Explanation: Pick numbers 5 and 7.
5*3 + 7*(-2) = 1
Example 2:

Input: nums = [29,6,10]
Output: true
Explanation: Pick numbers 29, 6 and 10.
29*1 + 6*(-3) + 10*(-1) = 1
Example 3:

Input: nums = [3,6]
Output: false


Constraints:

1 <= nums.length <= 10^5
1 <= nums[i] <= 10^9
*/




/*
Read (https://brilliant.org/wiki/bezouts-identity/, https://en.wikipedia.org/wiki/Bézout's_identity)

The basic idea is that for integers a and b, if gcd(a,b) = d, then there exist integers x and y, s.t a * x + b * y = d;

This can be generalized for (n >= 2) . e.g. if gcd(a,b,c) = d, then there exist integers x, y, and z, s.t, a* x + b*y + c * z = d.

Now this problem is just asking if gcd(x1, ......, xn) = 1

class Solution {

public:
    bool isGoodArray(vector<int>& nums) {
        if (nums.size() == 1) return nums[0] == 1;

        int a = nums[0];

        for (int i = 1; i < nums.size(); i++) {
            if (__gcd(a, nums[i]) == 1) return true;
            a = __gcd(a, nums[i]);
        }

        return false;
    }
};
*/
