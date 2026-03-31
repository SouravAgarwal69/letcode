class Solution {
public:
    bool isPallindrome(string temp,int s,int e)
    {
        if(s>=e)
        {
            return true;
        }
        if(temp[s]==temp[e])
        {
           return isPallindrome(temp,s+1,e-1);
        }
        return false;
    }
    void find(string &s,vector<vector<string>>&result,vector<string>&temp,int index)
    {
        if(index==s.size())
        {
            result.push_back(temp);
            return;
        }
        for(int part=1;part<=s.size();part++)
        {
            if(index+part>s.size())
            {
                break;
            }
            string var=s.substr(index,part);
            if(isPallindrome(var,0,var.size()-1))
            {
                temp.push_back(var);
                find(s,result,temp,index+part);
                temp.pop_back();
            }
        }
    }
    vector<vector<string>> partition(string s) {
        vector<vector<string>>result;
        vector<string>temp;
        find(s,result,temp,0);
        return result;
    }
};