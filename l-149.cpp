#include <iostream>
#include <unordered_map>
#include <vector>

using namespace std;

struct Point {
    int x;
    int y;
    Point() : x(0), y(0) {}
    Point(int a, int b) : x(a), y(b) {}
};

class Solution {
public:
    //!!! very basic idea with hash table and slope
    int maxPoints(vector<Point>& points) {
        int n = points.size();
        if(n <= 2) return n;

        int result = 0;
        for(int i = 0; i<n; ++i) {
            int x = points[i].x;
            int y = points[i].y;
            int dup = 0;
            int inf_slope = 0;
            unordered_map<float, int> s;
            for(int j = i+1; j<n; ++j) {
                if(points[j].x == x) {
                    if(points[j].y == y) {
                        ++dup;
                    } else {
                        ++inf_slope;
                    }
                    continue;
                }
                float slope = (float)/*TAKE CARE OF THIS!!!*/(points[j].y - y) / (points[j].x - x);
                ++s[slope];
            }

            if(inf_slope + dup + 1 > result)
                result = inf_slope + dup + 1;
            for(auto it = s.begin(); it!=s.end(); ++it)
                if(/*need?*/(*it).second + dup + 1 > result) {
                    result = (*it).second + dup + 1;
                    // printf("%0.3lf %d\n", (*it).first, (*it).second);
                }
        }
        // cout << result <<endl;
        return result;
    }
};

int main() {
    //[[84,250],[0,0],[1,0],[0,-70],[0,-70],[1,-1],[21,10],[42,90],[-42,-230]]
    vector<Point> points;
    points.push_back(Point( 84, 250));
    points.push_back(Point(  0,   0));
    points.push_back(Point(  1,   0));
    points.push_back(Point(  0, -70));
    points.push_back(Point(  0, -70));
    points.push_back(Point(  1,  -1));
    points.push_back(Point( 21,  10));
    points.push_back(Point( 42,  90));
    points.push_back(Point(-42,-230));
    Solution x;
    x.maxPoints(points);

    return 0;
}
