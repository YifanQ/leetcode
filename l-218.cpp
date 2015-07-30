#include <iostream>
#include <map>
#include <vector>

using namespace std;

class Solution {
public:
    vector< pair<int, int> > getSkyline(vector<vector<int> >& buildings) {
        vector< pair<int, int> > result;
        int n = buildings.size();
        if(n == 0) return result;
        map<int, int> m;

        for(int i = 0; i<n;++i) {
            m[buildings[i][0]] = 0;
            m[buildings[i][1]] = 0;
        }

        map<int, int>::iterator itLow, itUp;
        int currH;

        for(int i = 0; i<n;++i) {
            itLow = m.lower_bound(buildings[i][0]);
            // itUp = m.upper_bound(buildings[i][1]);
            // --itUp;
            itUp = m.lower_bound(buildings[i][1]);
            currH = buildings[i][2];
            for(auto it = itLow; it!=itUp; ++it){
                if(it->second < currH) it->second = currH;
            }
        }


        for(auto it = m.begin(); it!=m.end(); ++it)
            if(it == m.begin() || it->second != result.back().second) {
                // printf("(%d, %d)\n", it->first, it->second);
                result.push_back(pair<int, int>(it->first, it->second));
            }
        return result;

    }
};

int main() {
    // [ [2 9 10], [3 7 15], [5 12 12], [15 20 10], [19 24 8] ]
    const int nb = 0;
    int b_[5][3] = { {2,9,10},{3,7,15},{5,12,12},{15,20,10},{19,24,8} };

    vector< vector<int> > buildings(nb, vector<int>(3));
    for(int i = 0;i<nb;++i)
        for(int j=0;j<3;++j)
            buildings[i][j] = b_[i][j];

    Solution x;
    x.getSkyline(buildings);
    return 0;
}

