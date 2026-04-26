class Solution {
public:
    vector<int> answerQueries(vector<int>& nums, vector<int>& queries) {
        vector<int>result;
        sort(nums.begin(),nums.end());
        for(int i=0;i<queries.size();i++)
        {
            int cnt=0,target=queries[i];
            for(int j=0;j<nums.size();j++)
            {
                  if(target>=nums[j])
                  {
                     cnt++;
                     target-=nums[j];
                  }
                  else
                  {
                    break;
                  }
            }
            result.push_back(cnt);
        }
        return result;
    }
};