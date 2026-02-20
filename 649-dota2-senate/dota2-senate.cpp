class Solution {
public:
    void remove(string senate,vector<bool>&visited,char ch,int index)
    {
        while(true)
        {
            if(!visited[index] && senate[index]==ch)
            {
            visited[index]=true;
             break;
            }
            index=(index+1)%senate.size();
        }
    }
    string predictPartyVictory(string senate) {
        int totalR=0,totalD=0;
        for(int i=0;i<senate.size();i++)
        {
            if(senate[i]=='D')
            {
                totalD++;
            }
            else
            {
                totalR++;
            }
        }
        vector<bool>visited(senate.size(),0);
        int index=0;
        while(totalR>0 && totalD>0)
        {
            if(!visited[index])
            {
            if(senate[index]=='D')
            {
                remove(senate,visited,'R',(index+1)%senate.size());
                totalR--;
            }
            else
            {
                remove(senate,visited,'D',(index+1)%senate.size());
                totalD--;
            }
            }
            index=(index+1)%senate.size();
        }
        return totalR==0?"Dire":"Radiant";
    }
};