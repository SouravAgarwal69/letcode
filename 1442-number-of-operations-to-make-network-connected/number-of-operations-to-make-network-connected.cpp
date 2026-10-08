class Solution {
public:
    int find(int node,vector<int>&parent)
    {
        if(parent[node]==node)
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
            parent[x_parent]=y_parent;
            rank[y_parent]++;
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
        for(int i=0;i<connections.size();i++)
        {
            if(find(connections[i][0],parent)==find(connections[i][1],parent))
            {
                continue;
            }
            Union(connections[i][0],connections[i][1],parent,rank);
        }
        unordered_set<int>component;
        for(int i=0;i<n;i++)
        {
            component.insert(find(parent[i],parent));
        }
        return component.size()-1;
    }
};