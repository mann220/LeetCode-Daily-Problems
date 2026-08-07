class Solution {
public:
    int findUnsortedSubarray(vector<int>& nums) {
        int n=nums.size();
        vector<int> v=nums;
        sort(v.begin(),v.end());
        int l=-1;
        int r=-1;
        for(int i=0;i<n;i++){
            if(nums[i]!=v[i]){
                l=i;
                break;
            }
        }
        for(int i=n-1;i>=0;i--){
            if(nums[i]!=v[i]){
                r=i;
                break;
            }
        }
        if(l==-1) return 0;
        return r-l+1;
    }
};