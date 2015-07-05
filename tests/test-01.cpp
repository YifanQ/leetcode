#include <iostream>
#include <map>
#include <vector>
#include <map>
#include <cmath>

using namespace std;

int main() {
    vector<int> a;
    for(int i = 0; i < 10; ++ i) {
        a.push_back(10 - i);
    }
    cout << *(a.begin() + 1) <<endl;
    sort(a.begin() + 4, a.end());
    for (vector<int>::iterator i = a.begin(); i != a.end(); ++i) {
        cout<<*i<<" ";
    }
    cout<<endl;
    return 0;
}
