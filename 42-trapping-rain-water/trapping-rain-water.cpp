class Solution {
public:
    int trap(vector<int>& height) {
        vector<int>left(height.size());
        vector<int>right(height.size());
        int maximum=0;
        for(int i=0;i<height.size();i++)
        {
            maximum=max(maximum,height[i]);
            left[i]=maximum;
        }
        maximum=0;
        for(int i=height.size()-1;i>=0;i--)
        {
             maximum=max(maximum,height[i]);
             right[i]=maximum;
        }
        int water=0;
        for(int i=1;i<height.size()-1;i++)
        {
            water+=min(left[i],right[i])-height[i];
        }
        return water;
    }
};