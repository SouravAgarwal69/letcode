class Solution {
public:
    vector<int> survivedRobotsHealths(vector<int>& positions, vector<int>& healths, string directions) {
        vector<int>result;
        vector<int>index(positions.size());
        iota(index.begin(),index.end(),0);
        sort(index.begin(),index.end(),[&](int i,int j)
        {
            return positions[i]<positions[j];
        });
        stack<int>st;
        for(int i=0;i<index.size();i++)
        {
            bool collision=false;
            while(!st.empty() && directions[st.top()]=='R' && directions[index[i]]=='L')
            {
                if(healths[st.top()]==healths[index[i]])
                {
                    
                    healths[st.top()]=0;
                    healths[index[i]]=0;
                    st.pop();
                    collision=true;
                    break;
                }
                else if(healths[st.top()]>healths[index[i]])
                {
                    collision=true;
                    healths[index[i]]=0;
                    healths[st.top()]-=1;
                    break;
                }
                else
                {
                    healths[st.top()]=0;
                    healths[index[i]]-=1;
                      st.pop();
                }
            }
            if(!collision)
            {
                st.push(index[i]);
            }
        }
        for(int i=0;i<healths.size();i++)
        {
            if(healths[i]==0)
            {
                continue;
            }
            result.push_back(healths[i]);
        }
        return result;
    }
};