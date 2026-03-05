class Solution {
public:
    int Bs(int value,vector<int>&potions,long long success)
    {
        int s=0,e=potions.size()-1,ans=potions.size();
        while(s<=e)
        {
            int mid=s+(e-s)/2;
            if(1LL*potions[mid]*value>=success)
            {
               ans=mid;
               e=mid-1;
            }
            else
            {
                s=mid+1;
            }
        }
        return potions.size()-ans;
    }
    vector<int> successfulPairs(vector<int>& spells, vector<int>& potions, long long success) {
        vector<int>ans;
        sort(potions.begin(),potions.end());
        for(int i=0;i<spells.size();i++)
        {
            int SuccessFull=Bs(spells[i],potions,success);
            ans.push_back(SuccessFull);
        }
        return ans;
    }
};