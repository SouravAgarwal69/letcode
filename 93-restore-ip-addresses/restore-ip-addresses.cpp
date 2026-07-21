class Solution {
public:
    bool valid(string segment)
    {
        int val=stoi(segment);
        if(segment.size()>1 && segment[0]=='0')
        {
            return false;
        }
        return val<=255;
    }
    void fun(string &s,vector<string>&result,string temp,int index,int parts)
    {
        if(index==s.size() && parts==4)
        {
            temp.pop_back();
            result.push_back(temp);
            return;
        }
        for(int len=1;len<=3;len++)
        {
            if(index+len>s.size())
            {
                break;
            }
            string segment=s.substr(index,len);
            if(valid(segment))
            {
                fun(s,result,temp+segment+".",index+len,parts+1);
            }
        }
    }
    vector<string> restoreIpAddresses(string s) {
        vector<string>result;
        string temp;
        fun(s,result,temp,0,0);
        return result;
    }
};