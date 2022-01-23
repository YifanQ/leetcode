#include <iostream>
#include <cstdio>
#include <vector>

using namespace std;

class Solution {
public:
    vector<int> l;
    vector<vector<int>> r;

    vector<vector<int>> combine(int n, int k) {
        // assert(1<=n && k<=n && Cnk <= xx)
        l.resize(k, 0);

        bt(1, 1, n, k);
        return r;
    }

    void bt(int i, int ni, int n, int k) {
    // consider i-th slot with number starting from ni,
    // i = 1,2,3 ...
    // ni = 1,2, .., n
        if (i>k) {
            r.push_back(l);
            return ;
        }
        for(int v = ni; v<=n-k+i; v++) {
            l[i-1] = v;
            bt(i+1, v+1, n,k);
        }
    }
};

https://leetcode.com/problems/combinations/discuss/26992/Short-Iterative-C%2B%2B-Answer-8ms
class Solution {
public:
    vector<vector<int>> combine(int n, int k) {
        vector<vector<int>> result;
        int i = 0;
        vector<int> p(k, 0);
        while (i >= 0) {
            p[i]++;
            if (p[i] > n) --i;
            else if (i == k - 1) result.push_back(p);
            else {
                ++i;
                p[i] = p[i - 1];
            }
        }
        return result;
    }
};

int main() {
    Solution s;
    int n=9, k=5;
    s.combine(n,k);
    for(int i=0; i<s.r.size(); ++i) {
        for(int j=0; j<k; ++j)
            printf("%d ", s.r[i][j]);
        printf("\n");
    }
    return 0;
}
