class Solution {
public:
    string simplifyPath(string path) {
        vector<string>vec;
        stringstream ss(path);
        string temp;
        while(getline(ss,temp,'/'))
        {
            if(temp=="." || temp=="")
            {
                continue;
            }
            else if(temp=="..")
            {
                if(!vec.empty())
                {
                    vec.pop_back();
                }
            }
            else
            {
               vec.push_back(temp);
            }
        }
        if(vec.empty())
        {
            return "/";
        }
        string result;
        for(int i=0;i<vec.size();i++)
        {
            result=result+"/"+vec[i];
        }
        return result;
    }
};