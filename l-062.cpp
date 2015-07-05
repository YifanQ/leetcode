#include <iostream>
#include <algorithm>

using namespace std;

class Solution {
public:
    int uniquePaths(int m, int n) {
        //Corner case
        if(n==0 || m==0) return 1;
        if(n==1 || m==1) return 1;

        int f[m][n];
        f[0][0] = 1;
        for(int k = 1; k<=m-1+n-1; ++k) {
            for(int i = max(0, k-(n-1)); i<=min(m-1, k); ++i) {
                int j = k-i;
                f[i][j] = 0;
                if(i-1>=0) f[i][j] += f[i-1][j];
                if(j-1>=0) f[i][j] += f[i][j-1];
                cout << i<<" "<< j<<" "<<f[i][j]<<endl;
            }
        }
        return f[m-1][n-1];
    }
};

int main() {
    Solution x;
    cout<<x.uniquePaths(6, 2)<<endl;
    return 0;
}
