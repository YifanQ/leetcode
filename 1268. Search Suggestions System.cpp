/*
Weekly Contest 164
*/
#include <iostream>
#include <cstdio>

#include <string>
#include <vector>
#include <algorithm>

#include <cassert>

using namespace std;

class Solution {
public:
    vector<vector<string>> suggestedProducts(vector<string>& products, string searchWord) {
        vector<string> p(products);
        sort(p.begin(), p.end());

        string prefix, prefix2;
        vector<vector<string>> ans;
        for(int i = 0; i<searchWord.length(); ++i) {
            prefix += searchWord[i];
            prefix2 = prefix + '{';
            auto l = lower_bound (p.begin(), p.end(), prefix); // improvement, reuse l and r here
            auto r = lower_bound (p.begin(), p.end(), prefix2);
            vector<string> ans_i;
            for(;l!=r && ans_i.size()<3;++l) ans_i.push_back(*l);
            ans.push_back(ans_i);
        }
        return ans;
    }
};
//products = ["mobile","moneypot","monitor","mouse","mousepad"], searchWord = "mouse"
//"m" < ["mobile","moneypot","monitor","mouse","mousepad"]
//"mo" < ..
//"mou" < ["mouse", "mousepad"] < "mou{"
// ord('{') = ord('z')+1
// lower_bound, the first element in the range [first,last) which does not compare less than val
// upper_bound, the first element in the range [first,last) which compares greater than val.

int main() {
    Solution sol;
    string s1 = "xyz";
    string s2 = "xy";
    // ("xy" < "xyz")

    // cout << sol.suggestedProducts(s1, s2) << endl;
    cout << (s1 > s2) << endl;
    return 0;
}



/*
1268. Search Suggestions System


User Accepted:1720
User Tried:2026
Total Accepted:1765
Total Submissions:4342
Difficulty:Medium
Given an array of strings products and a string searchWord. We want to design a system that suggests at most three product names from products after each character of searchWord is typed. Suggested products should have common prefix with the searchWord. If there are more than three products with a common prefix return the three lexicographically minimums products.

Return list of lists of the suggested products after each character of searchWord is typed.



Example 1:

Input: products = ["mobile","mouse","moneypot","monitor","mousepad"], searchWord = "mouse"
Output: [
["mobile","moneypot","monitor"],
["mobile","moneypot","monitor"],
["mouse","mousepad"],
["mouse","mousepad"],
["mouse","mousepad"]
]
Explanation: products sorted lexicographically = ["mobile","moneypot","monitor","mouse","mousepad"]
After typing m and mo all products match and we show user ["mobile","moneypot","monitor"]
After typing mou, mous and mouse the system suggests ["mouse","mousepad"]
Example 2:

Input: products = ["havana"], searchWord = "havana"
Output: [["havana"],["havana"],["havana"],["havana"],["havana"],["havana"]]
Example 3:

Input: products = ["bags","baggage","banner","box","cloths"], searchWord = "bags"
Output: [["baggage","bags","banner"],["baggage","bags","banner"],["baggage","bags"],["bags"]]
Example 4:

Input: products = ["havana"], searchWord = "tatiana"
Output: [[],[],[],[],[],[],[]]


Constraints:

1 <= products.length <= 1000
There are no repeated elements in products.
1 <= Σ products[i].length <= 2 * 10^4
All characters of products[i] are lower-case English letters.
1 <= searchWord.length <= 1000
All characters of searchWord are lower-case English letters.
*/
