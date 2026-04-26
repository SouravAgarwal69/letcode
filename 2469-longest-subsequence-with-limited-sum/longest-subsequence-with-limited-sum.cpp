class Solution {
public:
    vector<int> answerQueries(vector<int>& nums, vector<int>& queries) {
        vector<int>result;
        sort(nums.begin(),nums.end());
        vector<int>temp(nums.size());
        temp[0]=nums[0];
        for(int i=1;i<nums.size();i++)
        {
            temp[i]=temp[i-1]+nums[i];
        }
        
        for(int i=0;i<queries.size();i++)
        {
          int  idx=upper_bound(temp.begin(),temp.end(),queries[i])-temp.begin();
            result.push_back(idx);
        }
        return result;
    }
};