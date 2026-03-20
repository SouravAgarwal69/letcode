class Solution {
public:
    int lengthOfLIS(vector<int>& nums) {
        vector<int>result;
        for(int i=0;i<nums.size();i++)
        {
            auto it=lower_bound(result.begin(),result.end(),nums[i]);
            if(it==result.end())
            {
                result.push_back(nums[i]);
            }
            else
            {
                int index=it-result.begin();
                result[index]=nums[i];
            }
        }
        return result.size();
    }
};