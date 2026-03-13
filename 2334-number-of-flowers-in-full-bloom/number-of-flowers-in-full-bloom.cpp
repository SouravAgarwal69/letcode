class Solution {
public:
    vector<int> fullBloomFlowers(vector<vector<int>>& flowers, vector<int>& people) {
        vector<int>Born(flowers.size());
        vector<int>Die(flowers.size());
        vector<int>result;
        for(int i=0;i<flowers.size();i++)
        {
            Born[i]=flowers[i][0];
            Die[i]=flowers[i][1];
        }
        sort(Born.begin(),Born.end());
        sort(Die.begin(),Die.end());
        for(int i=0;i<people.size();i++)
        {
            int total_start=upper_bound(Born.begin(),Born.end(),people[i])-Born.begin();
            int total_end=lower_bound(Die.begin(),Die.end(),people[i])-Die.begin();
            result.push_back(total_start-total_end);
        }
        return result;
    }
};