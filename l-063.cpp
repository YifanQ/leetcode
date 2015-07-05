#include <iostream>

using namespace std;

class Solution {
public:
    int uniquePathsWithObstacles(vector<vector<int>>& obstacleGrid) {
        //Corner case
        int m=1, n=1;
        m = obstacleGrid.size();
        if(m>0)
            n = obstacleGrid[0].size();
        if(n==0 || m==0)
            return 1;  //!!! more infomation...
        if(obstacleGrid[0][0]==1 || obstacleGrid[m-1][n-1]==1)
            return 0;

        int f[m][n];
        f[0][0] = 1;
        for(int k = 1; k<=m-1+n-1; ++k) {
            for(int i = max(0, k-(n-1))/**/; i<=min(m-1, k); ++i) {
                int j = k-i;
                f[i][j] = 0;
                if(obstacleGrid[i][j]==1) continue;
                if(i-1>=/**/0) f[i][j] += f[i-1][j];
                if(j-1>=0) f[i][j] += f[i][j-1];
            }
        }
        return f[m-1][n-1]/**/;
    }
};

// http://www.wolframalpha.com/input/?i=C%28200%2C+100%29
// C(200, 100) = 90548514656103281165404177077484163874504589675413336841320
int main() {
    Solution x;

    return 0;
}
