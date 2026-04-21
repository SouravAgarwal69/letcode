class Solution {
public:
    int maxArea(vector<int>& height) {
        int s=0,e=height.size()-1;
        int maxWater=0;
        while(s<e)
        {
            maxWater=max(maxWater,min(height[s],height[e])*(e-s));
            if(height[s]<height[e])
            {
                s++;
            }
            else
            {
                e--;
            }
        }
        return maxWater;
    }
};