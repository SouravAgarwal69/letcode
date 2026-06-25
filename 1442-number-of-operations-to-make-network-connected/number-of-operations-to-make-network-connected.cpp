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
    void Union(int x,int y,vector<int>&rank,vector<int>&parent)
    {
        int x_parent=find(x,parent);
        int y_parent=find(y,parent);
        if(x_parent==y_parent)
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
    int makeConnected(int n, vector<vector<int>>& connections) {
        if((n-1)>connections.size())
        {
            return -1;
        }
        int component=n;
        vector<int>parent(n);
        vector<int>rank(n,0);
        for(int i=0;i<n;i++)
        {
            parent[i]=i;
        }
        for(int i=0;i<connections.size();i++)
        {
            int x=connections[i][0];
            int y=connections[i][1];
            int x_parent=find(x,parent);
            int y_parent=find(y,parent);
            if(x_parent==y_parent)
            {
                continue;
            }
            Union(x_parent,y_parent,rank,parent);
           component--;
        }
        return component-1;
    }
};