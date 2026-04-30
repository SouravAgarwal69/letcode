class SummaryRanges {
public:
    map<int,int>mp;
    SummaryRanges() {
        mp.clear();
    }
    
    void addNum(int value) {
        int left=value,right=value;
        auto just_greater=mp.upper_bound(value);
        if(just_greater!=mp.begin())
        {
            auto prev1=prev(just_greater);
            if(value<=prev1->second)
            {
                return;
            }
            if(prev1->second+1==value)
            {
                left=prev1->first;
                mp.erase(prev1);
            }
        }
        if(just_greater!=mp.end() && just_greater->first==value+1)
        {
           right=just_greater->second;
           mp.erase(just_greater);
        }
         mp[left]=right;
    }
    
    vector<vector<int>> getIntervals() {
        vector<vector<int>>result;
        for(auto it=mp.begin();it!=mp.end();it++)
        {
            result.push_back({it->first,it->second});
        }
        return result;
    }
};

/**
 * Your SummaryRanges object will be instantiated and called as such:
 * SummaryRanges* obj = new SummaryRanges();
 * obj->addNum(value);
 * vector<vector<int>> param_2 = obj->getIntervals();
 */