5230. Check If It Is a Straight Line
You are given an array coordinates, coordinates[i] = [x, y], where [x, y] represents the coordinate of a point. Check if these points make a straight line in the XY plane.

Constraints:

2 <= coordinates.length <= 1000
coordinates[i].length == 2
-10^4 <= coordinates[i][0], coordinates[i][1] <= 10^4
coordinates contains no duplicate point.

class Solution {
public:
    bool checkStraightLine(vector<vector<int>>& coordinates) {
        vector<vector<int>> &co = coordinates;
        int num = co.size();
        if(num >= 3)
            for(int i=2; i<num; ++i)
                if(cross(co[0], co[1], co[i]) != 0)
                    return false;
        return true;
    }
    int cross(vector<int> &a, vector<int> &b, vector<int> &c) {
        // ab x ac
        return (b[0]-a[0])*(c[1]-a[1])-(b[1]-a[1])*(c[0]-a[0]);
    }
};
