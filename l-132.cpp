// Given a string s, partition s such that every substring of the partition is a palindrome.

// Return the minimum cuts needed for a palindrome partitioning of s.

// For example, given s = "aab",
// Return 1 since the palindrome partitioning ["aa","b"] could be produced using 1 cut.

#include <iostream>
#include <cstdio>
#include <string>
using namespace std;

class Solution {
public:
    int minCut(string s) {
        int n=s.size();
        if(n<=1) return 0;

        bool isP[n][n];
        int f[n];
        //C.F.
        //http://www.cnblogs.com/lichen782/p/4298615.html
        //http://blog.csdn.net/ljphhj/article/details/22573983
        //
        for(int i = 0; i<n; ++i) {
            f[i] = i;
            for(int j = 0; j<=i; ++j) {
                if(s[j] == s[i] && (i-j <= 1 || isP[j+1][i-1])) {
                    isP[j][i] = true;
                    // printf("%d %d %s\n", j, i, s.substr(j, i+1-j).c_str());
                    if(j>0) {
                        f[i] = min(f[i], f[j-1]+1);
                    } else {
                        f[i] = 0;
                    }
                } else {
                    isP[j][i] = false;
                }
            }
        }
        return f[n-1];
    }
};

int main() {
    string s = "cabababcbc";
    Solution x;
    cout << x.minCut(s) <<endl;
    return 0;
}


// 0 0 c
// 1 1 a
// 2 2 b
// 1 3 aba
// 3 3 a
// 2 4 bab
// 4 4 b
// 1 5 ababa
// 3 5 aba
// 5 5 a
// 2 6 babab
// 4 6 bab
// 6 6 b
// 0 7 cabababc 不初始化的恶果！！！
// 7 7 c
// 2 8 bababcb
// 4 8 babcb
// 6 8 bcb
// 8 8 b
// 0 9 cabababcbc
// 7 9 cbc
// 9 9 c
// 0
