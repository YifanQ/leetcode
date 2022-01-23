#include <iostream>
#include <cstdio>
#include <vector>
#include <algorithm>

using namespace std;

class Solution01 {
public:
    int maxArea(vector<int>& height) {
        int maxA = 0; int i0, i1;

        int n = height.size(); //2 <= n <= 10^5
        int maxh = 0;
        for(int i=0; i<n; ++i)
            maxh = max(maxh, height[i]);
        if(maxh == 0)
            return 0;

        vector<int> f(maxh+1, -1); // f[h] = i, s.t. height[i] >= h and i is smallest
        // if vector<int> f(maxh, -1); generates error like below

        fill(f.begin(), f.end(), -1);
        maxh = 0;
        for(int i=0; i<n; ++i) {
            int area;
            if(height[i] == 0) continue;

            if(height[i] > maxh) { // i.e. f[height[i]] == -1), there is no number before index i >= height[i]
                area = 0;
                // update f
                for(int h = maxh+1; h<=height[i]; ++h)
                    f[h] = i;
                maxh = height[i];
            } else {
                area = (i-f[height[i]])*height[i];
                if(area > maxA) {
                    maxA = area; i0 = f[height[i]]; i1 = i;
                }
            }
        }
        if(maxA > 0)
            printf("%d, [%d,%d] h=(%d,%d)\n", maxA,i0,i1, height[i0], height[i1]);

        vector<int> heigh2(height);
        reverse(heigh2.begin(),heigh2.end());
        // i => n-1-i

        fill(f.begin(), f.end(), -1);
        maxh = 0;
        for(int i=0; i<n; ++i) {
            int area;
            if(heigh2[i] == 0) continue;

            if(heigh2[i] > maxh) { // i.e. f[heigh2[i]] == -1), there is no number before index i >= heigh2[i]
                area = 0;
                // update f
                for(int h = maxh+1; h<=heigh2[i]; ++h)
                    f[h] = i;
                maxh = heigh2[i];
            } else {
                area = (i-f[heigh2[i]])*heigh2[i];
                if(area > maxA) {
                    maxA = area; i1 = n-1-f[heigh2[i]]; i0 = n-1-i;
                }
            }
        }
        if(maxA > 0)
            printf("%d, [%d,%d] h=(%d,%d)\n", maxA,i0,i1, height[i0], height[i1]);
        printf("%d\n", maxA);
        return maxA;
    }
};

/*
=================================================================
==32==ERROR: AddressSanitizer: heap-buffer-overflow on address 0x6030000000c0 at pc 0x00000034647a bp 0x7ffcf3efeb10 sp 0x7ffcf3efeb08
WRITE of size 4 at 0x6030000000c0 thread T0
    #2 0x7fccd1e350b2  (/lib/x86_64-linux-gnu/libc.so.6+0x270b2)
0x6030000000c0 is located 0 bytes to the right of 32-byte region [0x6030000000a0,0x6030000000c0)
allocated by thread T0 here:
    #5 0x7fccd1e350b2  (/lib/x86_64-linux-gnu/libc.so.6+0x270b2)
Shadow bytes around the buggy address:
  0x0c067fff7fc0: 00 00 00 00 00 00 00 00 00 00 00 00 00 00 00 00
  0x0c067fff7fd0: 00 00 00 00 00 00 00 00 00 00 00 00 00 00 00 00
  0x0c067fff7fe0: 00 00 00 00 00 00 00 00 00 00 00 00 00 00 00 00
  0x0c067fff7ff0: 00 00 00 00 00 00 00 00 00 00 00 00 00 00 00 00
  0x0c067fff8000: fa fa 00 00 00 07 fa fa fd fd fd fa fa fa fd fd
=&gt;0x0c067fff8010: fd fd fa fa 00 00 00 00[fa]fa fa fa fa fa fa fa
  0x0c067fff8020: fa fa fa fa fa fa fa fa fa fa fa fa fa fa fa fa
  0x0c067fff8030: fa fa fa fa fa fa fa fa fa fa fa fa fa fa fa fa
  0x0c067fff8040: fa fa fa fa fa fa fa fa fa fa fa fa fa fa fa fa
  0x0c067fff8050: fa fa fa fa fa fa fa fa fa fa fa fa fa fa fa fa
  0x0c067fff8060: fa fa fa fa fa fa fa fa fa fa fa fa fa fa fa fa
Shadow byte legend (one shadow byte represents 8 application bytes):
  Addressable:           00
  Partially addressable: 01 02 03 04 05 06 07
  Heap left redzone:       fa
  Freed heap region:       fd
  Stack left redzone:      f1
  Stack mid redzone:       f2
  Stack right redzone:     f3
  Stack after return:      f5
  Stack use after scope:   f8
  Global redzone:          f9
  Global init order:       f6
  Poisoned by user:        f7
  Container overflow:      fc
  Array cookie:            ac
  Intra object redzone:    bb
  ASan internal:           fe
  Left alloca redzone:     ca
  Right alloca redzone:    cb
  Shadow gap:              cc
==32==ABORTING
*/

class Solution {
public:
    int maxArea(vector<int>& height) {
        int maxA = 0; int i0, i1;

        int n = height.size(); //2 <= n <= 10^5

    }
}

int main() {

    // vector<int> h = {1,8,6,2,5,4,8,3,7};
    // vector<int> h = {1,2,1};
    vector<int> h = {12,1};
    // vector<int> h = {1,7,6,2,5,4,8,3,9};
    Solution s;
    s.maxArea(h);
    return 0;
}
