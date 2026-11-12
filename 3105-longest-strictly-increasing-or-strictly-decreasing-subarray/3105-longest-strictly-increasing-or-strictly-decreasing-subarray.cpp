class Solution {
public:
    int longestMonotonicSubarray(vector<int>& nums) {
        int cnt1=1;
        int cnt2=1;
        int ans=1;
        for(int i=0;i<nums.size()-1;i++){
            if(nums[i]<nums[i+1]){
                cnt1++;
                cnt2=1;
            }
            else if(nums[i]>nums[i+1]){
                cnt2++;
                cnt1=1;
            }
            else{
                cnt1=1;
                cnt2=1;
            }
            ans=max({ans,cnt1,cnt2});
        }
        return ans;
    }
};