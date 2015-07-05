#include <iostream>
#include <vector>
#include <cmath>
#include <utility>
#include <algorithm>


using namespace std;

bool sort_comp(const std::pair<int, int>& left, const std::pair<int, int>& right) {
    return left.first < right.first;
}
vector<int> twoSum(vector<int>& nums, int target) {
    vector< pair<int, int> > num_index;
    vector<int> result(2, 0);

    for(int i = 0; i < nums.size(); ++i) {
        num_index.push_back( make_pair(nums[i], i) );
    }
    sort(num_index.begin(), num_index.end(), sort_comp);

    int t2 = (int) floor( (double)target/2.0 ), ll = 0, rr = num_index.size()-1;
    for (int i = 0; i < num_index.size(); ++i) {
        if (num_index[i].first == t2) {
            if (t2 + t2 == target /*&& i < num_index.size()-1*/ && num_index[i + 1].first == t2) {
                ll = i;
                rr = i + 1;
                break;
            }
            ll = i;
            rr = i + 1;
            break;
        }
        if(num_index[i].first > t2) {
            ll = i - 1;
            rr = i;
            break;
        }
    }


    while(true) {
        while(ll>0 && num_index[ll].first + num_index[rr].first > target) --ll;
        while(rr<num_index.size()-1 && num_index[ll].first + num_index[rr].first < target) ++rr;
        if(num_index[ll].first + num_index[rr].first == target) {
            if(num_index[ll].second < num_index[rr].second) {
                result[0] = num_index[ll].second;
                result[1] = num_index[rr].second;
            } else {
                result[0] = num_index[rr].second;
                result[1] = num_index[ll].second;
            }
            ++result[0]; ++result[1];
            break;

        }
        if( ll == 0 && rr == nums.size()-1 && num_index[ll].first + num_index[rr].first != target) break;

    }
    return result;
}


int main() {
    int arr[4] = {-3,4,3,90};
    vector<int> a(arr, arr+4);
    twoSum(a, 0);
    return 0;
}
