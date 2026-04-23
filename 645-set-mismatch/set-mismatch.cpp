class Solution {
public:
    vector<int> findErrorNums(vector<int>& nums) {
        int missing ,duplicate;
        unordered_map<int,int>mp;
        for(int i=0;i<nums.size();i++)
        {
            mp[nums[i]]++;
        }
        for(int i=1;i<=nums.size();i++)
        {
            if(mp[i]==2)
            {
               duplicate=i ;
            }
            if(mp[i]==0)
            {
              missing=i;
            }
        }
        return {duplicate,missing};
    }
};