// Maximal Rectangle
// Given a 2D binary matrix filled with 0's and 1's, find the largest rectangle
// containing all ones and return its area.
#include <iostream>
#include <cstdio>
#include <vector>
using namespace std;

class Solution {
public:
    int maximalRectangle(vector< vector<char> >& matrix) {
        int m, n;
        m = matrix.size();
        if(m > 0)
            n = matrix[0].size();
        if(m==0 || n==0)
            return 0;

        int h[m+2][n+2];
        int i, j;
        i=0;    for(j = 0; j<n+2; ++j) h[i][j]=0;
        i=m+1;  for(j = 0; j<n+2; ++j) h[i][j]=0;
        j=0;    for(i = 0; i<m+2; ++i) h[i][j]=0;
        j=n+1;  for(i = 0; i<m+2; ++i) h[i][j]=0;

        for(i = 1; i<=m; ++i)
            for(j = 1; j<=n; ++j) {
                if(matrix[i-1][j-1] == '1') h[i][j] = h[i-1][j] + 1;
                else h[i][j] = 0;
            }
        int l[n+2], r[n+2];
        int maxArea = 0, maxInfo[5];
        for(i = 1; i<=m; ++i) {
            for(j = 1; j<=n; ++j) {
                if(h[i][j] == 0) continue;
                l[j] = j;
                while( h[i][j] <= h[i][l[j] - 1]) {
                    l[j] = l[l[j]-1];
                }
                //从左到右依次计算每个l[i]：初始时令l[i]=i，然后while h[i]<=h[l[i]-1] do l[i]:=l[l[i]]（h[i]表示第i个建筑物的高度）。
            }
            for(j = n; j>=1; --j) {
                if(h[i][j] == 0) continue;
                r[j] = j;
                while( h[i][j] <= h[i][r[j] + 1]) r[j] = r[r[j]+1];
            }
            for(j = 1; j<=n; ++j) {
                if(h[i][j] == 0) continue;
                if(h[i][j]*(r[j] - l[j] + 1) > maxArea) {
                    maxArea = h[i][j]*(r[j] - l[j] + 1);
                    maxInfo[0] = i;
                    maxInfo[1] = r[j];
                    maxInfo[2] = h[i][j];
                    maxInfo[3] = r[j] - l[j] + 1;
                    maxInfo[4] = j;
                }
            }
        }
        cout << maxInfo[0] <<", "<< maxInfo[1] << endl;
        cout << maxInfo[2] <<", "<< maxInfo[3] << endl;
        cout << maxInfo[4] <<", "<< maxInfo[2] << endl;
        return maxArea;
    }
};

int main() {
    Solution x;
    vector< vector<char> > matrix;
    vector<char> row;
    row.push_back('1');
    row.push_back('1');
    matrix.push_back(row);
    x.maximalRectangle(matrix);
    return 0;
}
