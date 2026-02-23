class Solution {
public:
    int candy(vector<int>& ratings) {
        vector<int>temp(ratings.size(),1);
        for(int i=0;i<ratings.size()-1;i++)
        {
             if(ratings[i]<ratings[i+1])
             {
                temp[i+1]=max(temp[i]+1,temp[i+1]);
             }
        }
        for(int i=ratings.size()-2;i>=0;i--)
        {
            if(ratings[i+1]<ratings[i])
            {
                temp[i]=max(temp[i+1]+1,temp[i]);
            }
        }
        int totalCandy=0;
        for(int i=0;i<temp.size();i++)
        {
            totalCandy+=temp[i];
        }
        return totalCandy;
    }
};