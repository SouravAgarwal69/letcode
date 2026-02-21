class Solution {
public:
    string removeKdigits(string num, int k) {
        string result;
        for(int i=0;i<num.size();i++)
        {
            while(!result.empty() && result.back()>num[i] && k>0)
            {
                result.pop_back();
                k--;
            }
            if(result.empty() && num[i]=='0')
            {
                continue;
            }
            result.push_back(num[i]);
        }
        while(k>0 && !result.empty())
        {
            result.pop_back();
            k--;
        }
        return result.empty()?"0":result;
    }
};