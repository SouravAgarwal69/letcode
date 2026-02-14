class Solution {
public:
    string countOfAtoms(string formula) {
        string result;
        stack<unordered_map<string,int>>st;
        st.push(unordered_map<string,int>());
        int i=0;
        while(i<formula.size())
        {
            if(formula[i]=='(')
            {
                st.push(unordered_map<string,int>());
                i++;
            }
            else if(formula[i]==')')
            {
                unordered_map<string,int>mp=st.top();
                st.pop();
                string digit;
                i++;
                while(i<formula.size() && isdigit(formula[i]))
                {
                    digit+=formula[i];
                    i++;
                }
                if(!digit.empty())
                {
                    int multiplier=stoi(digit);
                    for(auto it=mp.begin();it!=mp.end();it++)
                    {
                        it->second=(it->second)*multiplier;
                    }
                }
                for(auto it=mp.begin();it!=mp.end();it++)
                {
                    st.top()[it->first]+=it->second;
                }
            }
            else
            {
                string temp;
                temp+=formula[i];
                i++;
                while(i<formula.size() && islower(formula[i]))
                {
                    temp+=formula[i];
                    i++;
                }
                string digit;
                while(i<formula.size() && isdigit(formula[i]))
                {
                    digit+=formula[i];
                    i++;
                }
                int num=digit.empty()?1:stoi(digit);
                st.top()[temp]+=num;
            }
        }
        map<string,int>mp(st.top().begin(),st.top().end());
        for(auto it=mp.begin();it!=mp.end();it++)
        {
            result+=it->first;
            if(it->second>1)
            {
                result+=to_string(it->second);
            }
        }
        return result;
    }
};