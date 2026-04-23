class Solution {
public:
    int largestPerimeter(vector<int>& nums) {
        int largest=0;
        sort(nums.begin(),nums.end());
        for(int i=0;i<nums.size()-2;i++)
        {
            int j=i+1,k=i+2;
            if(nums[i]+nums[j]>nums[k])
            {
                largest=max(largest,nums[i]+nums[j]+nums[k]);
            }
        }
       return largest;
    }
};