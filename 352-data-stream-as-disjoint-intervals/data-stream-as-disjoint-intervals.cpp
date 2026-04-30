class SummaryRanges {
public:
    unordered_set<int>st;
    SummaryRanges() {
        st.clear();
    }
    
    void addNum(int value) {
        st.insert(value);
    }
    
    vector<vector<int>> getIntervals() {
        vector<vector<int>>res;
       vector<int>temp(st.begin(),st.end());
       sort(temp.begin(),temp.end());
       int i=0,n=temp.size();
      while(i<temp.size())
       {
          int left=temp[i];
          while(i<n-1 && temp[i]+1==temp[i+1])
          {
             i++;
          }
          int right=temp[i];
          res.push_back({left,right});
          i++;
       }
       return res;
    }
    
};

/**
 * Your SummaryRanges object will be instantiated and called as such:
 * SummaryRanges* obj = new SummaryRanges();
 * obj->addNum(value);
 * vector<vector<int>> param_2 = obj->getIntervals();
 */