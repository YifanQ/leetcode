#include <iostream>
#include <string>

using namespace std;

class Solution {
public:
    bool isScramble(string s1, string s2) {
        if(s1.size() != s2.size()) return false;
        if(s1.empty() && s2.empty()) return true;
        int len = s1.size();
        bool f[len][len][len+1];
        for(int i = 0; i<len; ++i)
            for(int j = 0; j<len; ++j)
                if(s1[i]==s2[j])
                    f[i][j][1]=true;
                else
                    f[i][j][1]=false;
        for(int s = 2; s<=len; ++s) {
            for(int i = 0; i<=len-s; ++i)
                for(int j = 0; j<=len-s; ++j) {
                    f[i][j][s] = false;
                    for(int k = 1; k<=s-1; ++k)
                        if( (f[i][j][k] && f[i+k][j+k][s-k]) ||
                            (f[i][j+s-k][k] && f[i+k][j][s-k]) ) {

                            f[i][j][s] = true;
                            break;
                        }
                }
        }
        return f[0][0][len];
    }
};

int main() {
    Solution x;
    string s1="great", s2="great";
    cout<< x.isScramble(s1, s2)<<endl;
    return 0;
}
