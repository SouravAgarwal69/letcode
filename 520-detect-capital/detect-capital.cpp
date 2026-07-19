class Solution {
public:
    bool checkCapital(string word)
    {
         for(int i=0;i<word.size();i++)
         {
            if(word[i]<65 || word[i]>90)
            {
                return false;
            }
         }
         return true;
    }
    bool checkSmall(string word)
    {
        word[0]=tolower(word[0]);
        for(int i=0;i<word.size();i++)
        {
            if(word[i]<97 || word[i]>122)
            {
                return false;
            }
        }
        return true;
    }
    bool detectCapitalUse(string word) {
        return checkCapital(word) || checkSmall(word);
    }
};