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
        if(x==y)
        {
            return;
        }
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
    bool equationsPossible(vector<string>& equations) {
        vector<int>parent(26);
        vector<int>rank(26);
        for(int i=0;i<26;i++)
        {
            parent[i]=i;
        }
        for(int i=0;i<equations.size();i++)
        {
            if(equations[i][1]=='=')
            {
                int x=find(equations[i][0]-'a',parent);
                int y=find(equations[i][3]-'a',parent);
                Union(x,y,parent,rank);
            }
        }
        for(int i=0;i<equations.size();i++)
        {
            if(equations[i][1]=='!')
            {
                int x=find(equations[i][0]-'a',parent);
                int y=find(equations[i][3]-'a',parent);
                if(x==y)
                {
                    return false;
                }
            }
        }
        return true;
    }
};