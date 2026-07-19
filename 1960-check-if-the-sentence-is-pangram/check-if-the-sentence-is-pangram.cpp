class Solution {
public:
    bool checkIfPangram(string sentence) {
        vector<int>symbol(26);
        for(int i=0;i<sentence.size();i++)
        {
            symbol[sentence[i]-'a']++;
        }
        for(int i=0;i<26;i++)
        {
            if(symbol[i]==0)
            {
                return false;
            }
        }
           return true;
    }
};