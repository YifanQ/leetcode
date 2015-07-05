#include <iostream>
using namespace std;

class Solution {
public:
    uint32_t reverseBits(uint32_t n) {
        uint32_t m=(n&1);
        int i = 31;
        while((n>>=1)) {
            m<<=1;
            m+=(n&1);
            --i;
        }
        m<<=i;  //!!! such bit operator edition like +=
        return m;
    }
};
int main() {
    uint32_t i = 43261596;
    cout<<i<<endl;
    Solution x;
    cout<<x.reverseBits(i)<<endl;  // should be 964176192
    return 0;
}
