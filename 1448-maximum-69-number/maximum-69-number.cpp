class Solution {
public:
    int maximum69Number (int num) {
        string temp=to_string(num);
        for(int i=0;i<temp.size();i++)
        {
            if(temp[i]=='6')
            {
                temp[i]='9';
                return stoi(temp);
            }
        }
        return num;
    }
};