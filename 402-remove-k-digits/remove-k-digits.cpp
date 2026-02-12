class Solution {
public:
    string removeKdigits(string num, int k) {
        string ans;
        for(int i=0;i<num.size();i++)
        {
            while(!ans.empty() && ans.back()-'0'>num[i]-'0' && k>0)
            {
                 ans.pop_back();
                 k--;
            }
            if(ans.empty() && num[i]=='0')
            {
                continue;
            }
           ans.push_back(num[i]);
        }
        while(k>0 && !ans.empty())
        {
            ans.pop_back();
            k--;
        }
        return ans.empty()?"0":ans;
    }
};