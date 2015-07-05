// Longest Palindromic Substring
#include <iostream>
#include <algorithm>
#include <string>
#include <cassert>

using namespace std;

class Solution {
public:
    string longestPalindrome(string s) {
        string res;
        if(s.empty()) return res;

        string ss = getNew(s);
        // cout<<ss<<endl;
        int p[3000], id, mx;

        p[1] = 1; id = 1; mx = id + p[id];
        for(int i=2; i<ss.size()-1; ++i) {
            if(mx > i)
                p[i] = min(p[2*id-i], mx-i);
            else
                p[i] = 1;
            while(ss[i + p[i]] == ss[i-p[i]])
                ++p[i];
            if(i + p[i] > mx) {
                id = i;
                mx = i + p[i];
            }
        }

        mx = 0;
        id = 2;
        for(int i = 2; i</*=*/ss.size()-1; ++i) {  //!!! if with this =, some unexpected wrong will happen!
            if(p[i] > mx) {
                id = i;
                mx = p[i];
            }
        }
        mx = mx - 1;
        // assert( !(mx%2 == 0) || (ss[id]=='#') );
        // cout<<ss.substr(id-mx, mx*2+1)<<endl;

        int i = id/2-1 - (mx-1)/2;
        return s.substr(i, mx);
        ;
    }
    string getNew(const string &s) {
        string res="$";
        res += '#';
        for(int i=0; i<s.size(); ++i) {
            res += s[i];
            res += '#';
        }
        return res;
    }
};

int main() {
    Solution x;
    string s = "madam";
    cout<<x.longestPalindrome(s)<<endl;
    return 0;
}
