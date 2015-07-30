#include <iostream>
#include <string>
#include <vector>

using namespace std;

class Solution {
public:
    bool exist(vector< vector<char> >& board, string word) {
        int m = board.size(), n;
        if(m>0) n = board[0].size();
        if(m == 0 || n == 0) return word.empty();
        if(word.empty()) return true;

        for(int i = 0; i<m; ++i)
            for(int j = 0; j<n; ++j)
                if( board[i][j] == word[0] && dfs(0, i, j, board, m, n, word) )
                    return true;
        return false;
    }
    bool dfs(int p, int i, int j, vector< vector<char> >& board, const int&m, const int&n, const string& word) {
        if(word[p] != board[i][j]) return false;
        if(p == word.size()-1) return true; //"a" ["a"]

        char curr = board[i][j];
        board[i][j] = '*';  ///!!a smart way to prevent it from using twice
        if( (i>0 && dfs(p+1, i-1, j, board, m, n, word) ) ||
            (j>0 && dfs(p+1, i, j-1, board, m, n, word) ) ||
           (i<m-1&& dfs(p+1, i+1, j, board, m, n, word) ) ||
           (j<n-1&& dfs(p+1, i, j+1, board, m, n, word) )  )
            return true;
        board[i][j] = curr;
        return false;
    }
};



int main() {

    return 0;
}
