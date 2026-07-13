class Solution {
public:
    string simplifyPath(string path) {
        vector<string>store;
        string temp;
        stringstream ss(path);
        while(getline(ss,temp,'/'))
        {
            if(temp=="." || temp=="")
            {
                continue;
            }
            else if(temp=="..")
            {
                if(!store.empty())
                {
                    store.pop_back();
                }
            }
            else
            {
                store.push_back(temp);
            }
        }
        if(store.empty())
        {
            return "/";
        }
        string result;
        for(int i=0;i<store.size();i++)
        {
            result=result+"/"+store[i];
        }
        return result;
    }
};