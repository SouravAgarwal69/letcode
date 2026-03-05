class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        unordered_map<int,int>mp;
        int index1=-1,index2=-1;
        for(int i=0;i<nums.size();i++)
        {
            if(mp.find(target-nums[i])!=mp.end())
            {
                index1=i;
                index2=mp[target-nums[i]];
                break;
            }
            else
            {
                mp[nums[i]]=i;
            }
        }
        return  {index1,index2};
    }
};