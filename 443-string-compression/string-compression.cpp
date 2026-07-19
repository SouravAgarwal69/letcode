class Solution {
public:
    int compress(vector<char>& chars) {
        int i=0,index=0;
        while(i<chars.size())
        {
            int cnt=1,j=i+1;
            while(j<chars.size() && chars[i]==chars[j])
            {
                cnt++;
                j++;
            }
           chars[index++]=chars[i];
           if(cnt>1)
           {
            string temp=to_string(cnt);
            for(int i=0;i<temp.size();i++)
            {
              chars[index++]=temp[i];
            }
           }
           i=j;
        }
        return index;
    }
};