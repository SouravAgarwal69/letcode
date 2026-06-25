class Solution {
public:
    int find(int node,vector<int>&parent)
    {
        if(node==parent[node])
        {
            return node;
        }
        return parent[node]=find(parent[node],parent);
    }
    void Union(int x,int y,vector<int>&parent,vector<int>&rank)
    {
        int x_parent=find(x,parent);
        int y_parent=find(y,parent);
        if(x_parent==y_parent)
        {
            return;
        }
        if(rank[x_parent]==rank[y_parent])
        {
            parent[y_parent]=x_parent;
            rank[x_parent]++;
        }
        else if(rank[x_parent]>rank[y_parent])
        {
            parent[y_parent]=x_parent;
        }
        else
        {
            parent[x_parent]=y_parent;
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
            Union(edges[i][0],edges[i][1],parent,rank);
        }
        unordered_map<int,int>mp;
        for(int i=0;i<n;i++)
        {
            int leader=find(i,parent);
            mp[leader]++;
        }
        int neighbour=n;
        long long result=0;
        for(auto it=mp.begin();it!=mp.end();it++)
        {
            int size=it->second;
            result=result+(long long)size*(neighbour-size);
            neighbour=neighbour-size;
        }
        return result;
    }
};