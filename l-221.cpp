//!!! http://stackoverflow.com/questions/1887097/variable-length-arrays-in-c
//!!! Variable length arrays in C++?

// void foo(int n) {
//     int values[n]; //Declare a variable length array
// }

class Solution {
public:
    int maximalSquare(vector< vector<char/*!!!*/> >& matrix) {
        int m, n;
        m = matrix.size();
        if(m > 0)
            n = matrix[0].size();
        if(m==0 || n==0)
            return 0;

        int f[m][n];
        int i,j;
        for(i = 0, j = 0; i<m; ++i) {
            if(matrix[i][j] == '0')
                f[i][j] = 0;
            else
                f[i][j] = 1;
        }
        for(i = 0, j = 0; j<n; ++j) {
            if(matrix[i][j] == '0')
                f[i][j] = 0;
            else
                f[i][j] = 1;
        }
        for(int i = 1; i<m; ++i) {
            for(int j = 1; j<n; ++j)
                if(matrix[i][j]=='0')
                    f[i][j] = 0;
                else {
                    f[i][j] = min( min(f[i-1][j], f[i][j-1]), f[i-1][j-1] )+1;
                    assert( f[i-1][j-1] >= min(f[i-1][j], f[i][j-1])-1 );
                }
        }

        int max = 0;
        for(int i = 0; i<m; ++i)
            for(int j = 0; j<n; ++j)
                if(f[i][j] > max)
                    max = f[i][j];
        return max*max; /*return its area*/
    }
};
