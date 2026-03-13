/**
 * // This is the MountainArray's API interface.
 * // You should not implement it, or speculate about its implementation
 * class MountainArray {
 *   public:
 *     int get(int index);
 *     int length();
 * };
 */

class Solution {
public:
    int findPivot(MountainArray &mountainArr)
    {
        int s=0,e=mountainArr.length()-1;
        while(s<e)
        {
            int mid=s+(e-s)/2;
            if(mountainArr.get(mid)<mountainArr.get(mid+1))
            {
                s=mid+1;
            }
            else
            {
                e=mid;
            }
        }
        return s;
    }
    int BS(int s,int e,MountainArray &mountainArr,int target)
    {
           while(s<=e)
           {
             int mid=s+(e-s)/2;
             if(mountainArr.get(mid)==target)
             {
                return mid;
             }
             else if(mountainArr.get(mid)>target)
             {
                e=mid-1;
             }
             else
             {
                 s=mid+1;
             }
           }
           return -1;
    }
    int BS1(int s,int e,int target, MountainArray &mountainArr)
    {
        while(s<=e)
        {
            int mid=s+(e-s)/2;
            if(mountainArr.get(mid)==target)
            {
                return mid;
            }
            else if(mountainArr.get(mid)>target)
            {
                s=mid+1;
            }
            else
            {
                e=mid-1;
            }
        }
        return -1;
    }
    int findInMountainArray(int target, MountainArray &mountainArr) {
        int pivot=findPivot(mountainArr);
        if(BS(0,pivot-1,mountainArr,target)!=-1)
        {
            return BS(0,pivot-1,mountainArr,target);
        }
        return BS1(pivot,mountainArr.length()-1,target,mountainArr);
    }
};