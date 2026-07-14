class Solution {
public:
    vector<int> minOperations(string boxes) {
        int n=boxes.size();
        vector<int>result(n);
        int cumSum=0,cnt=0;
        for(int i=0;i<boxes.size();i++)
        {
            result[i]=cumSum;
            if(boxes[i]=='1')
            {
                cnt++;
            }
            cumSum+=cnt;
        }
        cumSum=0,cnt=0;
        for(int i=n-1;i>=0;i--)
        {
            result[i]+=cumSum;
            if(boxes[i]=='1')
            {
                cnt++;
            }
            cumSum+=cnt;
        }
        return result;
    }
};