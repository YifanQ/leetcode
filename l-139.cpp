#include <iostream>
#include <string>
#include <vector>
#include <unordered_set>
#include <set>


using namespace std;

class Solution {
public:
    bool wordBreak(string s, unordered_set<string>& wordDict) {
        // s = "$" + s;// string append ahead method?
        vector< set<int> > match(s.size() + 1);
        for(auto it = wordDict.begin(); it != wordDict.end(); ++it) {
            int k = (*it).size(), pos = 0, a;
            while((a=s.find(*it, pos)) != string::npos) {
                match[a].insert(a+k);
                pos = a+1; //naive
            }
        }
        vector<bool> f(s.size()+1, false);
        f[0] = true;
        for(int i = 0; i<s.size(); ++i)
            if(f[i])
                for(auto it = match[i].begin(); it!=match[i].end(); ++it) {
                    f[*it] = true;
                    // cout << i<<", "<<*it <<endl;
                }
        return f[s.size()];
    }
};

int main() {
    Solution x;
    unordered_set<string> wordDict;
    wordDict.insert("aaaaa");
    wordDict.insert("aaa");
    for(auto it = wordDict.begin(); it != wordDict.end(); ++it) {
        cout<<*it<<" ";
    }
    cout<<endl;
    cout<<x.wordBreak("aaaaaaaa", wordDict)<<endl;

    return 0;
}
