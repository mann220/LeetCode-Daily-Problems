class Solution {
public:
    int triangleNumber(vector<int>& nums) {
        int n=nums.size();
        sort(nums.begin(),nums.end());
        int cnt=0;
        for(int i=0;i<n-2;i++){
            for(int j=i+1;j<n-1;j++){
                int val=nums[i]+nums[j];
                int lb=lower_bound(nums.begin()+j+1,nums.end(),val)-nums.begin();
                // cout<<val<<" "<<lb<<endl;
                cnt+=(lb-1-j);
            }
        }
        return cnt;
    }
};