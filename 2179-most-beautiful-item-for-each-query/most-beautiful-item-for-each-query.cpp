class Solution {
public:
    vector<int> maximumBeauty(vector<vector<int>>& items, vector<int>& queries) {
        int n=queries.size();
        vector<int>res;
        sort(items.begin(),items.end());
        int maxBeauty=0;
        for(int i=0;i<items.size();i++)
        {
            maxBeauty=max(maxBeauty,items[i][1]);
            items[i][1]=max(maxBeauty,items[i][1]);
        }
        for(int i=0;i<n;i++)
        {
           int s=0,e=items.size()-1;
           int ans=0;
           while(s<=e)
           {
             int mid=s+(e-s)/2;
              if(items[mid][0]<=queries[i])
              {
                ans=items[mid][1];
                s=mid+1;
              }
              else
              {
                e=mid-1;
              }
           }
           res.push_back(ans);
        }
        return res;
    }
};