class Solution {
public:
    int trap(vector<int>& height) {
        int left=0,right=height.size()-1;
        int totalWater=0,leftMost=0,rightMost=0;
        while(left<right)
        {
            leftMost=max(leftMost,height[left]);
            rightMost=max(rightMost,height[right]);
            if(leftMost<=rightMost)
            {
               totalWater+=leftMost-height[left];
               left++;
            }
            else
            {
                totalWater+=rightMost- height[right];
                right--;
            }
        }
        return totalWater;
    }
};