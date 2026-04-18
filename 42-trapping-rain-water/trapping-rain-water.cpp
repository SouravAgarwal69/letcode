class Solution {
public:
    int trap(vector<int>& height) {
        int n=height.size();
        vector<int>left(n);
        vector<int>right(n);
        int maxLeft=0,maxRight=0;
        for(int i=0;i<=height.size()-1;i++)
        {
            maxLeft=max(maxLeft,height[i]);
            left[i]=maxLeft;
        }
        for(int i=n-1;i>=0;i--)
        {
            maxRight=max(maxRight,height[i]);
            right[i]=maxRight;
        }
        int total=0;
        for(int i=1;i<height.size()-1;i++)
        {
            total+=min(left[i],right[i])-height[i];
        }
        return total;
    }
};