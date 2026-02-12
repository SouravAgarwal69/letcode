class Solution {
public:
    void findNSL(vector<int>&heights,vector<int>&NSL,stack<int>st)
    {
          for(int i=0;i<heights.size();i++)
          {
             while(!st.empty() && heights[i]<=heights[st.top()])
             {
                st.pop();
             }
             if(st.empty())
             {
                NSL[i]=-1;
             }
             else
             {
                NSL[i]=st.top();
             }
             st.push(i);
          }
    }
    void findNSR(vector<int>&heights,vector<int>&NSR,stack<int>st)
    {
         for(int i=heights.size()-1;i>=0;i--)
         {
            while(!st.empty() && heights[st.top()]>=heights[i])
            {
                st.pop();
            }
            if(st.empty())
            {
                NSR[i]=heights.size();
            }
            else
            {
                NSR[i]=st.top();
            }
            st.push(i);
         }
    }
    int largestRectangleArea(vector<int>& heights) {
        vector<int>NSL(heights.size());
        vector<int>NSR(heights.size());
        stack<int>st;
        findNSL(heights,NSL,st);
        findNSR(heights,NSR,st);
        int maxArea=0;
        for(int i=0;i<heights.size();i++)
        {
            int area=heights[i]*(NSR[i]-NSL[i]-1);
            maxArea=max(area,maxArea);
        }
        return maxArea;
    }
};