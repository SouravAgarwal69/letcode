class Solution {
public:
    vector<int> survivedRobotsHealths(vector<int>& positions, vector<int>& healths, string directions) {
        vector<int>result;
        vector<int>index(positions.size());
        iota(index.begin(),index.end(),0);
        sort(index.begin(),index.end(),[&](int i,int j){
            return positions[i]<positions[j];
        }
        );
        stack<int>st;
        for(int i=0;i<index.size();i++)
        {
            bool collision=false;
            while(!st.empty() && directions[st.top()]=='R' && directions[index[i]]=='L')
            {
                if(healths[index[i]]==healths[st.top()])
                {
                    healths[index[i]]=0;
                    healths[st.top()]=0;
                    st.pop();
                    collision=true;
                    break;
                }
                else if(healths[index[i]]>healths[st.top()])
                {
                    healths[index[i]]-=1;
                    healths[st.top()]=0;
                    st.pop();
                }
                else if(healths[index[i]]<healths[st.top()])
                {
                    healths[index[i]]=0;
                    healths[st.top()]-=1;
                    collision=true;
                    break;
                }
            }
            if(!collision)
                {
                    st.push(index[i]);
                }
        }
        for(int i=0;i<positions.size();i++)
        {
            if(healths[i]!=0)
            {
                result.push_back(healths[i]);
            }
        }
        return result;
    }
};