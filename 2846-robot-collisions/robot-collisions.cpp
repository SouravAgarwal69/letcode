class Solution {
public:
    vector<int> survivedRobotsHealths(vector<int>& positions, vector<int>& healths, string directions) {
        vector<int>indices(positions.size());
        iota(indices.begin(),indices.end(),0);
        sort(indices.begin(),indices.end(),[&](int i,int j){
            return positions[i]<positions[j];
        });
        vector<int>result;
        stack<int>st;
        for(int i=0;i<indices.size();i++)
        {
            bool collision=false;
            while(!st.empty() && directions[indices[i]]=='L' && directions[st.top()]=='R')
            {
                if(healths[indices[i]]==healths[st.top()])
                {
                    healths[indices[i]]=0;
                    healths[st.top()]=0;
                    st.pop();
                    collision=true;
                    break;
                }
                else if(healths[indices[i]]>healths[st.top()])
                {
                    healths[st.top()]=0;
                    healths[indices[i]]-=1;
                    st.pop();
                }
                else
                {
                    healths[indices[i]]=0;
                    healths[st.top()]-=1;
                    collision=true;
                    break;
                }
            }
            if(!collision)
            {
                st.push(indices[i]);
            }
        }
         for(int i=0;i<healths.size();i++)
         {
            if(healths[i]!=0)
            {
                result.push_back(healths[i]);
            }
         }
         return result;
    }
};