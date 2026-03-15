class Solution {
public:
    int maxProfitAssignment(vector<int>& difficulty, vector<int>& profit, vector<int>& worker) {
        long long totalProfit=0;
        priority_queue<pair<int,int>>pq;
        for(int i=0;i<difficulty.size();i++)
        {
            pq.push(make_pair(profit[i],difficulty[i]));
        }
        sort(worker.begin(),worker.end(),greater<int>());
        for(int i=0;i<worker.size();i++)
        {
            while(!pq.empty() && worker[i]<pq.top().second)
            {
                pq.pop();
            }
            if(!pq.empty())
            {
                totalProfit+=pq.top().first;
            }
        }
        return totalProfit;
    }
};