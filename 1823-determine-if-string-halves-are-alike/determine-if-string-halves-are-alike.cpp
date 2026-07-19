class Solution {
public:
    bool isVowel(char ch)
    {
        char c=tolower(ch);
        return c=='a' || c=='e' || c=='i' || c=='o' || c=='u';
    }
    bool halvesAreAlike(string s) {
        int i=0,j=s.size()/2,cntA=0,cntB=0;
        while(i<s.size()/2)
        {
            if(isVowel(s[i]))
            {
                cntA++;
            }
            i++;
        }
        while(j<s.size())
        {
            if(isVowel(s[j]))
            {
                cntB++;
            }
            j++;
        }
        return cntA==cntB;
    }
};