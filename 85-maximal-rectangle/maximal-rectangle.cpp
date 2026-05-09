class Solution {
public:
    int find(vector<int>&col)
    {
        stack<int>st;
        vector<int>left(col.size());
        vector<int>right(col.size());
        for(int i=0;i<col.size();i++)
        {
            while(!st.empty() && col[st.top()]>=col[i])
            {
                st.pop();
            }
            if(st.empty())
            {
                left[i]=-1;
            }
            else
            {
                left[i]=st.top();
            }
            st.push(i);
        }
        stack<int>st2;
        for(int i=col.size()-1;i>=0;i--)
        {
            while(!st2.empty() && col[st2.top()]>=col[i])
            {
                st2.pop();
            }
            if(st2.empty())
            {
                right[i]=col.size();
            }
            else
            {
                right[i]=st2.top();
            }
            st2.push(i);
        }
        int area=0;
        for(int i=0;i<col.size();i++)
        {
           area=max(area,(right[i]-left[i]-1)*col[i]);
        }
        return area;
    }
    int maximalRectangle(vector<vector<char>>& matrix) {
        int m=matrix.size(),n=matrix[0].size();
        vector<vector<int>>reactangle(m,vector<int>(n));
        vector<int>col(n,0);
        int area=0;
        for(int i=0;i<m;i++)
        {
            for(int j=0;j<n;j++)
            {
                if(matrix[i][j]=='0')
                {
                    col[j]=0;
                }
                else
                {
                    col[j]+=1;
                }
            }
           area=max(area,find(col));
        }
        return area;
    }
};