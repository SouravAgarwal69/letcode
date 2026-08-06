class Solution {
public:
    int trap(vector<int>& height) {
        vector<int>left(height.size());
        vector<int>right(height.size());
        int maxHeight=height[0];
        for(int i=1;i<height.size();i++)
        {
             maxHeight=max(maxHeight,height[i]);
             left[i]=maxHeight;
        }
        maxHeight=height[height.size()-1];
        for(int i=height.size()-2;i>=0;i--)
        {
            maxHeight=max(maxHeight,height[i]);
            right[i]=max(right[i],maxHeight);
        }
        int total=0;
       for(int i=0;i<height.size();i++)
       {
           int water=min(left[i],right[i])-height[i];
            if(water>0)
            {
                total+=water;
            }
       }
       return total;
    }
};