5232. Replace the Substring for Balanced String

User Accepted:444
User Tried:1543
Total Accepted:451
Total Submissions:2744
Difficulty:Medium

You are given a string containing only 4 kinds of characters 'Q', 'W', 'E' and 'R'.

A string is said to be balanced if each of its characters appears n/4 times where n is the length of the string.

Return the minimum length of the substring that can be replaced with any other string of the same length to make the original string s balanced.

Return 0 if the string is already balanced.



Example 1:

Input: s = "QWER"
Output: 0
Explanation: s is already balanced.
Example 2:

Input: s = "QQWE"
Output: 1
Explanation: We need to replace a 'Q' to 'R', so that "RQWE" (or "QRWE") is balanced.
Example 3:

Input: s = "QQQW"
Output: 2
Explanation: We can replace the first "QQ" to "ER".
Example 4:

Input: s = "QQQQ"
Output: 3
Explanation: We can replace the last 3 'Q' to make s = "QWER".


Constraints:

1 <= s.length <= 10^5
s.length is a multiple of 4
s contains only 'Q', 'W', 'E' and 'R'.

class Solution {
public:
    int balancedString(string s) {
        int n = s.size();
        int n4 = n/4;
        vector<int> c(4,0);
        for(int i=0;i<n;++i)
            switch (s[i]) {
                case 'Q': ++c[0]; break;
                case 'W': ++c[1]; break;
                case 'E': ++c[2]; break;
                case 'R': ++c[3]; break;
            }
        cout<<n4<<endl;
        cout<<c[0]<<" "<<c[1]<<" "<<c[2]<<" "<<c[3]<<endl;
        int sum = 0;
        for(int i=0;i<4;++i) {
            if(c[i] > n4)
                sum+=c[i]-n4;
        }
        return sum;
        // Return the minimum length of the substring
        // that can be replaced with any other string of the same length to make the original string s balanced.
        // "WWEQERQWQWWRWWERQWEQ"
    }
};
