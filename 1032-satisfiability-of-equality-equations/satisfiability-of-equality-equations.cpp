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
        if(x_parent==y_parent)
        {
            return ;
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
                Union(equations[i][0]-'a',equations[i][3]-'a',parent,rank);
            }
        }
        for(int i=0;i<equations.size();i++)
        {
            if(equations[i][1]=='!')
            {
               if(find(equations[i][0]-'a',parent)==find(equations[i][3]-'a',parent))
               {
                  return false;
               }
            }
        }
        return true;
    }
};