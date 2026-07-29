class Solution {
public:
    bool isVowel(char ch)
    {
         char ch1=tolower(ch);
          return ch1=='a' || ch1=='e' || ch1=='i' || ch1=='o' || ch1=='u';
    }
    string reverseVowels(string s) {
        int st=0,e=s.size()-1;
        while(st<e)
        {
           if(isVowel(s[st]) && isVowel(s[e]))
           {
                swap(s[st],s[e]);
                st++;
                e--;
           }
            if(!isVowel(s[st]))
           {
              st++;
           }
            if(!isVowel(s[e]))
           {
             e--;
           }
        }
       return s;
    }
};