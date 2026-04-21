class Solution {
public:
    int trap(vector<int>& height) {
        vector<int>left(height.size());
        vector<int>right(height.size());
        int leftMost=0,rightMost=0,totalWater=0;
        for(int i=0;i<height.size();i++)
        {
            left[i]=leftMost;
            leftMost=max(leftMost,height[i]);
        }
        for(int i=height.size()-1;i>=0;i--)
        {
            right[i]=rightMost;
            rightMost=max(rightMost,height[i]);
        }
        for(int i=0;i<height.size();i++)
        {
            int water=min(left[i],right[i])-height[i];
            if(water>0)
            {
                totalWater+=water;
            }
        }
        return totalWater;
    }
};