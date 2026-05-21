class Solution {
public:
    string simplifyPath(string path) {
       vector<string>store;
       stringstream ss(path);
       string result;
       string temp;
       while(getline(ss,temp,'/'))
       {
           if(temp=="." || temp=="")
           {
             continue;
           }
           if(temp=="..")
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
     for(int i=0;i<store.size();i++)
     {
         result=result+"/"+store[i];
     }
      return result;
    }
};