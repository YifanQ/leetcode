#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

void rotate(vector<int>& nums, int k) {
    int n = nums.size();
    if(n<=1) return;
    k = k%n;
    if(k==0) return;

    k = n-k;
    // vector<Type>::iterator nth = v.begin() + index;
    vector<int>::iterator kth = nums.begin() + k;
    reverse(nums.begin(), kth);
    reverse(kth, nums.end());
    reverse(nums.begin(), nums.end());
}

int main() {

    return 0;
}
