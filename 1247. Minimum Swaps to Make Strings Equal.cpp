/*
Weekly Contest 161
*/
#include <iostream>
#include <string>
#include <vector>
#include <cassert>
#include <cstdio>

using namespace std;

class Solution {
public:
    int minimumSwap(string s1, string s2) {
        assert(s1.length() == s2.length());
        int len = s1.length();
        int cnt0[2] = {0, 0}; // x  y
        int cnt1[2] = {0, 0}; // xy yx

        vector<char> s1_, s2_;

        for(int i=0; i<len; ++i) {
            if(s1[i] == s2[i]) {
                continue;
            } else {
                s1_.push_back(s1[i]); s2_.push_back(s2[i]);
                cnt0[0] += int(s1[i] == 'x') + int(s2[i] == 'x');
                cnt0[1] += int(s1[i] == 'y') + int(s2[i] == 'y');
                cnt1[0] += int(s1[i] == 'x' && s2[i] == 'y');
                cnt1[1] += int(s1[i] == 'y' && s2[i] == 'x');
            }
        }

        string s1p(s1_.begin(), s1_.end()), s2p(s2_.begin(), s2_.end());
        // cout << s1p << endl << s2p << endl;
        // printf("x : %d, y : %d, xy : %d, yx : %d\n",
        //        cnt0[0], cnt0[1], cnt1[0], cnt1[1]);

        if( cnt0[0]%2==1 || cnt0[1]%2==1 )
            return -1; // <=> (cnt1[0]+cnt1[1])%2==1
        // remaining two cases: a) cnt1[0] cnt1[1] all even; b) cnt1[0] cnt1[1] all odd
        if( cnt1[0]%2==1 || cnt1[1]%2==1 )
            return (cnt1[0]+cnt1[1])/2+1;
        if( cnt1[0]%2==0 || cnt1[1]%2==0 )
            return (cnt1[0]+cnt1[1])/2;
        return -1;
    }
};

int main() {
    Solution sol;
    string s1 = "xxyyxyxyxx";
    string s2 = "xyyxyxxxyx";

    cout << sol.minimumSwap(s1, s2) << endl;
    return 0;
}



/*
Weekly Contest 161

Minimum Swaps to Make Strings Equal
User Accepted:1726
User Tried:2087
Total Accepted:1783
Total Submissions:3577
Difficulty:Medium
You are given two strings s1 and s2 of equal length consisting of letters "x" and "y" only. Your task is to make these two strings equal to each other. You can swap any two characters that belong to different strings, which means: swap s1[i] and s2[j].

Return the minimum number of swaps required to make s1 and s2 equal, or return -1 if it is impossible to do so.



Example 1:

Input: s1 = "xx", s2 = "yy"
Output: 1
Explanation:
Swap s1[0] and s2[1], s1 = "yx", s2 = "yx".
Example 2:

Input: s1 = "xy", s2 = "yx"
Output: 2
Explanation:
Swap s1[0] and s2[0], s1 = "yy", s2 = "xx".
Swap s1[0] and s2[1], s1 = "xy", s2 = "xy".
Note that you can't swap s1[0] and s1[1] to make s1 equal to "yx", cause we can only swap chars in different strings.
Example 3:

Input: s1 = "xx", s2 = "xy"
Output: -1
Example 4:

Input: s1 = "xxyyxyxyxx", s2 = "xyyxyxxxyx"
Output: 4


Constraints:

1 <= s1.length, s2.length <= 1000
s1, s2 only contain 'x' or 'y'.
*/
