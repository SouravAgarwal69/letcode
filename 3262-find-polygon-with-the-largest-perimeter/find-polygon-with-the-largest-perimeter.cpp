class Solution {
public:
    long long largestPerimeter(vector<int>& nums) {
        long long ans=-1,cumSum=0;
        sort(nums.begin(),nums.end());
        int sides=0;
        for(int i=0;i<nums.size();i++)
        {
            if(sides>=2 && cumSum>nums[i])
            {
                ans=cumSum+nums[i];
            }
            cumSum+=nums[i];
            sides++;
        }
        return ans;
    }
};