class Solution {
public:
    bool isPossible(int capable,vector<int>&tasks,vector<int>&workers,int pills,int strength)
    {
        multiset<int>ms(workers.begin(),workers.begin()+capable);
        for(int i=capable-1;i>=0;i--)
        {
            auto it1=prev(ms.end());
            if(*it1>=tasks[i])
            {
                ms.erase(it1);
            }
            else if(pills==0)
            {
                return false;
            }
            else
            {
                int req=tasks[i]-strength;
                auto it2=ms.lower_bound(req);
                if(it2==ms.end())
                {
                    return false;
                }
                ms.erase(it2);
                pills--;
            }
        }
        return true;
    }
    int maxTaskAssign(vector<int>& tasks, vector<int>& workers, int pills, int strength) {
        sort(workers.begin(),workers.end(),greater<int>());
        sort(tasks.begin(),tasks.end());
        int s=0,e=min(tasks.size(),workers.size());
        int ans=s;
        while(s<=e)
        {
            int mid=s+(e-s)/2;
            if(isPossible(mid,tasks,workers,pills,strength))
            {
                ans=mid;
                s=mid+1;
            }
            else
            {
                e=mid-1;
            }
        }
        return ans;
    }
};