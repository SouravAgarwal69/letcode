class Solution {
public:
    vector<int> sumEvenAfterQueries(vector<int>& nums, vector<vector<int>>& queries) {
        vector<int>result;
        for(int i=0;i<queries.size();i++)
        {
            nums[queries[i][1]]+=queries[i][0];
            int sum=0;
            for(int i=0;i<nums.size();i++)
            {
                if(nums[i]%2==0)
                {
                    sum+=nums[i];
                }
            }
            result.push_back(sum);
        }
           return result;
    }
};