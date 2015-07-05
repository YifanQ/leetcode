#include <iostream>
#include <cstdio>
#include <vector>

using namespace std;

class Solution {
public:
    int maxProfit(int k, vector<int>& prices) {
        int n = prices.size();
        if(n < 2) return 0;
        if(k>n/2) {
            int ans = 0;
            for (int i=1; i<n; ++i){
                ans += max(prices[i] - prices[i-1],0);
            }
            return ans;
        }
        // std::vector<std::vector<int> > f(
        //     k+1,
        //     std::vector<int>(n+1, 0) );
        // cout<<"capacity: "<<prices.capacity()<<endl;
        // cout<<"size: "<<prices.size()<<endl;
        // prices.insert(prices.begin(), 0);  // modify the input object!!
        // cout<<"capacity: "<<prices.capacity()<<endl;
        // cout<<"size: "<<prices.size()<<endl;
        const int o = 1;

        // vector<int> f0(n+1, 0);
        // vector<int> f1(n+1, 0);
        int f0[n+1];
        int f1[n+1];
        for(int i = 0; i<=n; ++i) {
            f0[i] = 0;
            f1[i] = 0;
        }

        for(int j = 1; j<=k; ++j) {
            f1[0] = 0;
            int maxv = f0[0] - prices[1-o];
            for(int i = 1; i<=n; ++i) {
                // for (i)th Day with prices[i-1]
                if(maxv + prices[i-o] > f1[i-1])
                    f1[i] = maxv + prices[i-o];
                else
                    f1[i] = f1[i-1];
                if(i<n && f0[i]-prices[i+1-o]>maxv)
                    maxv = f0[i]-prices[i+1-o];
            }
            for(int i = 0; i<=n; ++i) f0[i] = f1[i];
        }
        return f1[n];
    }
};

int main() {
    Solution x;
    // int p[8] = {4, 2, 3, 9, 1, 10, 25, 2};
    // int p[9] = {1, 2, 3, 4, 5, 6, 7, 1, 201};
    // vector<int> prices(p, p+9);
    freopen("l-188-1.input","r",stdin);
    vector<int> prices;
    int num;
    while(cin>>num)
        prices.push_back(num);
    cout<<prices.size()<<endl;
    cout<<x.maxProfit(4, prices)<<endl;
    return 0;
}


