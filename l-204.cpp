#include <iostream>
#include <cmath>

using namespace std;

class Solution {
public:
    int countPrimes(int n) {
        if(n <= 2) return 0;

        bool f[n];
        for(int i = 2; i<n; ++i) f[i] = true;
        int cnt = n;
        cnt = cnt - 2;  //without n and 1
        cnt = cnt - (n-1)/2 + 1;  //even < n except 2

        int Upper = floor(sqrt( (double)n ));
        for(int i = 3; i<=Upper; i+=2) {
            if(f[i]) {
                cout<<i<<endl;
                for(int k = i*i; k<n; k+=i)
                    if(k&1 == 1 && f[k]) {
                        f[k] = false;
                        --cnt;
                    }
            }
        }
        cout << cnt <<endl;
        return cnt;
    }
};

int main() {
    Solution x;
    x.countPrimes(10000);
    return 0;
}
