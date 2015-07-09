#include <iostream>
#include <climits>
#include <vector>

using namespace std;

class Solution {
public:
    int candy(vector<int>& ratings) {
        int n = ratings.size();
        if(n<=1) return n;

        ratings.insert(ratings.begin(), INT_MAX);
        ratings.push_back(INT_MAX);

        vector<int> candies(ratings.size(), 0);

        int c = 0;
        int sum = 0, cnt = 0;
        while(cnt<n) {
            ++c;
            for(int i = 1; i<=n; ++i) {
                if(ratings[i] == INT_MAX) continue;
                if(ratings[i-1]>=ratings[i] && ratings[i]<=ratings[i+1]) {
                    candies[i] = c;
                    sum += c;
                    ++ cnt;
                }
            }
            for(int i = 1; i<=n; ++i) {
                if(candies[i] == c) ratings[i]=INT_MAX;
            }
        }
        cout << sum << endl;
        return sum;
    }
};

int main() {
    vector<int> ratings;
    int sum = 0;
    for(int i = 12000; i >=1; --i) {
        sum += i;
        ratings.push_back(i);
    }
    cout<<sum<<endl;
    Solution x;
    x.candy(ratings);


    return 0;
}
