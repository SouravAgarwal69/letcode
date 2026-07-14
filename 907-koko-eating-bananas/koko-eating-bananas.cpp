class Solution {
public:
    bool isPossible(int mid,vector<int>&piles,int givenHr)
    {
        long long hr=0;
        for(int i=0;i<piles.size();i++)
        {
            hr+=(piles[i]+mid-1)/mid;
            if(hr>givenHr)
            {
                return false;
            }
        }
        return hr<=givenHr;
    }
    int minEatingSpeed(vector<int>& piles, int h) {
        int e=*max_element(piles.begin(),piles.end()),s=1;
        int ans=e;
        while(s<=e)
        {
            int mid=s+(e-s)/2;
            if(isPossible(mid,piles,h))
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