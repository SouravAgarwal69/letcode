class Solution {
public:
    int candy(vector<int>& ratings) {
        int candies=ratings.size();
        int i=1;
     while(i<ratings.size())
        {
            if(ratings[i]==ratings[i-1])
            {
                i++;
                continue;
            }
            int peak=0,dip=0;
            while(ratings[i]>ratings[i-1])
            {
                peak++;
                candies+=peak;
                 i++;
                if(i==ratings.size())
                {
                    return candies;
                }
            }
            while(i<ratings.size() && ratings[i]<ratings[i-1])
            {
                dip++;
                candies+=dip;
                i++;
            }
            candies-=min(peak,dip);
        }
        return candies;
    }
};