#include <iostream>
#include <string>
#include <vector>

using namespace std;

class Solution {
public:
    vector<string> fullJustify(vector<string>& words, int maxWidth) {
        vector<string> result;
        if(words.empty()) return result;
        if(words[0].empty()) {
            string spac(maxWidth,' ');
            result.push_back(spac);
            return result;
        }
        // [""], 0
        int i = 0, j = 0;
        while(true) {
            string line;
            int len = -1;
            for(;j<words.size();++j) {
                if(len+words[j].size()+1 <= maxWidth)
                    len+=(words[j].size() + 1);
                else
                    break;
            }
            len = len-(j-i-1);
            if(j-i == 1) {
                line+=words[i];
                int sp = maxWidth-len;
                string spac(sp, ' ');
                line+=spac;
                i = j;
            } else {
                if(j == words.size()) {
                    line+=words[i];
                    int sp = (maxWidth-len-(j-i-1));
                    for(++i;i<j;++i) {
                        line+=" ";
                        line+=words[i];
                    }
                    string spac(sp, ' ');
                    line+=spac;
                }
                else {
                    line+=words[i];
                    int sp = (maxWidth-len)/(j-i-1);
                    int more = (maxWidth-len)%(j-i-1);
                    string spac(sp, ' ');
                    for(++i;i<j;++i) {
                        line+=spac;
                        if(more>0) {
                            line+=" ";
                            --more;
                        }
                        line+=words[i];
                    }
                }
            }
            result.push_back(line);
            if(j==words.size())
                break;
        }
        return result;
    }
};

int main() {
    Solution x;
    vector<string> words;
    words.push_back("This");
    words.push_back("is");
    words.push_back("an");
    words.push_back("example");
    words.push_back("of");
    words.push_back("text");
    words.push_back("justification.");
    words.clear();

    words.push_back("what");
    words.push_back("must");
    words.push_back("be");
    words.push_back("shall");
    words.push_back("be.");
    vector<string> result = x.fullJustify(words, 12);
    for(int i = 0; i<result.size(); ++i)
        cout<<result[i]<<endl;

    return 0;
}
