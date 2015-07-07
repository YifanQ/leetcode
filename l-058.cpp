#include<iostream>
#include<cmath>
using namespace std;

class Solution {
public:
    double myPow(double x, int n) {
        if(n==0) return 1.0;
        if(x==1.0) return 1.0;
        if(x < 0) {

        }

        long long nn = n;
        // 34.00515, -3
        if(n<0) {
            x = 1.0/x;
            // -1.00000, -2147483648
            nn = -nn;
        }

        long long k = 1;
        while(k <= nn) {
            k<<=1;
        }
        k>>=1;

        double ans = x;
        while(true) {
            // cout<<ans<<endl;
            // cout<<k<<endl;
            k>>=1;
            if(k==0)
                break;
            ans = ans*ans;

            if((k&nn) > 0)
                ans = ans*x;
        }
        cout<<ans<<endl;
        return ans;
    }
};

int main() {
    Solution x;
    x.myPow(-1.00000, -2147483648ll);
    return 0;
}
