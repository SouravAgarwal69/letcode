class Solution {
public:
    vector<int> replaceNonCoprimes(vector<int>& nums) {
        vector<int>result;
        for(int i=0;i<nums.size();i++)
        {
            int first=nums[i];
            while(!result.empty())
            {
                int second=result.back();
                int gcd=__gcd(first,second);
                if(gcd==1)
                {
                    break;
                }
                int lcm=(1LL*first*second)/gcd;
                first=lcm;
                result.pop_back();
            }
            result.push_back(first);
        }
        return result;
    }
};