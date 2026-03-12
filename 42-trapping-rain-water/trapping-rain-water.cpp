class Solution {
public:
    int trap(vector<int>& height) {
        int leftMax=0,rightMax=0;
        int s=0,e=height.size()-1;
        int total=0;
        while(s<e)
        {
            leftMax=max(leftMax,height[s]);
            rightMax=max(rightMax,height[e]);
            if(leftMax<rightMax)
            {
                total+=leftMax-height[s];
                s++;
            }
            else
            {
                total+=rightMax-height[e];
                e--;
            }
        }
        return total;
    }
};