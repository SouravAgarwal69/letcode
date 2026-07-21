class Solution {
public:
    bool isConcatenated(string words,unordered_map<string,bool>&mp,unordered_set<string>&st,vector<string>&result)
    {
         if(mp.find(words)!=mp.end())
         {
            return mp[words];
         }
         for(int i=0;i<words.size();i++)
         {
            string prefix=words.substr(0,i+1);
            string suffix=words.substr(i+1);
            if((st.find(prefix)!=st.end() && st.find(suffix)!=st.end()) || (st.find(prefix)!=st.end() && isConcatenated(suffix,mp,st,result)))
            {
                mp[words]=true;
                return true;
            }
         }
         mp[words]=false;
         return false;
    }
    vector<string> findAllConcatenatedWordsInADict(vector<string>& words) {
        vector<string>result;
        unordered_set<string>st(words.begin(),words.end());
        unordered_map<string,bool>mp;
        for(int i=0;i<words.size();i++)
       {
             if(isConcatenated(words[i],mp,st,result))
             {
                result.push_back(words[i]);
             }
       }
       return result;
    }
};   