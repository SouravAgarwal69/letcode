class Solution {
public:
    int trap(vector<int>& height) {
        int n=height.size();
        vector<int>leftMax(n);
        vector<int>rightMax(n);
        int leftMaximum=0,rightMaximum=0,totalWater=0;
        for(int i=0;i<height.size();i++)
        {
            leftMax[i]=leftMaximum;
             leftMaximum=max(height[i],leftMaximum);
        }
        for(int i=n-1;i>=0;i--)
        {
            rightMax[i]=rightMaximum;
            rightMaximum=max(rightMaximum,height[i]);
        }
        for(int i=0;i<n;i++)
        {
          int water=min(leftMax[i],rightMax[i])-height[i];
            if(water>0)
            {
                 totalWater+=water;
            }
        }
        return totalWater;
    }
};