class Solution {
public:
    string intToRoman(int num) {
      vector<pair<string,int>>symbol={{"M",1000},{"CM",900},{"D",500},{"CD",400},{"C",100},{"XC",90},{"L",50},{"XL",40},{"X",10},{"IX",9},{"V",5},{"IV",4},{"I",1}};
         string result;
         for(int i=0;i<symbol.size();i++)
         {
            int val=symbol[i].second;
            string roman=symbol[i].first;
            int cnt=num/val;
            while(cnt>0)
            {
                result+=roman;
                cnt--;
            }
            num=num%val;
            if(num==0)
            {
                break;
            }
         }
         return result;
    }
};