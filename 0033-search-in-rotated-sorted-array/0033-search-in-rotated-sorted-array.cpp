class Solution {
public:
    int bs(int lo,int hi,int target,vector<int>& nums){
        while(lo<=hi){
            int mid=lo+(hi-lo)/2;
            if(nums[mid]==target) return mid;
            else if(nums[mid]<target) lo=mid+1;
            else hi=mid-1;
        }
        return -1;
    }
    int search(vector<int>& nums, int target) {
        int n=nums.size();
        int lo=0;
        int hi=n-1;
        while(lo<=hi){
            int mid=lo+(hi-lo)/2;
            if(nums[lo]<=nums[mid]){    // this is sorted half
                if(nums[lo]<=target && target<=nums[mid]) return bs(lo,mid,target,nums);
                else lo=mid+1;
            }
            else{       // else this is sorted half
                if(nums[mid]<=target && target<=nums[hi]) return bs(mid,hi,target,nums);
                else hi=mid-1;
            }
        }
        return -1;
    }
};