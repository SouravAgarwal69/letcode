class Solution {
public:
    vector<int> sumEvenAfterQueries(vector<int>& nums, vector<vector<int>>& queries) {
        vector<int>result;
        int EvenSum=0;
        for(int i=0;i<nums.size();i++)
        {
            if(nums[i]%2==0)
            {
                EvenSum+=nums[i];
            }
        }
        for(int i=0;i<queries.size();i++)
        {
            int val=queries[i][0];
            int index=queries[i][1];
            if(nums[index]%2==0)
            {
                EvenSum-=nums[index];
            }
            nums[index]=nums[index]+val;
            if(nums[index]%2==0)
            {
                EvenSum+=nums[index];
            }
            result.push_back(EvenSum);
        }
        return result;
    }
};