class Solution {
public:
    bool isPossible(vector<int>&piles,int mid,int h)
    {
        long long time=0;
        for(int i=0;i<piles.size();i++)
        {
            time+=((piles[i]+mid-1)/mid);
            if(time>h)
            {
               return false;
            }
        }
        return time<=h;
    }
    int minEatingSpeed(vector<int>& piles, int h) {
        int s=1,e=*max_element(piles.begin(),piles.end());
        int ans=e;
        while(s<=e)
        {
            int mid=s+(e-s)/2;
            if(isPossible(piles,mid,h))
            {
                ans=mid;
                e=mid-1;
            }
            else
            {
                s=mid+1;
            }
        }
        return ans;
    }
};