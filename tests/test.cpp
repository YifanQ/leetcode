#include <iostream>
#include <map>
#include <vector>
#include <map>
#include <cmath>

using namespace std;

int main() {
    vector<int> a;
    map<int, int> s;
    for (int i = 0; i < 10; ++ i) {
        int fac = int( double(i) * sin( double(i)*3.6 + 6.0 ) );
        a.push_back(i*fac);
    }
    for (int i = 0; i < 10; ++ i)
    {
        cout << a[i] << " ";
        s[a[i]] = i;
    }
    for (int i = 0; i < 10;)
    return 0;
}
