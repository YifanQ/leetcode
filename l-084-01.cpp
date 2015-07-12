class Solution {
public:
    int largestRectangleArea(vector<int>& height) {
        int n = height.size();
        if(n==0) return 0;
        if(n==1) return height[0];

        height.insert(height.begin(), -1);
        height.push_back(-1);
        int l[n+2], r[n+2];
        int maxArea = 0;

        for(int i = 1; i<=n; ++i) {
            if(height[i] == 0) continue;
            l[i] = i;
            while(height[i] <= height[l[i]-1] )
                l[i] = l[l[i]-1];
        }

        for(int i = n; i>=1; --i) {
            if(height[i] == 0) continue;
            r[i] = i;
            while(height[i] <= height[r[i]+1] )
                r[i] = r[r[i]+1];
        }
        for(int i = 1; i<=n; ++i) {
            if(height[i] == 0) continue;
            if(height[i]*(r[i] - l[i] + 1) > maxArea)
                maxArea = height[i]*(r[i] - l[i] + 1);
        }
        return maxArea;
    }
};
