class Solution {
public:
    int minOperations(vector<int>& nums) {
        int n=nums.size();
        int cnt1=0,cnt2=0,ans=INT_MAX;
        int ind=-1;
        for(int i=0;i<nums.size();i++){
            if(nums[i]<nums[(i+1)%n]) cnt1++;
            else cnt2++;
            if(nums[i]==0) ind=i;
        }
        if(cnt1>1 && cnt2>1) return -1;
        if(cnt2<=1){                // the array is in ascending order
            ans=min(ans,ind);
            ans=min(ans,n-ind+2);
        }
        if(cnt1<=1){                // the array is in descending order
            ans=min(ans,ind+2);
            ans=min(ans,n-ind);
        }
        return ans;
    }
};