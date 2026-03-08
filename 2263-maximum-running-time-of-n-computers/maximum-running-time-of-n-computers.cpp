class Solution {
public:
    bool isPossible(int n,vector<int>&batteries,long long mid)
    {
        long long time=0;
        for(int i=0;i<batteries.size();i++)
        {
            time=time+min(mid,(long long)batteries[i]);
        }
           return time>=mid*n;
    }
    long long maxRunTime(int n, vector<int>& batteries) {
        long long s=*min_element(batteries.begin(),batteries.end());
        long long total=0;
        for(int i=0;i<batteries.size();i++)
        {
            total+=batteries[i];
        }
        long long e=total/n;
        long long ans=s;
        while(s<=e)
        {
            long long mid=s+(e-s)/2;
            if(isPossible(n,batteries,mid))
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