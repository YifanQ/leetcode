#include <string>
#include <iostream>
// #include <map>
// #include <vector>
using namespace std;
class Solution {
public:
    bool isIsomorphic(string s, string t) {
        int len = s.size();
        if(len!=t.size()) return false;
        if(len==0) return true;

        const int LEN = 128;
        int ms[LEN], mt[LEN], cs, ct;
        for(int c = 0; c<LEN; ++c) {
            ms[c] = 0;
            mt[c] = 0;
        }
        cs = 0; ct = 0;

        for(int i = 0; i<len; ++i) {
            int ss = (int)s[i];
            int tt = (int)t[i];
            if(ms[ss] == 0)
                ms[ss] = ++cs;
            if(mt[tt] == 0)
                mt[tt] = ++ct;
            if(ms[ss] != mt[tt])
                return false;
            cout << ms[ss] <<" "<< mt[tt] <<endl;
        }
        return true;
    }
};

int main() {
    Solution x;
    x.isIsomorphic("ab", "aa");
    return 0;
}
