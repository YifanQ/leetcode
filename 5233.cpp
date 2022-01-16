#include <iostream>
#include <vector>
#include <map>
#include <algorithm>

using namespace std;

class Solution {
public:
    int jobScheduling(vector<int>& startTime, vector<int>& endTime, vector<int>& profit) {
        int n = profit.size();
        if(n == 0) return 0;
        int m;

        // discretize time
        vector<int> t;
        map<int, int> ti;
        map<int, int> it;
        t.insert(t.end(), startTime.begin(), startTime.end());
        t.insert(t.end(), endTime.begin(),   endTime.end());
        sort(t.begin(), t.end());

        std::vector<int>::iterator iter;
        iter = std::unique(t.begin(), t.end());
        t.resize( std::distance(t.begin(),iter) );
        m = t.size();

        // for(int i=0; i<m; ++i) cout<<t[i]<<" "; cout<<endl;
        for(int i=0; i<m; ++i) {
            ti.insert(pair<int,int>(t[i], i));
            it.insert(pair<int,int>(i, t[i]));
        }
        vector<int> st(n,0), et(n,0);
        vector< vector<int> > jobs_et(m);
        vector<int> f(m,0), g(m,0);

        for(int i=0; i<n; ++i) {
            st[i] = ti[startTime[i]]; et[i] = ti[endTime[i]];
            jobs_et[et[i]].push_back(i);
        }
        // cout<<jobs_et.size()<<endl;
        // for(int i=0; i<m; ++i) {
        //     for(int j=0; j<jobs_et[i].size(); ++j)
        //         cout<<jobs_et[i][j]<<" ";
        //     cout<<endl;
        // }
        for(int i=0; i<m; ++i) {
            if(jobs_et[i].size() == 0) {
                g[i] = (i!=0?g[i-1]:f[0]);
                continue;
            }

            for(int j=0; j<jobs_et[i].size(); ++j) {
                int job_id = jobs_et[i][j];
                int f_i = profit[job_id] + g[st[job_id]];
                if(f_i > f[i]) f[i] = f_i;
            }
            g[i] = max(g[i-1], f[i]);
            // cout << f[i] << g[i]<< endl;
        }

        return g[m-1];
    }
};

vector<int> startTime = {1,2,3,4,6}, endTime = {3,5,10,6,9}, profit = {20,20,100,70,60};

int main() {
    Solution s;
    s.jobScheduling(startTime, endTime, profit);

    return 0;
}


/*
1235. Maximum Profit in Job Scheduling

User Accepted:548
User Tried:934
Total Accepted:586
Total Submissions:1809
Difficulty:Hard

We have n jobs, where every job is scheduled to be done from startTime[i] to endTime[i], obtaining a profit of profit[i].

You're given the startTime , endTime and profit arrays, you need to output the maximum profit you can take such that there are no 2 jobs in the subset with overlapping time range.

If you choose a job that ends at time X you will be able to start another job that starts at time X.



Example 1:



Input: startTime = [1,2,3,3], endTime = [3,4,5,6], profit = [50,10,40,70]
Output: 120
Explanation: The subset chosen is the first and fourth job.
Time range [1-3]+[3-6] , we get profit of 120 = 50 + 70.
Example 2:




Input: startTime = [1,2,3,4,6], endTime = [3,5,10,6,9], profit = [20,20,100,70,60]
Output: 150
Explanation: The subset chosen is the first, fourth and fifth job.
Profit obtained 150 = 20 + 70 + 60.
Example 3:



Input: startTime = [1,1,1], endTime = [2,3,4], profit = [5,6,4]
Output: 6


Constraints:

1 <= startTime.length == endTime.length == profit.length <= 5 * 10^4
1 <= startTime[i] < endTime[i] <= 10^9
1 <= profit[i] <= 10^4
*/
