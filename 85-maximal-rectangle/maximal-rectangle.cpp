class Solution {
public:
    void findNSE(vector<int>&NSE,stack<int>st,vector<int>&height)
    {
            for(int i=height.size()-1;i>=0;i--)
            {
                while(!st.empty() && height[i]<=height[st.top()])
                {
                    st.pop();
                }
                if(st.empty())
                {
                    NSE[i]=height.size();
                }
                else
                {
                    NSE[i]=st.top();
                }
                st.push(i);
            }
    }
    void findPSE(vector<int>&PSE,stack<int>st,vector<int>&height)
    {
       for(int i=0;i<height.size();i++)
       {
         while(!st.empty() && height[i]<=height[st.top()])
         {
            st.pop();
         }
         if(st.empty())
         {
            PSE[i]=-1;
         }
         else
         {
            PSE[i]=st.top();
         }
         st.push(i);
       }
    }
    int findMaxArea(vector<int>&height)
    {
        int maxArea=0;
        vector<int>NSE(height.size());
        vector<int>PSE(height.size());
        stack<int>st;
        findNSE(NSE,st,height);
        findPSE(PSE,st,height);
        for(int i=0;i<height.size();i++)
        {
            int area=height[i]*(NSE[i]-PSE[i]-1);
            maxArea=max(maxArea,area);
        }
        return maxArea;
    }
    int maximalRectangle(vector<vector<char>>& matrix) {
        int maxArea=0;
        vector<int>height(matrix[0].size());
        for(int i=0;i<matrix.size();i++)
        {
            for(int j=0;j<matrix[i].size();j++)
            {
                if(matrix[i][j]=='0')
                {
                    height[j]=0;
                }
                else
                {
                    height[j]+=1;
                }
            }
            maxArea=max(findMaxArea(height),maxArea);
        }
        return maxArea;
    }
};