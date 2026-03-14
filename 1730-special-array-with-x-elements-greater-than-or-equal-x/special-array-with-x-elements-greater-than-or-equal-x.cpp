class Solution {
public:
    int specialArray(vector<int>& nums) {
        sort(nums.begin(),nums.end());
        int s=1,e=nums.size();
        while(s<=e)
        {
            int mid=s+(e-s)/2;
            int index=lower_bound(nums.begin(),nums.end(),mid)-nums.begin();
            int element=nums.size()-index;
            if(element==mid)
            {
                return mid;
            }
            else if(element>mid)
            {
                s=mid+1;
            }
            else
            {
                e=mid-1;
            }
        }
        return -1;
    }
};