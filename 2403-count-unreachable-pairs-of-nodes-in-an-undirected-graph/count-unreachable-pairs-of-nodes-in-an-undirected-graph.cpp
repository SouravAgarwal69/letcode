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
        int x_parent=find(x,parent);
        int y_parent=find(y,parent);
        if(x==y)
        {
            return;
        }
        if(rank[x_parent]>rank[y_parent])
        {
            parent[y_parent]=x_parent;
        }
        else if(rank[x_parent]<rank[y_parent])
        {
            parent[x_parent]=y_parent;
        }
        else
        {
            parent[y_parent]=x_parent;
            rank[x_parent]++;
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
            int x=find(edges[i][0],parent);
            int y=find(edges[i][1],parent);
            Union(x,y,parent,rank);
        }
        unordered_map<int,int>mp;
        for(int i=0;i<n;i++)
        {
            int p=find(i,parent);
            mp[p]++;
        }
        int neigh=n;
        long long res=0;
        for(auto it=mp.begin();it!=mp.end();it++)
        {
            int size=it->second;
            res=res+(long long)(neigh-size)*size;
            neigh=neigh-size;
        }
        return res;
    }
};