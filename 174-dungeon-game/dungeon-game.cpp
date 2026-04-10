class Solution {
public:
    bool isPossible(int i,int j,int mid,vector<vector<int>>&dungeon,unordered_map<string,int>&mp)
    {
           if(i>=dungeon.size() || j>=dungeon[0].size())
           {
              return false;
           }
           string temp=to_string(i)+"_"+to_string(j)+"_"+to_string(mid);
           if(mp.find(temp)!=mp.end())
           {
              return mp[temp];
           }
            mid+=dungeon[i][j];
           if(mid<=0)
           {
              return false;
           }
           if(i==dungeon.size()-1 && j==dungeon[0].size()-1)
           {
                return true;
           }
          
         return mp[temp]=isPossible(i,j+1,mid,dungeon,mp) || isPossible(i+1,j,mid,dungeon,mp);
    }
    int calculateMinimumHP(vector<vector<int>>& dungeon) {
        int s=1,e=4*1e7;
        int result=e;
        unordered_map<string,int>mp;
        while(s<=e)
        {
            int mid=s+(e-s)/2;
            if(isPossible(0,0,mid,dungeon,mp))
            {
                result=mid;
                e=mid-1;
            }
            else
            {
                s=mid+1;
            }
        }
        return result;
    }
};