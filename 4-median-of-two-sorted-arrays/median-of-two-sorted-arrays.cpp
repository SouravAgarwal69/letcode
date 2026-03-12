class Solution {
public:
    double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
        if(nums1.size()>nums2.size())
        {
            swap(nums1,nums2);
        }
        int s=0,e=nums1.size(),size=nums1.size()+nums2.size();
        while(s<=e)
        {
            int p1=s+(e-s)/2;
            int p2=((size+1)/2)-p1;
            double x1=p1==0?INT_MIN:nums1[p1-1];
            double x2=p1==nums1.size()?INT_MAX:nums1[p1];
            double y1=p2==0?INT_MIN:nums2[p2-1];
            double y2=p2==nums2.size()?INT_MAX:nums2[p2];
            if(x1<=y2 && y1<=x2)
            {
                if(size%2==0)
                {
                    return (max(x1,y1)+min(x2,y2))/2.0;
                }
                return max(x1,y1);
            }
            else if(x1>y2)
            {
                e=p1-1;
            }
            else{
                s=p1+1;
            }
        }
        return -1;
    }
};