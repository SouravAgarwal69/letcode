class Solution {
public:
    int find(int x,vector<int>&parent)
    {
        if(x==parent[x])
        {
            return x;
        }
        return parent[x]=find(parent[x],parent);
    }
    void Union(int x,int y,vector<int>&parent,vector<int>&rank)
    {
         if(rank[x]==rank[y])
         {
            parent[x]=y;
            rank[y]++;
         }
         else if(rank[x]>rank[y])
         {
            parent[y]=x;
         }
         else
         {
            parent[x]=y;
         }
    }
    long long countPairs(int n, vector<vector<int>>& edges) {
        vector<int>parent(n);
        vector<int>rank(n);
        for(int i=0;i<n;i++)
        {
            parent[i]=i;
        }
        for(int i=0;i<edges.size();i++)
        {
            int u=edges[i][0];
            int v=edges[i][1];
            int x=find(u,parent);
            int y=find(v,parent);
                if(x==y)
                {
                    continue;
                }
                Union(x,y,parent,rank);
            }
        unordered_map<int,int>mp;
        for(int i=0;i<n;i++)
        {
            int p=find(i,parent);
            mp[p]++;
        }
        long long result=0;
        int neighbour=n;
        for(auto it=mp.begin();it!=mp.end();it++)
        {
            int size=it->second;
            result=result+(long long) size*(neighbour-size);
            neighbour=neighbour-size;
        }
       return result;
    }
};