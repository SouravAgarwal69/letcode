class Solution {
public:
    int longestPalindrome(vector<string>& words) {
        int length=0;
        unordered_map<string,int>mp;
        for(int i=0;i<words.size();i++)
        {
            mp[words[i]]++;
        }
        bool centered=false;
        for(int i=0;i<words.size();i++)
        {
            string rev=words[i];
            reverse(rev.begin(),rev.end());
            if(words[i]==rev)
            {
                 if(mp[words[i]]>=2)
                 {
                    length+=4;
                    mp[words[i]]-=2;
                 }
                 else if(mp[words[i]]==1 && !centered)
                 {
                    length+=2;
                    mp[words[i]]--;
                    centered=true;
                 }
            }
            else if(mp[words[i]]>0 && mp[rev]>0)
            {
                 length+=4;
                 mp[words[i]]--;
                 mp[rev]--;
            }
        }
        return length;
    }
};