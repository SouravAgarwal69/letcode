class Solution {
public:
    int minimumRounds(vector<int>& tasks) {
        int maxRounds=0;
        unordered_map<int,int>mp;
        for(int i=0;i<tasks.size();i++)
        {
            mp[tasks[i]]++;
        }
        for(auto it=mp.begin();it!=mp.end();it++)
        {
            if(it->second<2)
            {
                return -1;
            }
            if((it->second)%3==0)
            {
                maxRounds+=(it->second/3);
            }
            else
            {
                maxRounds+=(it->second/3)+1;
            }
        }
        return maxRounds;
    }
};