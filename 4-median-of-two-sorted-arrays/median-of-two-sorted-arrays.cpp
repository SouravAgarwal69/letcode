class Solution {
public:
    double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
        int element1=-1,element2=-1;
        int size=nums1.size()+nums2.size();
        int i=0,j=0,k=0,index1=(size-1)/2,index2=size/2;
        while(i<nums1.size() && j<nums2.size())
        {
            if(nums1[i]<nums2[j])
            {
               
                 if(k==index1)
            {
                element1=nums1[i];
            }
            if(k==index2)
            {
                element2=nums1[i];
            }
             i++;
             k++;
            }
            else
            {
               
                 if(k==index1)
            {
                element1=nums2[j];
            }
            if(k==index2)
            {
                element2=nums2[j];
            }
             j++;
                k++;
            }
        }
        while(i<nums1.size())
        {
           
            if(k==index1)
            {
                element1=nums1[i];
            }
            if(k==index2)
            {
                element2=nums1[i];
            }
             i++;
            k++;
        }
        while(j<nums2.size())
        {
             if(k==index1)
            {
                element1=nums2[j];
            }
            if(k==index2)
            {
                element2=nums2[j];
            }
             j++;
            k++;
        }
        if((nums1.size()+nums2.size())%2==0)
        {
            return (element1+element2)/2.0;
        }
        return element1;
    }
};