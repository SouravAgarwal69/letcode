class Solution {
public:
    vector<int> replaceNonCoprimes(vector<int>& nums) {
        vector<int>result;
        for(int i=0;i<nums.size();i++)
        {
            int curr=nums[i];
            while(!result.empty())
            {
                int gcd=__gcd(result.back(),curr);
                if(gcd!=1)
                {
                     curr=(1LL*result.back()*curr)/gcd;
                      result.pop_back();
                }
                else
                {
                    break;
                }
            }
            result.push_back(curr);
        }
        return result;
    }
};