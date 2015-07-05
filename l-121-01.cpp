class Solution {
public:
    int maxProfit(vector<int>& prices) {
        if(prices.size() <= 1)
            return 0;
        pair<int, int> min, max, curr;
        if(prices[0] < prices[1]) {
            min = make_pair(prices[0], 0);
            max = make_pair(prices[1], 1);
        } else {
            max = make_pair(prices[0], 0);
            min = make_pair(prices[1], 1);
        }
        for(int i=2; i<prices.size(); ++i) {
            curr = make_pair(prices[i], i);
            if(curr > max) max = curr;
            else if(min > curr) min = curr;
        }
        return max.first - min.first;
    }
};

// Wrong Answer
// Input:
// [2,1]
// Output:
// 1
// Expected:
// 0
