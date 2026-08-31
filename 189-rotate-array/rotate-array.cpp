class Solution {
public:
    void rotate(vector<int>& result, int k) {
        k=k%result.size();
        reverse(result.begin(),result.end());
        reverse(result.begin(),result.begin()+k);
        reverse(result.begin()+k,result.end());
    }
};