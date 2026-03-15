class Solution {
public:
    int find(vector<pair<int,int>>&vp,int target)
    {
        int s=0,e=vp.size()-1;
        int ans=0;
        while(s<=e)
        {
            int mid=s+(e-s)/2;
            if(vp[mid].first<=target)
            {
                ans=vp[mid].second;
                s=mid+1;
            }
            else
            {
                e=mid-1;
            }
        }
        return ans;
    }
    int maxProfitAssignment(vector<int>& difficulty, vector<int>& profit, vector<int>& worker) {
        int n=profit.size();
        int m=worker.size();
        vector<pair<int,int>>vp;
        for(int i=0;i<n;i++)
        {
            vp.push_back(make_pair(difficulty[i],profit[i]));
        }
        sort(vp.begin(),vp.end());
        int maximum=0;
        for(int i=0;i<n;i++)
        {
            maximum=max(vp[i].second,maximum);
             vp[i].second=maximum;
        }
        int total=0;
        for(int i=0;i<m;i++)
        {
           total+=find(vp,worker[i]);
        }
        return total;
    }
};