#include <iostream>
#include <climits>
#include <random>       // std::default_random_engine
#include <algorithm>    // std::random_shuffle
#include <vector>       // std::vector

using namespace std;

class Solution {
public:
    int candy(vector<int>& ratings) {
        int n = ratings.size();
        if(n<=1) return n;

        ratings.insert(ratings.begin(), INT_MAX);
        ratings.push_back(INT_MAX);

        vector<int> candy(ratings.size(), 0);

        for(int i = 1; i<=n; ++i) {
            if(ratings[i-1]>=ratings[i] && ratings[i]<=ratings[i+1]) {
                candy[i] = 1;

                int j = i-1;
                while(j>=1) {
                    if(ratings[j] >= ratings[j+1]) {
                        candy[j] = max( candy[j], candy[j+1] + int(ratings[j]>ratings[j+1]) );
                        //              ________ !=0 just on the boundary
                        //this peak may contains more than one point with equal ratings
                    } else
                        break;
                    --j;
                }
                cout <<j+1<<" "<<i<<" ";
                i = i+1;
                while(i<=n) {
                    if(ratings[i-1] <= ratings[i]) {
                        candy[i] = candy[i-1] + int(ratings[i]>ratings[i-1]);
                    } else
                        break;
                    ++i;
                }
                --i; //for the loop to ++i
                cout <<i<<endl;
            }
        }
        int sum = 0;
        for(int i = 1; i<=n; ++i) {
            cout << candy[i] << " ";
            sum += candy[i];
        }
        cout << endl;
        cout << sum <<endl;
        return sum;
    }
};

int main() {
    // int r_[] = {1, 2, 3, 5, 4, 8, 0, 2, 5};
//  int r_[] = {_, 2, 3, 5, _, 8, _, 2, 5};

    int r_[] = {1, 2, 2};
    vector<int> r(r_, r_+3);
    Solution x;
    x.candy(r);
    return 0;
}


// I got wrong answer here :

// Input: [1,2,2] Output: 5 Expected: 4

// The requirement is : Children with a higher rating get more candies than their neighbors.
// How about equal ratings ? Guys, how do you understand such requirement ?

// Children with a higher rating get more candies than their neighbors.
// An equivalent discription can be: Children get (not more) candies
// than their neighbors has a (not higher) ratings. Since we need the minimum,
// change it as: Children get less candies than their neighbors may has the same rate with them.
