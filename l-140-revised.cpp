#include <iostream>
#include <string>
#include <vector>
#include <unordered_set>
#include <set>


using namespace std;

class Solution {
public:
    vector<string> wordBreak(string s, unordered_set<string>& wordDict) {
        vector<string> result;
        int len = s.size();
        if(len == 0) return result;  //!
        vector< vector<int> > node(len+1);
        for(int i=0; i<len; ++i) {
            if(i==0 || !node[i].empty()/* can reach the beginning! */) {
                string s_i; /* bool flag, have the later or not*/
                for(int j=i+1; j<=len/**/; ++j) {
                    s_i += s[j-1];
                    if(wordDict.find(s_i) != wordDict.end()) {
                        node[j].push_back(i);
                        // cout<<j<<" "<<i<<endl;
                    }
                }
            }
        }
        if(node[len].empty()) return result;  //!
        int stack[len][3], cnt = 0;

        stack[cnt][0] = node[len][0];   //@len not len+1!!!
        stack[cnt][1] = len;            //node 1st index
        stack[cnt][2] = 0;              //node 2nd index
        while(cnt>=0) {
            if(stack[cnt][0]!=0) {
                int p = stack[cnt][0];
                stack[cnt+1][0] = node[p][0];
                stack[cnt+1][1] = p;
                stack[cnt+1][2] = 0;
                ++cnt;
            } else {
                // before these pos, stack[cnt-1, ... 0][0], we need a space
                int k = cnt-1;
                string res;
                for(int i = 0; i<len; ++i) {
                    if(i==stack[k][0]) {
                        res+=" ";
                        -- k;
                    }
                    res+=s[i];
                }
                result.push_back(res);

                while(cnt>=0) {
                    int idx1 = stack[cnt][1];
                    int idx2 = stack[cnt][2];
                    if( idx2+1 < node[idx1].size()) {
                        stack[cnt][0] = node[idx1][idx2+1];
                        ++ stack[cnt][2];
                        break; /**/
                    } else {
                        -- cnt;
                    }
                }
            }
        }
        return result;
    }
};

int main() {
    Solution x;
    unordered_set<string> wordDict;
    wordDict.insert("cat");
    wordDict.insert("cats");
    wordDict.insert("sand");
    wordDict.insert("and");
    wordDict.insert("dog");

    vector<string> result = x.wordBreak("catsanddog", wordDict);

    for(auto it = result.begin(); it != result.end(); ++it) {
        cout<<*it<<endl;
    }
    cout<<endl;
    return 0;
}
