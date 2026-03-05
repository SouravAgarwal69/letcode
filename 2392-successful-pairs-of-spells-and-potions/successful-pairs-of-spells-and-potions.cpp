class Solution {
public:
   
    vector<int> successfulPairs(vector<int>& spells, vector<int>& potions, long long success) {
        vector<int>ans;
        sort(potions.begin(),potions.end());
        for(int i=0;i<spells.size();i++)
        {
            long long value=(success+spells[i]-1)/spells[i];
            int index=lower_bound(potions.begin(),potions.end(),value)-potions.begin();
            int SuccessFull=potions.size()-index;
            ans.push_back(SuccessFull);
        }
        return ans;
    }
};