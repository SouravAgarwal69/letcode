class Solution {
public:
    vector<int> sumEvenAfterQueries(vector<int>& nums, vector<vector<int>>& queries) {
        vector<int>result;
        int totalSum=0;
        for(int i=0;i<nums.size();i++)
        {
            if(nums[i]%2==0)
            {
              totalSum+=nums[i];
            }
        }
        for(int i=0;i<queries.size();i++)
        {
           if(nums[queries[i][1]]%2==0)
           {
               totalSum-=nums[queries[i][1]];
           }
           nums[queries[i][1]]+=queries[i][0];
           if(nums[queries[i][1]]%2==0)
           {
              totalSum+=nums[queries[i][1]];
           }
             result.push_back(totalSum);
        }
        return result;
    }
};