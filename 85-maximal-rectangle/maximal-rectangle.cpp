class Solution {
public:
    void findNSE2(vector<int>&temp,vector<int>&right)
    {
        stack<int>st;
        for(int i=temp.size()-1;i>=0;i--)
        {
            while(!st.empty() && temp[st.top()]>=temp[i])
            {
                 st.pop();
            }
            if(st.empty())
            {
                right[i]=right.size();
            }
            else
            {
                right[i]=st.top();
            }
            st.push(i);
        }
    }
    void findNSE1(vector<int>&temp,vector<int>&left)
    {
         stack<int>st;
         for(int i=0;i<temp.size();i++)
         {
              while(!st.empty() && temp[st.top()]>=temp[i])
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
    }
    int findArea(vector<int>&temp)
    {
        vector<int>left(temp.size());
        vector<int>right(temp.size());
        findNSE1(temp,left);
        findNSE2(temp,right);
        int maxArea=0;
        for(int i=0;i<temp.size();i++)
        {
            maxArea=max(maxArea,(right[i]-left[i]-1)*temp[i]);
        }
        return maxArea;
    }
    int maximalRectangle(vector<vector<char>>& matrix) {
        int maxArea=0;
        vector<int>col(matrix[0].size());
        for(int i=0;i<matrix.size();i++)
        {
            for(int j=0;j<matrix[0].size();j++)
            {
                if(matrix[i][j]=='0')
                {
                    col[j]=0;
                }
                else
                {
                    col[j]=col[j]+1;
                }
            }
            maxArea=max(maxArea,findArea(col));
        }
        return maxArea;
    }
};