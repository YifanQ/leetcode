// l-022.cpp
#include <iostream>
#include <string>

using namespace std;

class Solution {
public:
    string intToRoman(int num) {
        string s;
        if(num <= 0) return s;

        char Roman[4][3] = {{'I','V','X'},{'X','L','C'},{'C','D','M'},{'M',' ',' '}};
        int pos = 1000, n;
        for(int i = 3; i>=0; --i, pos/=10) {
            n = num / pos;
            num = num % pos;
            if(n==0) continue;
            if(n<=3) {
                s+= string(n, Roman[i][0]); continue;
            }
            if(n==4) {
                s+= Roman[i][0]; s+= Roman[i][1];
                continue;
            }
            if(n<=8) {
                s+= Roman[i][1]; s+= string(n-5, Roman[i][0]);
                continue;
            }
            if(n==9) {
                s+= Roman[i][0]; s+= Roman[i][2];
                continue;
            }
        }
        return s;
    }
};
/*!!!
from sequence (5)   string (const char* s, size_t n);
fill (6)            string (size_t n, char c);

(5) from buffer
    Copies the first n characters from the array of characters pointed by s.
(6) fill constructor
    Fills the string with n consecutive copies of character c.
*/

int main() {
    Solution x;
    string s;

    cout << x.intToRoman(3874) << endl;
    return 0;
}
