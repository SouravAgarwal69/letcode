class Solution {
public:
    int maxProfitAssignment(vector<int>& difficulty, vector<int>& profit, vector<int>& worker) {
        vector<pair<int,int>>vp;
        for(int i=0;i<difficulty.size();i++)
        {
            vp.push_back(make_pair(difficulty[i],profit[i]));
        }
        sort(vp.begin(),vp.end());
        for(int i=1;i<vp.size();i++)
        {
            vp[i].second=max(vp[i-1].second,vp[i].second);
        }
        int total=0;
        for(int i=0;i<worker.size();i++)
        {
            int s=0,e=difficulty.size()-1;
            int ans=0;
            while(s<=e)
            {
                int mid=s+(e-s)/2;
                if(worker[i]>=vp[mid].first)
                {
                    ans=vp[mid].second;
                    s=mid+1;
                }
                else
                {
                    e=mid-1;
                }
            }
            total+=ans;
        }
        return total;
    }
};