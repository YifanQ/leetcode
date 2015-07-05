#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    static int maxProfit_k(int k, vector<int>& prices) {
        int n = prices.size();
        if(n < 2) return 0;
        std::vector<std::vector<int> > f(
            n+1,
            std::vector<int>(k+1, 0) );
        for(int j = 1; j<=k; ++j) {
            int maxv = f[0][j-1] - prices[0]/**/;
            for(int i = 1; i<=n; ++i) {
                // for (i)th Day with prices[i-1]
                if(maxv + prices[i-1]/**/ > f[i-1][j])
                    f[i][j] = maxv + prices[i-1]/**/;
                else
                    f[i][j] = f[i-1][j];
                if(i<n && f[i][j-1]-prices[i]/**/>maxv)
                    maxv = f[i][j-1]-prices[i]/**/;
            }
        }
        cout<<f[n][k]<<endl;
        return f[n][k];
    }
    int maxProfit(vector<int>& prices) {
        return maxProfit_k(2, prices);
    }
};

int main() {
    Solution x;
    // int p[8] = {4, 2, 3, 9, 1, 10, 25, 2};
    int p[8] = {1, 2, 3, 4, 5, 6, 7, 8};

    vector<int> prices(p, p);
    x.maxProfit(prices);
    return 0;
}
