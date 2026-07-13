class Solution {
public:
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
    int find(int node,vector<int>&parent)
    {
        if(node==parent[node])
        {
            return node;
        }
        return parent[node]=find(parent[node],parent);
    }
    int makeConnected(int n, vector<vector<int>>& connections) {
        if(connections.size()<n-1)
        {
            return -1;
        }
        vector<int>parent(n);
        vector<int>rank(n);
        for(int i=0;i<n;i++)
        {
            parent[i]=i;
        }
        int component=n;
        for(int i=0;i<connections.size();i++)
        {
            int x=find(connections[i][0],parent);
            int y=find(connections[i][1],parent);
            if(x==y)
            {
                continue;
            }
            Union(x,y,parent,rank);
            component--;
        }
          return component-1;
    }
};