class Solution {
public:
    vector<int> fullBloomFlowers(vector<vector<int>>& flowers, vector<int>& people) {
        int n=people.size();
        int m=flowers.size();
        vector<int>result(n);
        vector<int>bloom(m);
        vector<int>dead(m);
        for(int i=0;i<flowers.size();i++)
        {
            bloom[i]=flowers[i][0];
            dead[i]=flowers[i][1];
        }
        sort(bloom.begin(),bloom.end());
        sort(dead.begin(),dead.end());
        for(int i=0;i<n;i++)
        {
            int s=upper_bound(bloom.begin(),bloom.end(),people[i])-bloom.begin();
            int e=lower_bound(dead.begin(),dead.end(),people[i])-dead.begin();
            result[i]=s-e;
        }
        return result;
    }
};