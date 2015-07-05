#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int d = 0, max = 0, mb, ms, buy, sell;
        for(int i = 1; i<prices.size(); ++i) {
            if(d > 0) {
                d = d + prices[i] - prices[i-1];
            }
            else {
                d = prices[i] - prices[i-1];
                buy = i-1;
            }
            sell = i;
            if(d > max) {
                max = d; mb = buy; ms = sell;
            }
        }
        cout << mb <<" "<< ms <<endl;
        return max;
    }
};

int main() {
    Solution x;
    int p[8] = {4, 2, 3, 9, 1, 10, 25, 2};
    vector<int> prices(p, p+8);
    x.maxProfit(prices);
    return 0;
}
