class Solution {
public:
    int maxArea(vector<int>& height) {
        int s=0,e=height.size()-1;
         int maximumArea=0;
         while(s<e)
         {
            maximumArea=max(maximumArea,min(height[s],height[e])*(e-s));
            if(height[s]<height[e])
            {
                s++;
            }
            else
            {
                e--;
            }
         }
         return maximumArea;
    }
};