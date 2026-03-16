class Solution {
public:
    int maxProfitAssignment(vector<int>& difficulty, vector<int>& profit, vector<int>& worker) {
        int n=difficulty.size();
        vector<pair<int,int>>vp;
        for(int i=0;i<difficulty.size();i++)
        {
            vp.push_back(make_pair(difficulty[i],profit[i]));
        }
        sort(vp.begin(),vp.end());
        sort(worker.begin(),worker.end());
        int maxProfit=0;
        long long total=0;
        int i=0,j=0;
        while(j<worker.size() )
        {
           while(i<n && worker[j]>=vp[i].first)  
           {
               maxProfit=max(vp[i].second,maxProfit);
               i++;
           }
              total+=maxProfit;
              j++;          
        }
        return total;
    }
};