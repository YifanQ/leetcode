#include <iostream>
#include <string>
#include <vector>
#include <algorithm>

using namespace std;

class Solution {
public:
    vector<string> findWords(vector< vector<char> >& board, vector<string>& words) {
        vector<string> result;

        int m = board.size(), n;
        if(m>0) n = board[0].size();

        sort(words.begin(), words.end());
        int sum_len = 0, offset = 0;
        for(int i = 0; i<words.size(); ++i)
            if(   words[i].empty() ||
                ( i-1-offset >= 0 && words[i] == words[i-1-offset] ) ) {
                ++offset;
            } else {
                sum_len += words[i].size();
                if(offset>0) words[i-offset] = words[i];
            }
        if(offset>0) words.resize(words.size()-offset);
        bool no_word = (sum_len == 0);

        if(m == 0 || n == 0) return result; // return no_word;
        if(no_word) return result; // return true;

        int W = words.size();
        vector<bool> found(W, false);
        for(int i = 0; i<m; ++i)
            for(int j = 0; j<n; ++j)
                for(int k = 0; k<W; ++k) {
                    string aword = words[k];
                    if( !found[k] && board[i][j] == aword[0] && dfs(0, i, j, board, m, n, aword) ) {
                        result.push_back(aword);
                        found[k] = true;
                    }
                }
        return result;
    }
    bool dfs(int p, int i, int j, vector< vector<char> >& board, const int&m, const int&n, const string& word) {
        if(word[p] != board[i][j]) return false;
        if(p == word.size()-1) return true; //"a" ["a"]

        char curr = board[i][j];
        board[i][j] = '*';  ///!!a smart way to prevent it from using twice
        bool result = ( (i>0 && dfs(p+1, i-1, j, board, m, n, word) ) ||
            (j>0 && dfs(p+1, i, j-1, board, m, n, word) ) ||
           (i<m-1&& dfs(p+1, i+1, j, board, m, n, word) ) ||
           (j<n-1&& dfs(p+1, i, j+1, board, m, n, word) )  );
        board[i][j] = curr;
        return result;
    }
};



int main() {

    return 0;
}
