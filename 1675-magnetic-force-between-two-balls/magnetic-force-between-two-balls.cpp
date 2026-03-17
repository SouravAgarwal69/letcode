class Solution {
public:
    bool isPossible(int givenForce,vector<int>&position,int m)
    {
        int balls=1;
        int s=0;
        for(int i=1;i<position.size();i++)
        {
            if(position[i]-position[s]>=givenForce)
            {
                balls++;
                s=i;
            }
        }
        return balls>=m;
    }
    int maxDistance(vector<int>& position, int m) {
        sort(position.begin(),position.end());
        int s=0,e=position[position.size()-1]-position[0];
        int ans=0;
        while(s<=e)
        {
           int mid=s+(e-s)/2;
           if(isPossible(mid,position,m))
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