class Solution {
public:
    int threeSumClosest(vector<int>& nums, int target) {
        sort(nums.begin(),nums.end());
        int closest=nums[0]+nums[1]+nums[2];
        for(int i=0;i<nums.size()-2;i++)
        {
            int s=i+1,e=nums.size()-1;
            while(s<e)
            {
                int val=nums[i]+nums[s]+nums[e];
                if(abs(closest-target)>abs(target-val))
                {
                    closest=val;
                }
                else if(val<target)
                {
                    s++;
                }
                else
                {
                    e--;
                }
            }
        }
        return closest;
    }
};