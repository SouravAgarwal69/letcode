class Solution {
public:
    string simplifyPath(string path) {
        vector<string>temp;
        stringstream ss(path);
        string token;
        while(getline(ss,token,'/'))
        {
            temp.push_back(token);
        }
        vector<string>result;
        for(int i=0;i<temp.size();i++)
        {
            if(temp[i]=="" || temp[i]=="." )
            {
                continue;
            }
            else if( temp[i]=="..")
            {
                if(!result.empty())
                {
                result.pop_back();
                }
            }
            else
            {
               result.push_back(temp[i]);
            }
        }
        if(result.empty())
        {
            return "/";
        }
        string ans;
        for(int i=0;i<result.size();i++)
        {
           ans+="/"+result[i];
        }
        return ans;
    }
};