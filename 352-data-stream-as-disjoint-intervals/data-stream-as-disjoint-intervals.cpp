class SummaryRanges {
public:
    map<int,int>mp;
    SummaryRanges() {
        mp.clear();
    }
    
    void addNum(int value) {
        int left=value,right=value;
        auto it=mp.upper_bound(value);
        if(it!=mp.begin())
        {
            auto prev=it;
            --prev;
            if(prev->second >=value)
            {
                return;
            }
            if(prev->second+1==value)
            {
                left=prev->first;
                mp.erase(prev);
            }
        }
        if(it!=mp.end() && it->first==value+1)
        {
           right=it->second;
           mp.erase(it);
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