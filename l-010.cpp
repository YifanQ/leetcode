#include <iostream>
#include <vector>
#include <cctype>

using namespace std;

class Solution {
public:
    bool isMatch(string s, string p) {
        s = "$" + s;
        p = "$" + modP(p);
        // cout << p << endl<<endl;

        vector<bool> f_1(s.size(), false);
        f_1[0] = true;

        for(int j = 1; j < p.size(); ++j) {
            // for(int i = 0; i <j; ++i) cout<<p[i]<<" ";
            // cout<<endl;
            // for(int i = 0; i <s.size(); ++i) cout<<s[i]<<" ";
            // cout<<endl;
            // for(int i = 0; i <s.size(); ++i) cout<<f_1[i]<<" ";
            // cout<<endl<<endl;

            vector<bool> f(s.size(), false);

            if( p[j] == '.' ) {
                f[0] = false;
                for(int i = 1; i<s.size(); ++i) {
                    if(f_1[i-1]) f[i] = true;
                }
                f_1 = f;
                continue;
            }
            if( islower(p[j]) ) {
                f[0] = false;
                for(int i = 1; i<s.size(); ++i) {
                    if(f_1[i-1] && s[i] == p[j]) f[i] = true;
                }
                f_1 = f;
                continue;
            }
            if(p[j] == ',') {
                f[0] = f_1[0];
                for(int i = 1; i<s.size(); ++i) {
                    if(f[i-1]/*0, 1, ...*/ || f_1[i-1] || f_1[i]) f[i] = true;
                }
                f_1 = f;
                continue;
            }
            if( isupper(p[j]) ) {
                f[0] = f_1[0];
                for(int i = 1; i<s.size(); ++i) {
                    if( f_1[i] ) f[i] = true; /*zero*/
                    else {
                        if((f[i-1] || f_1[i-1]) && p[j] == toupper(s[i])) f[i] = true;
                    }
                }
                f_1 = f;
                continue;
            }
        }
        return f_1[s.size()-1];
    }
    static string modP(string p) {
        string ps = "";
        for(int i = 0; i<p.size(); ) {
            if( i+1<p.size() && p[i+1]=='*' ) {
                if(islower(p[i])) {
                    ps += toupper(p[i]);
                    i += 2;
                    continue;
                }
                if(p[i] == '.') {
                    ps += ',';
                    i += 2;
                    continue;
                }
            }
            ps += p[i]; ++i;
        }
        return ps;
    }
};

int main() {
    Solution x;
    string s = "aasdfasdfasdfasdfas";
    string p = "aasdf.*asdf.*asdf.*asdf.*s";
    cout << x.isMatch(s, p) <<endl;

    return 0;
}
