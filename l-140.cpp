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
        if(s.size() == 0) return result;

        s = "$" + s;
        vector< vector<int> > back(s.size());
        back[0].push_back(0);
        for(int i = 0; i < s.size(); ++i)
            if(!back[i].empty()) {
                string ss = "";
                for(int j = i+1; j < s.size(); ++j) {
                    ss += s[j]; /*add another checking, if it is longer than the longest word in Dict... */
                    if(wordDict.find(ss) != wordDict.end())
                        back[j].push_back(i);
                }
            }
        // for(int i = 0;i <s.size(); ++i) {
        //     cout<<s.substr(0,i+1)<<endl;
        //     for(auto j = back[i].begin(); j!=back[i].end(); ++j) cout<<*j<<" ";
        //     cout<<"]"<<endl;
        // }
        // cout<<endl<<endl;

        int pos = s.size()-1;
        if(back[pos].empty()) return result;

        int stack[s.size()][3], cnt = -1;
        // push
        ++ cnt;
        stack[cnt][2] = 0;              //index
        stack[cnt][0] = back[pos][0];   //start
        stack[cnt][1] = pos;            //end
        while(cnt>=0) {
            if(stack[cnt][0]!=0) {
                //push
                ++ cnt;
                stack[cnt][1] = stack[cnt-1][0];
                stack[cnt][2] = 0;
                stack[cnt][0] = back[stack[cnt-1][0]][0];
                continue;
            }
            else {
                //output
                int len = stack[cnt][1] - stack[cnt][0];
                string res = s.substr(stack[cnt][0]+1, len);
                for(int i=cnt-1; i>=0; --i) {
                    len = stack[i][1] - stack[i][0];
                    res += (" "+s.substr(stack[i][0]+1, len));
                }
                result.push_back(res);
                --cnt;
                while(cnt>=0) {
                    if(stack[cnt][2] < back[ stack[cnt][1] ].size()-1) {
                        stack[cnt][0] = back[ stack[cnt][1] ][ ++stack[cnt][2] ];
                        break;
                    } else {
                        --cnt;
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
    for(auto it = wordDict.begin(); it != wordDict.end(); ++it) {
        // cout<<*it<<" ";
    }
    cout<<endl;

    vector<string> result = x.wordBreak("catsanddog", wordDict);
    for(auto it = result.begin(); it != result.end(); ++it) {
        cout<<*it<<endl;
    }
    cout<<endl;


    return 0;
}

/*
        s = "$" + s;
        vector<bool> f(s.size(), false);
        f[0] = true;
        for(int i = 1; i<s.size(); ++i)
            for(int j = 0; j<i; ++j) {
                if(f[j] && s.)
            }
*/
