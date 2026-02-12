class Solution {
public:
    void findNSE(vector<int>&NSE,stack<int>st,vector<int>&arr)
    {
        for(int i=arr.size()-1;i>=0;i--)
        {
            while(!st.empty() && arr[i]<=arr[st.top()])
            {
                st.pop();
            }
            if(st.empty())
            {
                 NSE[i]=arr.size();
            }
            else
            {
                NSE[i]=st.top();
            }
            st.push(i);
        }
    }
    void findPSE(vector<int>&PSE,stack<int>st,vector<int>&arr)
    {
        for(int i=0;i<arr.size();i++)
        {
            while(!st.empty() && arr[i]<=arr[st.top()])
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
    int find(vector<int>&arr)
    {
        vector<int>NSE(arr.size());
        vector<int>PSE(arr.size());
        stack<int>st;
        int maxArea=0;
        findNSE(NSE,st,arr);
        findPSE(PSE,st,arr);
        for(int i=0;i<arr.size();i++)
        {
            int area=arr[i]*(NSE[i]-PSE[i]-1);
            maxArea=max(maxArea,area);
        }
        return maxArea;
    }
    int maximalRectangle(vector<vector<char>>& matrix) {
        int maximum=0;
        vector<int>heights(matrix[0].size());
        for(int i=0;i<matrix.size();i++)
        {
            for(int j=0;j<matrix[i].size();j++)
            {
                if(matrix[i][j]!='0')
                {
                    heights[j]+=1;
                }
                else
                {
                    heights[j]=0;
                }
            }
            maximum=max(maximum,find(heights));
        }
        return maximum;
    }
};