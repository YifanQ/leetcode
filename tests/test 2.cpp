#include <iostream>
using namespace std;

class Solution {
public:
    bool isInterleave(string s1, string s2, string s3) {
        if(s3.size() != s1.size() + s2.size()) return false;
        if(s1.size() > s2.size()) s1.swap(s2);
        // Constant Time Cost
        // http://www.cplusplus.com/reference/string/string/swap/

        bool f[s1.size() + 1];
        f[0] = true;
        for(int i = 1; i <= s1.size(); ++i) {
            if(f[i-1] && s3[i-1] == s1[i-1])
                f[i] = true;
            else
                f[i] = false;
        }

        for(int j = 1; j <= s2.size(); ++j) {
            if(f[0]/**/ && s3[j-1] == s2[j-1])
                f[0] = true;
            else
                f[0] = false;
            for(int i = 1; i <= s1.size(); ++i)
                if(s3[i+j-1] == s2[j-1] && f[i]/**/)
                    f[i] = true;
                else
                    if(s3[i+j-1] == s1[i-1] && f[i-1])
                        f[i] = true;
                    else
                        f[i] = false;
                // f[i][j] = true if s3[i+j+1 -2] == s1[i -1] && f[i-1][j]
                //         = true if s3[i+j+1 -2] == s2[j -1] && f[i][j-1]
                //         = false;
        }
        return f[s1.size()];
    }
};
// Note:
// Notice that a non-member function exists with the same name, swap, overloading
// that algorithm with an optimization that behaves like this member function.
int main() {
    Solution x;
    cout << x.isInterleave("aabcc", "dbbca", "aadbbcbcca")<<endl;
    return 0;
}

