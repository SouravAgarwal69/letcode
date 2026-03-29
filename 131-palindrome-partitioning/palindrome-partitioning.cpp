class Solution {
public:
     bool isPallindrome(string temp)
     {
        int s=0,e=temp.size()-1;
        while(s<=e)
        {
            if(temp[s]==temp[e])
            {
                s++;
                e--;
            }
            else{
                return false;
            }
        }
        return true;
     }
    void find(string &s,vector<vector<string>>&ans,int index,vector<string>&temp)
    {
        if(index>=s.size())
        {
            ans.push_back(temp);
            return;
        }
        for(int part=1;part<=s.size();part++)
        {
            if(index+part>s.size())
            {
                return;
            }
            string ptr=s.substr(index,part);
            if(isPallindrome(ptr))
            {
            temp.push_back(ptr);
            find(s,ans,index+part,temp);
            temp.pop_back();
            }
        }
    }
    vector<vector<string>> partition(string s) {
        vector<vector<string>>ans;
        vector<string>temp;
       find(s,ans,0,temp);
       return ans;
    }
};